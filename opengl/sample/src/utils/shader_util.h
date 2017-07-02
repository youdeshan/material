#ifndef SHADER_UTIL_H_
#define SHADER_UTIL_H_
#include <string>

#include <glad/glad.h>

typedef struct {
  GLenum type_;
  const char* file_name_;
  GLuint shader_;
} ShaderInfo;

GLuint LoadShaders(ShaderInfo* shaders);


#endif //SHADER_UTIL_H_
