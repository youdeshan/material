#ifndef INODE_H
#define INODE_H

#include <list>

class IRenderer;
class INode {
public:
  virtual ~INode() {
    for (auto child : children_) {
      delete child;
    }
    children_.clear();
  }

  virtual void AddChild(INode* node) {
    children_.push_back(node);
  }

  virtual void Render(IRenderer* renderer) = 0;

protected:
  INode() { children_.clear(); }

  std::list<INode*> children_;
};

#endif // INODE_H
