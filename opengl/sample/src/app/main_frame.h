#ifndef CIGPS_FRAME_H
#define CIGPS_FRAME_H

#include <wx/frame.h>

class GLCanvas;
class MainFrame : public wxFrame {
  DECLARE_EVENT_TABLE()

public:
  MainFrame(const wxString& title);
  virtual ~MainFrame();

protected:
  GLCanvas* canvas_;
};

#endif // CIGPS_FRAME_H
