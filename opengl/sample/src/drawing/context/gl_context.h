#ifndef GL_CONTEXT_H
#define GL_CONTEXT_H

#include "drawing/context/context.h"

class wxGLCanvas;
class wxGLContext;
class GLContext : public IContext {
public:
  GLContext(wxGLCanvas* canvas);
  ~GLContext();

  void SetCurrent() override;

protected:
  wxGLCanvas* canvas_;
  wxGLContext* context_;
};

#endif // GL_CONTEXT_H
