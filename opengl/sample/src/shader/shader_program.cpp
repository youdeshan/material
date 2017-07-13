#include "shader/shader_program.h"

#include "shader/shader_util.h"

ShaderProgram::ShaderProgram(ShaderInfo* shader_info) {
  id_ = LoadShaders(shader_info);
}

void ShaderProgram::Use() {
  glUseProgram(id_);
}

void ShaderProgram::SetBool(const std::string &name, bool value) const {
  glUniform1i(glGetUniformLocation(id_, name.c_str()), (int)value);
}

void ShaderProgram::SetInt(const std::string &name, int value) const {
  glUniform1i(glGetUniformLocation(id_, name.c_str()), value);
}

void ShaderProgram::SetFloat(const std::string &name, float value) const {
  glUniform1f(glGetUniformLocation(id_, name.c_str()), value);
}