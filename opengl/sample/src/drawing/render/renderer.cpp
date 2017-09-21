#include "drawing/render/renderer.h"

#include "glad/glad.h"
#include "drawing/context/context.h"

IRenderer::IRenderer(IContext* context) : context_(context) {
}

IRenderer::~IRenderer() {
  if (context_) delete context_;
  context_ = nullptr;
}
