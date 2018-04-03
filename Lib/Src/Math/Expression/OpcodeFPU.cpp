#include "pch.h"
#include "InstructionBuilder.h"

bool OpcodeFPUTransfer::isValidOperand(const InstructionOperand &op, bool throwOnError) const {
  switch(op.getType()) {
  case REGISTER     : return __super::isValidOperand(op,throwOnError);
  case MEMORYOPERAND:
    switch(op.getSize()) {
    case REGSIZE_DWORD: return m_dwordCode.isValidOperand(op,throwOnError);
    case REGSIZE_QWORD: return m_qwordCode.isValidOperand(op,throwOnError);
    case REGSIZE_TBYTE: return m_tbyteCode.isValidOperand(op,throwOnError);
    }
  }
  return __super::isValidOperand(op,throwOnError);
}

InstructionBase OpcodeFPUTransfer::operator()(const InstructionOperand &op) const {
  isValidOperand(op, true);
  if(op.getType() == MEMORYOPERAND) {
    switch(op.getSize()) {
    case REGSIZE_DWORD: return m_dwordCode(op);
    case REGSIZE_QWORD: return m_qwordCode(op);
    case REGSIZE_TBYTE: return m_tbyteCode(op);
    }
  }
  return __super::operator()(op);
}

InstructionBase OpcodeFPU2Reg::operator()(const InstructionOperand &op1, const InstructionOperand &op2) const {
  isValidOperandCombination(op1,op2,true);
  if(op2.isST0()) {
    return InstructionBuilder(*this).setRegisterOperand(op1.getRegister());
  } else if(op1.isST0()) {
    return InstructionBuilder(m_st0iCode).setRegisterOperand(op2.getRegister());
  }
  throwInvalidOperandCombination(op1,op2);
  return InstructionBuilder(*this);
}

bool OpcodeFPUArithm::isValidOperand(const InstructionOperand &op, bool throwOnError) const {
  if(op.getType() == MEMORYOPERAND) {
    switch(op.getSize()) {
    case REGSIZE_DWORD: return m_dwordCode.isValidOperand(op,throwOnError);
    case REGSIZE_QWORD: return m_qwordCode.isValidOperand(op,throwOnError);
    }
  }
  return __super::isValidOperand(op,throwOnError);
}

bool OpcodeFPUArithm::isValidOperandCombination(const InstructionOperand &op1, const InstructionOperand &op2, bool throwOnError) const {
  return m_2regCode.isValidOperandCombination(op1,op2,throwOnError);
}

InstructionBase OpcodeFPUArithm::operator()(const InstructionOperand &op) const {
  isValidOperand(op,true);
  if(op.getType() == MEMORYOPERAND) {
    switch(op.getSize()) {
    case REGSIZE_DWORD: return m_dwordCode(op);
    case REGSIZE_QWORD: return m_qwordCode(op);
    }
  }
  return __super::operator()(op);
}

InstructionBase OpcodeFPUArithm::operator()(const InstructionOperand &op1, const InstructionOperand &op2) const {
  return m_2regCode(op1,op2);
}
