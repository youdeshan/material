#include "main_frame.h"

#include <wx/sizer.h>

#include "app/gl_canvas.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title)
  : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600)) {
  wxGLAttributes vAttrs;
  vAttrs.PlatformDefaults().RGBA().DoubleBuffer().Depth(16).EndList();
  canvas_ = new GLCanvas(this, vAttrs);

  wxSizer* body_sizer = new wxBoxSizer(wxVERTICAL);
  body_sizer->Add(canvas_, 1, wxEXPAND);
  SetSizer(body_sizer);
  Layout();
}

MainFrame::~MainFrame() {
}
