#include "pch.h"
#include <Math/Expression/Expression.h>
#include "ExpressionCompile.h"

DEFINECLASSNAME(Expression);

Expression::Expression(TrigonometricMode mode) {
  init(mode);
}

Expression::Expression(const Expression &src) : ParserTree(src) {
  init(src.getTrigonometricMode(), src.getReturnType(), src.getState(), src.getReduceIteration());
  buildSymbolTable();
  copyValues((ParserTree&)src);
  setMachineCode(src.isMachineCode());
}

Expression &Expression::operator=(const Expression &src) {
  if(&src == this) {
    return *this;
  }

  clear();
  ParserTree::operator=(src);
  setTrigonometricMode(src.getTrigonometricMode());

  buildSymbolTable();
  copyValues((ParserTree&)src);

  setMachineCode(    src.isMachineCode());
  setReduceIteration(src.getReduceIteration());
  setReturnType(     src.getReturnType());
  setState(          src.getState());

  return *this;
}

void Expression::init(TrigonometricMode    trigonometricMode
                     ,ExpressionReturnType returnType
                     ,ExpressionState      state
                     ,UINT                 reduceIteration)
{
  m_machineCode       = false;
  m_code              = NULL;
  m_listFile          = NULL;
  m_trigonometricMode = trigonometricMode; // this is init.  so don't call set-properties here
  m_returnType        = returnType;
  m_state             = state;
  m_reduceIteration   = reduceIteration;
}

void Expression::clear() {
  releaseAll();
  setReturnType(EXPR_NORETURNTYPE);
  setMachineCode(false);
  setState(EXPR_EMPTY);
  setReduceIteration(0);
}

void Expression::compile(const String &expr, bool machineCode, FILE *listFile) {
  parse(expr);
  if(!isOk()) {
    return;
  }
  setReturnType(findReturnType());
  try {
    if(machineCode && (listFile!=NULL)) {
      m_listFile = listFile;
      _ftprintf(m_listFile, _T("%s\n\n"), expr.cstr());
      _ftprintf(m_listFile, _T("%s\n\n"), variablesToString().cstr());
    }

    setMachineCode(machineCode);

    if(m_listFile) {
      _ftprintf(m_listFile, _T("----------------------------------------------------\n"));
      m_listFile = NULL;
    }
  } catch (...) {
    m_listFile = NULL;
    throw;
  }
}

void Expression::parse(const String &expr) {
  clear();
  setOk(true);
  LexStringStream    stream(expr);
  ExpressionLex      lex(&stream);
  ExpressionParser   parser(*this, &lex);
  lex.setParser(&parser);
  parser.parse();
  if(isOk()) {
    buildSymbolTable();
    setTreeForm(TREEFORM_STANDARD);
    setState(EXPR_COMPILED);
  }
}

ExpressionReturnType Expression::findReturnType() const {
  DEFINEMETHODNAME;
  const ExpressionNodeArray stmtList = getStatementList((ExpressionNode*)getRoot());
  switch(stmtList.last()->getSymbol()) {
  case RETURNREAL : return EXPR_RETURN_REAL;
  case RETURNBOOL : return EXPR_RETURN_BOOL;
  default         : throwUnknownSymbolException(method, stmtList.last());
                    return EXPR_RETURN_REAL;
  }
}

void Expression::setState(ExpressionState newState) {
  setProperty(EXPR_STATE, m_state, newState);
}

void Expression::setReduceIteration(UINT iteration) {
  setProperty(EXPR_REDUCEITERATION, m_reduceIteration, iteration);
}

void Expression::setReturnType(ExpressionReturnType returnType) {
  setProperty(EXPR_RETURNTYPE, m_returnType, returnType);
}

void Expression::setMachineCode(bool machinecode) {
  if(machinecode != isMachineCode()) {
    if(machinecode) {
      genMachineCode();
    } else {
      clearMachineCode();
    }
    setProperty(EXPR_MACHINECODE, m_machineCode, machinecode);
  }
}

void Expression::genMachineCode() {
  clearMachineCode();
  m_code  = CodeGenerator(this, getTrigonometricMode(),m_listFile).getCode();
}

void Expression::clearMachineCode() {
  MachineCode *mcode = (MachineCode*)m_code;
  SAFEDELETE(mcode);
}

Real Expression::fastEvaluateReal() {
  return ((MachineCode*)m_code)->evaluateReal();
}

bool Expression::fastEvaluateBool() {
  return ((MachineCode*)m_code)->evaluateBool();
}

void Expression::setTrigonometricMode(TrigonometricMode mode) {
  const TrigonometricMode oldMode = m_trigonometricMode;
  if(mode != oldMode) {
    m_trigonometricMode = mode;
    if(isMachineCode()) {
      genMachineCode();
    }
    notifyPropertyChanged(EXPR_TRIGONOMETRICMODE, &oldMode, &m_trigonometricMode);
  }
}

class MarkedNodeTransformer : public ExpressionNodeHandler {
private:
  CompactNodeHashMap<ExpressionNode*> m_nodeMap;
protected:
  Expression &m_expr;
public:
  MarkedNodeTransformer(Expression *expr) : m_expr(*expr) {
  }
  inline void putNodes(const ExpressionNode *from, ExpressionNode *to) {
    if(to != from) m_nodeMap.put(from, to);
  }
  Expression &transform();
};

Expression &MarkedNodeTransformer::transform() {
  m_expr.traverseTree(*this);
  if(m_nodeMap.isEmpty()) {
    return m_expr;
  }
  m_expr.substituteNodes(m_nodeMap);
  m_expr.pruneUnusedNodes();
  return m_expr;
}

class MarkedNodeExpander : public MarkedNodeTransformer {
public:
  MarkedNodeExpander(Expression *expr) : MarkedNodeTransformer(expr) {
  }
  bool handleNode(ExpressionNode *n, int level);
};

bool MarkedNodeExpander::handleNode(ExpressionNode *n, int level) {
  if(n->isMarked() && n->isExpandable()) {
    putNodes(n, n->expand());
  }
  return true;
}

class MarkedNodeMultiplier : public MarkedNodeTransformer {
public:
  MarkedNodeMultiplier(Expression *expr) : MarkedNodeTransformer(expr) {
  }
  bool handleNode(ExpressionNode *n, int level);
};

bool MarkedNodeMultiplier::handleNode(ExpressionNode *n, int level) {
  if(n->isMarked()) {
    putNodes(n, m_expr.multiplyParentheses(n));
  }
  return true;
}

Expression &Expression::expandMarkedNodes() {
  return MarkedNodeExpander(this).transform();
}

Expression &Expression::multiplyMarkedNodes() {
  return MarkedNodeMultiplier(this).transform();
}

String Expression::toString() const {
  const ExpressionNode *root = getRoot();
  return root ? root->toString() : EMPTYSTRING;
}

void Expression::print(const ExpressionNode *n, FILE *f) const {
  _ftprintf(f,_T("%s"), n->toString().cstr());
}

void Expression::print(FILE *f) const {
  _ftprintf(f,_T("%s"),toString().cstr());
}

String Expression::getDefaultListFileName() { // static
#ifdef _DEBUG
#define CONFSTR "Dbg"
#else
#define CONFSTR "Rel"
#endif // _DEBUG
#ifdef IS32BIT
#define PFSTR "x86"
#else // IS64BIT
#define PFSTR "x64"
#endif // IS64BIT
#ifdef LONGDOUBLE
#define REALSTR "TB"
#else
#define REALSTR "QW"
#endif // LONGDOUBLE
  return _T("c:\\temp\\ExprList\\expr" PFSTR CONFSTR REALSTR "lst");
}
