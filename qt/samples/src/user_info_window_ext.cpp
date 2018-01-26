#include "user_info_window_ext.h"
#include "ui_userinfowindowext.h"

#include <QMessageBox>

UserInfoWindowExt::UserInfoWindowExt(QWidget *parent) :
    QWidget(parent, Qt::Window),
    ui(new Ui::UserInfoWindowExt) {
    ui->setupUi(this);
}

UserInfoWindowExt::~UserInfoWindowExt() {
    delete ui;
}

void UserInfoWindowExt::on_submit_clicked() {
}

void UserInfoWindowExt::on_cancel_clicked() {

}
