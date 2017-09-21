#include "drawing/scene/graph.h"

Graph::Graph() {
}

Graph::~Graph() {
  for (auto child : children_) {
    delete child;
  }
  children_.clear();
}

void Graph::Render(IRenderer* renderer) {
  for (auto child : children_) {
    child->Render(renderer);
  }
}
