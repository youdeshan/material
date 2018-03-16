#include "drawing/scene/drawable.h"

#include "drawing/render/renderer.h"

Drawable::Drawable() {
}

Drawable::~Drawable() {
}

void Drawable::Render(IRenderer* renderer) {
  // Only test opengl drawing
  renderer->Draw();
}
