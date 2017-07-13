#include "shader/shader_util.h"

#include <fstream>
#include <iostream>

#include "shader/shader_info.h"

/*
static std::string ReadShader(const std::string& file_path) {
  std::ifstream ifs(file_path, std::ifstream::in);
  if (!ifs.good()) return "";

  return std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
}*/

static const GLchar* ReadShader(const char* file_name) {
#ifdef WIN32
  FILE* infile;
  fopen_s(&infile, file_name, "rb");
#else
  FILE* infile = fopen(file_name, "rb");
#endif

  if (!infile) {
#ifdef _DEBUG
    std::cerr << "Unable to open file '" << file_name << "'" << std::endl;
#endif
    return NULL;
  }
  fseek(infile, 0, SEEK_END);
  int len = ftell(infile);
  fseek(infile, 0, SEEK_SET);
  GLchar* source = new GLchar[len + 1];
  fread(source, 1, len, infile);
  fclose(infile);
  source[len] = 0;

  return const_cast<const GLchar*>(source);
}

GLuint LoadShaders(ShaderInfo* shaders) {
  if (shaders == NULL) return 0;

  GLuint program = glCreateProgram();
  ShaderInfo* entry = shaders;
  while (entry->type_ != GL_NONE) {
    GLuint shader = glCreateShader(entry->type_);
    entry->shader_ = shader;

    //const GLchar* source = ReadShader(entry->file_name_).c_str();
    const GLchar* source = ReadShader(entry->file_name_);
    if (source == NULL) {
      for (entry = shaders; entry->type_ != GL_NONE; ++entry) {
        glDeleteShader(entry->shader_);
        entry->shader_ = 0;
      }
    }

    glShaderSource(shader, 1, &source, NULL);
    delete[] source;
    glCompileShader(shader);

    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
#ifdef _DEBUG
      GLsizei len;
      glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
      GLchar* log = new GLchar[len + 1];
      glGetShaderInfoLog(shader, len, &len, log);
      std::cerr << "Shader compilation failed: " << log << std::endl;
      delete[] log;
#endif
      return 0;
    }
    glAttachShader(program, shader);
    ++entry;
  }

  glLinkProgram(program);
  GLint linked;
  glGetProgramiv(program, GL_LINK_STATUS, &linked);
  if (!linked) {
#ifdef _DEBUG
      GLsizei len;
      glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
      GLchar* log = new GLchar[len + 1];
      glGetProgramInfoLog(program, len, &len, log);
      std::cerr << "Program link failed: " << log << std::endl;
      delete[] log;
#endif
  }
  
  // Delete shaders after link program
  for (entry = shaders; entry->type_ != GL_NONE; ++entry) {
    glDeleteShader(entry->shader_);
    entry->shader_ = 0;
  }
  return program;
}
