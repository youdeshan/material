#include "user_info_window.h"
#include "ui_userinfowindow.h"

#include <QMessageBox>

UserInfoWindow::UserInfoWindow(QWidget *parent) :
    QWidget(parent, Qt::Window),
    ui(new Ui::UserInfoWindow) {
    ui->setupUi(this);
}

UserInfoWindow::~UserInfoWindow() {
    delete ui;
}

void UserInfoWindow::on_submit_clicked() {
}

void UserInfoWindow::on_cancel_clicked() {

}
