#ifndef GRAPH_H
#define GRAPH_H

#include "drawing/scene/node.h"

class Graph : public INode{
public:
  Graph();
  ~Graph();

  void Render(IRenderer* renderer) override;
};

#endif // GRAPH_H
