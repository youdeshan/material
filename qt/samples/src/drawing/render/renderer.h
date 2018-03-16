#ifndef IRENDERER_H
#define IRENDERER_H

class IRenderer  {
public:
  virtual ~IRenderer() {};

  virtual void Draw() = 0;
  virtual void Resize(int width, int height) = 0;

protected:
  IRenderer() {};

  int win_size_[2];
};

#endif // IRENDERER_H
