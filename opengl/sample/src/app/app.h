#ifndef DRAWING_APP_H
#define DRAWING_APP_H

#include <wx/app.h>

class MainFrame;
class App : public wxApp
{
public:
  virtual bool OnInit();

private:
  MainFrame* main_frame_;
  
  DECLARE_EVENT_TABLE()
};

DECLARE_APP(App)

#endif // DRAWING_APP_H
