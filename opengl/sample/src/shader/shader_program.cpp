#include "shader/shader_program.h"

#include "shader/shader_util.h"

ShaderProgram::ShaderProgram(ShaderInfo* shader_info) {
  id_ = LoadShaders(shader_info);
}

void ShaderProgram::Use() {
  glUseProgram(id_);
}

void ShaderProgram::SetBool(const std::string &name, GLboolean value) const {
  glUniform1i(glGetUniformLocation(id_, name.c_str()), (GLint)value);
}

void ShaderProgram::SetInt(const std::string &name, GLint value) const {
  glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}

void ShaderProgram::SetFloat(const std::string &name, GLfloat value) const {
  glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
}

void ShaderProgram::SetMatrix(const std::string& name, const GLfloat* value) const {
  glUniformMatrix4fv(glGetUniformLocation(id_, name.c_str()), 1, GL_FALSE, value);
}

void ShaderProgram::setVec3(const std::string &name, const glm::vec3& value) const {
  glUniform3fv(glGetUniformLocation(id_, name.c_str()), 1, &value[0]);
}

void ShaderProgram::setVec3(const std::string &name, float x, float y, float z) const {
  glUniform3f(glGetUniformLocation(id_, name.c_str()), x, y, z);
}
