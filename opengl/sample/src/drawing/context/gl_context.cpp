#include "drawing/context/gl_context.h"

#include <glad/glad.h>
#include <wx/glcanvas.h>

GLContext::GLContext(wxGLCanvas* canvas) : canvas_(canvas) {
  wxGLContextAttrs context_attrs;
  context_attrs.PlatformDefaults().CoreProfile().OGLVersion(3, 2).EndList();
  context_ = new wxGLContext(canvas_, NULL, &context_attrs);
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
