#include <QApplication>

#include <QLabel>
#include <QPushButton>
#include <QTextCodec>

#ifdef WIN32 || WIN64
#include <windows.h>
#endif // WIN32 || WIN64


#include "view/mainwindow.h"
#include "view/logindialog.h"

int main(int argc, char *argv[]) {
  {
    FreeConsole();
    AllocConsole();
    AttachConsole(GetCurrentProcessId());

    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);
    freopen("CON", "r", stdin);
  }
  QApplication a(argc, argv);
  LoginDialog login_dlg;
  if (login_dlg.exec() == QDialog::Accepted) {
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));

    MainWindow w;
    w.show();
    return a.exec();
  } else {
    return 0;
  }
}
