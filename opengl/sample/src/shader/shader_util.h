#ifndef SHADER_UTIL_H_
#define SHADER_UTIL_H_

#include <glad/glad.h>

struct S_Info;
typedef struct S_Info ShaderInfo;
GLuint LoadShaders(ShaderInfo* shaders);

#endif //SHADER_UTIL_H_
