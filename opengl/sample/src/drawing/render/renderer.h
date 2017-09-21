#ifndef IRENDERER_H
#define IRENDERER_H

class IContext;
class IRenderer  {
public:
  virtual ~IRenderer();

  virtual void Draw() = 0;
  virtual void Resize(int width, int height) = 0;

protected:
  IRenderer(IContext* context);

  IContext* context_;
  int win_size_[2];
};

#endif // IRENDERER_H
