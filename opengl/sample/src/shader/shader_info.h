#ifndef SHADER_INFO_H_
#define SHADER_INFO_H_

#include "glad/glad.h"

typedef struct S_Info {
  GLenum type_;
  const char* file_name_;
  GLuint shader_;
} ShaderInfo;

#endif // SHADER_INFO_H_
