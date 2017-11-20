#ifndef SHADER_PROGRAM_H_
#define SHADER_PROGRAM_H_

#include <string>
#include <glm/glm.hpp>

#include "glad/glad.h"

struct S_Info;
typedef struct S_Info ShaderInfo;
class ShaderProgram {
public:
  ShaderProgram(ShaderInfo* shader_info);
  GLuint id() { return id_; }

  void Use();
  void SetBool(const std::string& name, GLboolean value) const;
  void SetInt(const std::string& name, GLint value) const;
  void SetFloat(const std::string& name, GLfloat value) const;
  void SetMatrix(const std::string& name, const GLfloat* value) const;

  void setVec3(const std::string &name, const glm::vec3& value) const;
  void setVec3(const std::string &name, float x, float y, float z) const;

private:
  GLuint id_;
};
#endif // SHADER_PROGRAM_H_ 
