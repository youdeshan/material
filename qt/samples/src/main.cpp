#include <QApplication>

#include <QLabel>
#include <QPushButton>
#include <QTextCodec>

#include "view/mainwindow.h"
#include "view/logindialog.h"

int main(int argc, char *argv[])
{
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
