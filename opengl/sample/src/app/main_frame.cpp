#include "main_frame.h"

#include <wx/sizer.h>
#include <wx/log.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>

#include "app/gl_canvas.h"
#include "util/log.h"

#define ID_LOG_WINDOW wxID_HIGHEST + 10

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
#if wxUSE_LOGWINDOW
    EVT_MENU(ID_LOG_WINDOW, MainFrame::OnLogWindow)
#endif
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
  : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {
  wxMenu* file_menu = new wxMenu;
#if wxUSE_LOGWINDOW
  file_menu->Append(ID_LOG_WINDOW, "&Log window", "Open the log window");
#endif

  wxMenuBar* menu_bar = new wxMenuBar();
  menu_bar->Append(file_menu, "&File");
  SetMenuBar(menu_bar);

#if wxUSE_LOGWINDOW
  log_window_ = new wxLogWindow(NULL, "Opengl log window", false, false);
  wxLog::SetActiveTarget(log_window_);
#endif

  wxGLAttributes vAttrs;
  vAttrs.PlatformDefaults().Defaults().EndList();
  bool accepted = wxGLCanvas::IsDisplaySupported(vAttrs);
  if (accepted) {
      LOG_MESSAGE("The display supports required visual attribute.");
  } else {
#if wxUSE_LOGWINDOW
      wxLogMessage("First try with opengl default visual attributes failed.");
#endif
      vAttrs.Reset();
      vAttrs.PlatformDefaults().RGBA().DoubleBuffer().Depth(16).EndList();
      accepted = wxGLCanvas::IsDisplaySupported(vAttrs);
      if (!accepted) {
          wxMessageBox("Visual attributes for opengl are not accepted.\nThe app will exit now.", "Error with opengl", wxOK | wxICON_ERROR);
      } else {
#if wxUSE_LOGWINDOW
      wxLogMessage("Second try with other visual attributes worked.");
#endif
      }
  }
  if (accepted) {
    canvas_ = new GLCanvas(this, vAttrs);

    wxSizer* body_sizer = new wxBoxSizer(wxVERTICAL);
    body_sizer->Add(canvas_, 1, wxEXPAND);
    SetSizer(body_sizer);
    Layout();
  }
  SetMinSize(wxSize(250, 200));
}

MainFrame::~MainFrame() {
}

#if wxUSE_LOGWINDOW
void MainFrame::OnLogWindow(wxCommandEvent& evt) {
    if (log_window_->GetFrame()->IsIconized())
        log_window_->GetFrame()->Restore();
    if (!log_window_->GetFrame()->IsShown())
        log_window_->Show();

    log_window_->GetFrame()->SetFocus();
}
#endif
