#include "utils/gl_general.h"

#include <QtGui/qopengl.h>
#include <QOpenGLFunctions_3_3_Compatibility>

void CheckGLError(const char* file, int line) {
  QOpenGLFunctions_3_3_Compatibility* funcs = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Compatibility>();

  GLenum error = funcs->glGetError();
  if (error != GL_NO_ERROR) {
    switch (error) {
    case GL_INVALID_ENUM:
      //printf("GL Error: GL_INVALID_ENUM %s : %d \n", file, line);
      qInfo("GL Error: GL_INVALID_ENUM %s : %d \n", file, line);
      break;
    case GL_INVALID_VALUE:
      qInfo("GL Error: GL_INVALID_VALUE %s : %d \n", file, line);
      break;
    case GL_INVALID_OPERATION:
      qInfo("GL Error: GL_INVALID_OPERATION %s : %d \n", file, line);
      break;
    case GL_STACK_OVERFLOW:
      qInfo("GL Error: GL_STACK_OVERFLOW %s : %d \n", file, line);
      break;
    case GL_STACK_UNDERFLOW:
      qInfo("GL Error: GL_STACK_UNDERFLOW %s : %d \n", file, line);
      break;
    case GL_OUT_OF_MEMORY:
      qInfo("GL Error: GL_OUT_OF_MEMORY %s : %d \n", file, line);
      break;
    default:
      qInfo("GL Error: 0x%x %s : %d \n", error, file, line);
      break;
    }
  }
}
