#ifndef GL_LOG_H
#define GL_LOG_H

#include <wx/log.h>

#ifndef LOG_MESSAGE
#define LOG_MESSAGE(msginfo) //{#if wxUSE_LOGWINDOW wxLogMessage(msginfo); #endif}
#endif

#endif // GL_LOG_H
