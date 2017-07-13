#ifndef SHADER_PROGRAM_H_
#define SHADER_PROGRAM_H_

#include <string>

#include "glad/glad.h"

struct S_Info;
typedef struct S_Info ShaderInfo;
class ShaderProgram {
public:
  ShaderProgram(ShaderInfo* shader_info);

  void Use();
  void SetBool(const std::string &name, bool value) const;
  void SetInt(const std::string &name, int value) const;
  void SetFloat(const std::string &name, float value) const;

private:
  GLuint id_;
};
#endif // SHADER_PROGRAM_H_ 
