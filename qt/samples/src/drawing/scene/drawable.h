#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "drawing/scene/node.h"

class Drawable: public INode{
public:
  Drawable();
  ~Drawable();

  void Render(IRenderer* renderer) override;
};

#endif // DRAWABLE_H
