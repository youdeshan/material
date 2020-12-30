#include <glad/glad.h>

#include "app/gl_canvas.h"

#include <wx/dcclient.h>
#include "drawing/context/gl_context.h"
#include "drawing/render/gl_renderer.h"
#include "drawing/scene/graph.h"
#include "drawing/scene/drawable.h"
#include "camera/camera.h"

BEGIN_EVENT_TABLE(GLCanvas, wxGLCanvas)
EVT_PAINT(GLCanvas::OnPaint)
EVT_SIZE(GLCanvas::OnSize)
EVT_CHAR(GLCanvas::OnChar)
EVT_LEFT_DOWN(GLCanvas::OnMouseLeftDown)
EVT_LEFT_UP(GLCanvas::OnMouseLeftUp)
EVT_MOTION(GLCanvas::OnMouseMotion)
EVT_MOUSEWHEEL(GLCanvas::OnMouseWheel)
END_EVENT_TABLE()

GLCanvas::GLCanvas(wxWindow* parent, const wxGLAttributes& canvas_attrs)
  : wxGLCanvas(parent, canvas_attrs), renderer_(nullptr), scene_graph_(NULL), win_height_(0), mouse_down_(false) {
  //IContext* context = new GLContext(this); // Will be destroyed by renderer
}

GLCanvas::~GLCanvas() {
  if (renderer_) delete renderer_;
  renderer_ = nullptr;
  
  if (scene_graph_) delete scene_graph_;
  scene_graph_ = NULL;
}

void GLCanvas::Init() {
  IContext* context = new GLContext(this); // Will be destroyed by renderer
  renderer_ = new GLRenderer(context);
  renderer_->InitGL();

  scene_graph_ = new Graph();
  auto draw_node = new Drawable();
  scene_graph_->AddChild(draw_node);
}

void GLCanvas::OnPaint(wxPaintEvent& event) {
  // This is a dummy, to avoid an endless succession of paint messages.
  // OnPaint handlers must always create a wxPaintDC.
  wxPaintDC dc(this);

  // Avoid painting when we have not yet a size
  if (win_height_ < 1) return;

  if (scene_graph_)
    scene_graph_->Render(renderer_);

  SwapBuffers();
}

//Note:
// You may wonder why OpenGL initialization was not done at wxGLCanvas ctor.
// The reason is due to GTK+/X11 working asynchronously, we can't call
// SetCurrent() before the window is shown on screen (GTK+ doc's say that the
// window must be realized first).
// In wxGTK, window creation and sizing requires several size-events. At least
// one of them happens after GTK+ has notified the realization. We use this
// circumstance and do initialization then.
void GLCanvas::OnSize(wxSizeEvent& event) {
  event.Skip();

  // If this window is not fully initialized, dismiss this event
  if (!IsShownOnScreen())
    return;

  if (!renderer_) {
      Init();
      PostSizeEvent();
  }

  win_height_ = event.GetSize().y;
  renderer_->Resize(event.GetSize().x, event.GetSize().y);

  // Generate paint event without erasing the background.
  Refresh(false);
}

void GLCanvas::OnChar(wxKeyEvent& event) {
  wxChar uc = event.GetUnicodeKey();
  if (uc != WXK_NONE) {
    Camera::MoveDirection dir = Camera::kStatic;
    switch (uc) {
    case 'w':
      dir = Camera::kForward;
      break;
    case 's':
      dir = Camera::kBackward;
      break;
    case 'a':
      dir = Camera::kLeft;
      break;
    case 'd':
      dir = Camera::kRight;
      break;
    case 'r':
      renderer_->camera()->Reset();
      break;
    default:
      break;
    }
    if (dir != Camera::kStatic) {
      renderer_->camera()->ProcessKeyboard(dir);
    }
  } else {
    switch (event.GetKeyCode()) {
    case WXK_UP:
      renderer_->set_mix_val(renderer_->mix_val() + 0.001);
      break;
    case WXK_DOWN:
      renderer_->set_mix_val(renderer_->mix_val() - 0.001);
      break;
    default:
      break;
    }
  }
  Refresh(false);
  Update();
}

void GLCanvas::OnMouseLeftDown(wxMouseEvent& event) {
  mouse_down_ = true;
  pos_down_[0] = event.GetX();
  pos_down_[1] = GetSize().y - event.GetY();
}

void GLCanvas::OnMouseLeftUp(wxMouseEvent& event) {
  mouse_down_ = false;
}

void GLCanvas::OnMouseMotion(wxMouseEvent& event) {
  if (!mouse_down_) return;

  int pos_x = event.GetX();
  int pos_y = GetSize().y - event.GetY();

  GLfloat offset_x = pos_x - pos_down_[0];
  GLfloat offset_y = pos_y - pos_down_[1];
  pos_down_[0] = pos_x;
  pos_down_[1] = pos_y;
  renderer_->camera()->ProcessMouseMovement(offset_x, offset_y);

  Refresh(false);
  Update();
}

void GLCanvas::OnMouseWheel(wxMouseEvent& event) {
  int rotation = event.GetWheelRotation();
  renderer_->camera()->ProcessMouseScroll(rotation > 0 ? 1.0 : -1.0);

  Refresh(false);
  Update();
}
