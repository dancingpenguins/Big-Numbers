#include "pch.h"
#include <Math/MathXML.h>
#include <MFCUtil/MFCXml.h>
#include <D3DGraphics/ParametricR2R3SurfaceParameters.h>
#include <D3DGraphics/D3XML.h>

void setValue(XMLDoc &doc, XMLNodePtr n, const ParametricR2R3SurfaceParameters     &v) {
  setValue(  doc,  n, _T("tinterval"         ), v.m_tInterval                      );
  setValue(  doc,  n, _T("sinterval"         ), v.m_sInterval                      );
  setValue(  doc,  n, _T("tstepcount"        ), v.m_tStepCount                     );
  setValue(  doc,  n, _T("sstepcount"        ), v.m_sStepCount                     );
  setValue(  doc,  n, _T("common"            ), (D3SurfaceCommonParameters&)v      );
}






void getValue(XMLDoc &doc, XMLNodePtr n, ParametricR2R3SurfaceParameters           &v) {
  getValue(  doc,  n, _T("tinterval"         ), v.m_tInterval                      );
  getValue(  doc,  n, _T("sinterval"         ), v.m_sInterval                      );
  getValue(  doc,  n, _T("tstepcount"        ), v.m_tStepCount                     );
  getValue(  doc,  n, _T("sstepcount"        ), v.m_sStepCount                     );
  getValue(  doc,  n, _T("common"            ), (D3SurfaceCommonParameters&)v      );
}
