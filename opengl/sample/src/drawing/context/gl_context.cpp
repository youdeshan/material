#include "drawing/context/gl_context.h"

#include <glad/glad.h>
#include <wx/glcanvas.h>
#include <wx/msgdlg.h>

GLContext::GLContext(wxGLCanvas* canvas) : canvas_(canvas) {
  wxGLContextAttrs context_attrs;
  context_attrs.PlatformDefaults().OGLVersion(99, 2).EndList();
  context_ = new wxGLContext(canvas_, NULL, &context_attrs);
  if (!context_->IsOK()) {
#if wxUSE_LOGWINDOW
      wxLogMessage("Trying to set opengl 99.2 failed, as expected.");
#endif
      delete context_;
      context_attrs.Reset();
      context_attrs.PlatformDefaults().CoreProfile().OGLVersion(3, 3).EndList();
      context_ = new wxGLContext(canvas_, NULL, &context_attrs);
  }

  if (!context_->IsOK()) {
      wxMessageBox("This program needs an opengl 3.3 capable driver.\nThe app will exit now.", "Opengl version error ", wxOK | wxICON_INFORMATION, canvas_);
      delete context_;
      context_ = NULL;
  } else {
#if wxUSE_LOGWINDOW
      wxLogMessage("Opengl core profile 3.3 successfully set.");
#endif
  }
}

GLContext::~GLContext() {
  if (context_) {
    canvas_->SetCurrent(*context_);
  }
  if (context_) {
    delete context_;
    context_ = NULL;
  }
}

void GLContext::SetCurrent() {
  canvas_->SetCurrent(*context_);
}
