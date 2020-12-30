#ifndef GL_CANVAS_H
#define GL_CANVAS_H

#include <wx/glcanvas.h>

class GLRenderer;
class Graph;
class GLCanvas : public wxGLCanvas {
  DECLARE_EVENT_TABLE()

public:
  GLCanvas(wxWindow* parent, const wxGLAttributes& canvas_attrs);
  virtual ~GLCanvas();

protected:
  void OnPaint(wxPaintEvent& event);
  void OnSize(wxSizeEvent& event);
  void OnChar(wxKeyEvent& event);
  void OnMouseLeftDown(wxMouseEvent& event);
  void OnMouseLeftUp(wxMouseEvent& event);
  void OnMouseMotion(wxMouseEvent& event);
  void OnMouseWheel(wxMouseEvent& event);

  void Init();

  GLRenderer* renderer_;
  Graph* scene_graph_;
  int win_height_;

  bool mouse_down_;
  int pos_down_[2];
};

#endif // GL_CANVAS_H
