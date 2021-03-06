#pragma once

#include <MFCUtil/AbstractMouseHandler.h>
#include "PolygonSet.h"

class DrawTool : public AbstractMouseHandler {
private:
  CBrush m_blackBrush, m_redBrush;
  TCHAR  m_infostr[400];

protected:
  ProfileEditor         &m_editor;
  PolygonSet             m_polygonSet;
  CompactArray<Point2D*> m_selectedPoints;
  ProfileEditorState     m_state;

  DrawTool &drawState();
  DrawTool &paintBox(            const Point2D        &p, bool selected);
  DrawTool &paintPoints(         const ProfilePolygon2D &p, bool selected);
  DrawTool &repaintPolygon(      const ProfilePolygon2D &p, bool selected);
  DrawTool &selectPolygonsInRect(const Rectangle2D    &r);
  DrawTool &selectPointsInRect(  const Rectangle2D    &r);
  DrawTool &select(                    ProfilePolygon2D *p);
  DrawTool &select(                    Point2D          *p);
  DrawTool &unselect(                  ProfilePolygon2D *p);
  DrawTool &unselect(                  Point2D          *p);
  bool isSelected(                     ProfilePolygon2D *p) const;
  bool isSelected(               const Point2D          *p) const;
public:
  DrawTool(ProfileEditor *editor);
  virtual ~DrawTool();
  bool OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
  bool canConnect() const;
  DrawTool &connect();
  bool canInvertNormals() const;
  DrawTool &invertNormals();
  bool canMirror() const;
  DrawTool &mirror(bool horizontal);
  bool canDelete();
  DrawTool &deleteSelected();
  bool canCopy();
  DrawTool &copySelected();
  bool canCut();
  DrawTool &cutSelected();
  DrawTool &paste();
  void initState() { m_state = IDLE; }
  DrawTool &unselectAll();
  DrawTool &repaintProfile();
  DrawTool &repaintScreen();
  DrawTool &repaintAll();
};
