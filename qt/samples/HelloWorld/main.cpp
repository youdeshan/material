#include "mainwindow.h"
#include <QApplication>

#include <QLabel>
#include <QPushButton>
#include "newspaper.h"
#include "reader.h"
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog login_dlg;
    if (login_dlg.exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    } else {
        return 0;
    }
    //QLabel label("Hello world!");
    //label.show();

    /*QPushButton button("Quit");
    //QObject::connect(&button, &QPushButton::clicked, &QApplication::quit);
    QObject::connect(&button, &QPushButton::clicked, [](bool){qDebug("You clicked me!");});
    button.show();

    Newspaper newspaper("pepeole newspaper");
    Reader reader;
    QObject::connect(&newspaper, &Newspaper::newPaper, &reader, &Reader::receiveNewspaper);
    newspaper.send();*/

}
