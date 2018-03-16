#include "view/logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->UserlineEdit->setText(tr("youdeshan"));
    ui->PasswdlineEdit->setText(tr("123"));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginButton_clicked()
{
    if (ui->UserlineEdit->text().trimmed() == tr("youdeshan")
            && ui->PasswdlineEdit->text() == tr("123")) {
        accept();
    } else {
        QMessageBox::warning(this, tr("Warning"), tr("User name or password is wrong!"), QMessageBox::Yes);

        ui->UserlineEdit->clear();
        ui->PasswdlineEdit->clear();
        ui->UserlineEdit->setFocus();
    }
}
