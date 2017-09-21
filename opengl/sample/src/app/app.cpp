#include "app.h"

#include <wx/image.h>
#include <wx/xrc/xmlres.h>

#include "main_frame.h"

IMPLEMENT_APP(App)

BEGIN_EVENT_TABLE(App, wxApp)
END_EVENT_TABLE()

bool App::OnInit()
{
  wxLocale *ll = new wxLocale(wxLANGUAGE_ENGLISH);
  if (!wxApp::OnInit()) {
    return false;
  }

  wxXmlResource::Get()->InitAllHandlers();
  if (!wxXmlResource::Get()->LoadAllFiles("rc")) {
    return false;
  }

#ifdef WIN32
  AllocConsole();
  freopen("CONOUT$", "w", stdout);//neceesary
  HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
  int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
  FILE* hf_out = _fdopen(hCrt, "w");
  setvbuf(hf_out, NULL, _IONBF, 1);
  *stdout = *hf_out;

  freopen("CONIN$", "r", stdin);//necessary
  HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
  hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
  FILE* hf_in = _fdopen(hCrt, "r");
  setvbuf(hf_in, NULL, _IONBF, 128);
  *stdin = *hf_in;
#endif // WIN32

  wxImage::AddHandler(new wxPNGHandler);

  main_frame_ = new MainFrame(_T("Hello Opengl"));
  main_frame_->Show();

  return true;
}
