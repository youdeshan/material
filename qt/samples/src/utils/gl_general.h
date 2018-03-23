#ifndef GL_GENERAL_H
#define GL_GENERAL_H

extern void CheckGLError(const char* file, int line);

#define  GL_CHECK CheckGLError(__FILE__,__LINE__);

#endif // GL_GENERAL_H
