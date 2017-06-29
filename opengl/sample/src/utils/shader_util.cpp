#include "utils/shader_util.h"
#include <fstream>

std::string load_shader_source(const std::string& file_path) {
  std::ifstream ifs(file_path, std::ifstream::in);
  if (!ifs.good()) return "";

  return std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
}
