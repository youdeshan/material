#include "user_info_window.h"
#include "ui_userinfowindow.h"

#include <QMessageBox>

GLWindow::GLWindow(QWidget *parent) :
    QWidget(parent, Qt::Window),
    ui(new Ui::UserInfoWindow) {
    ui->setupUi(this);
}

GLWindow::~GLWindow() {
    delete ui;
}

void GLWindow::on_submit_clicked() {
}

void GLWindow::on_cancel_clicked() {

}
