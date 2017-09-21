#ifndef GL_RENDER_H
#define GL_RENDER_H

#include <glad/glad.h>
#include "drawing/render/renderer.h"

class IContext;
class ShaderProgram;
class Camera;
class GLRenderer: public IRenderer {
public:
  GLRenderer(IContext* context);
  ~GLRenderer();

  void Draw() override;
  void Resize(int width, int height) override;

  Camera* camera() { return camera_; }
  GLfloat mix_val() { return mix_val_; }
  void set_mix_val(GLfloat val);

protected:
  void InitGL();

  ShaderProgram* program_;
  Camera* camera_;
  GLuint vao_;
  GLuint texture0_;
  GLuint texture1_;

  GLfloat mix_val_;
};

#endif // GL_RENDER_H
