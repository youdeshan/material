#ifndef CIGPS_FRAME_H
#define CIGPS_FRAME_H

#include <wx/frame.h>

class GLCanvas;
class wxLogWindow;
class MainFrame : public wxFrame {
  DECLARE_EVENT_TABLE()

public:
  MainFrame(const wxString& title);
  virtual ~MainFrame();

#if wxUSE_LOGWINDOW
  void OnLogWindow(wxCommandEvent& evt);
#endif

protected:
  GLCanvas* canvas_;

#if wxUSE_LOGWINDOW
  wxLogWindow* log_window_;
#endif
};

#endif // CIGPS_FRAME_H
