#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    //QToolBar* toolbar = addToolBar(tr("&File"));
    //toolbar->addAction(openAction);

    ui->setupUi(this);

    ui->label->setText(u8"Hello, welcome to QT world! »¶Ó­ÓÎµÂÉ½£¡");
    ui->menu_file->addSeparator();

    // Add menu item(QAction) for save
    QAction* save_action = new QAction(tr("&Save(&S)"), this);
    QIcon save_icon(":/res/save_file");
    save_action->setIcon(save_icon);
    save_action->setShortcut(QKeySequence(tr("Ctrl+S")));
    save_action->setStatusTip(tr("Save file"));
    connect(save_action, &QAction::triggered, this, &MainWindow::OnSaveFile);
    ui->menu_file->addAction(save_action);

    // Add toolbar item(QAction) for save
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(save_action);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnNewFile() {
    QDialog* dlg = new QDialog(this);
    dlg->setMinimumSize(QSize(300, 200));
    dlg->setWindowTitle(tr("New file dialog"));
    dlg->setAttribute(Qt::WA_DeleteOnClose); // destroy the dialog when closing the dialog
    dlg->show();
}

void MainWindow::OnSaveFile() {
    //QMessageBox::information(this, tr("Info"), tr("Open"));
    QDialog* dlg = new QDialog(this);
    dlg->setMinimumSize(QSize(300, 200));
    dlg->setWindowTitle(tr("Save file dialog"));
    dlg->setAttribute(Qt::WA_DeleteOnClose); // destroy the dialog when closing the dialog
    dlg->show();
}

void MainWindow::test_click() {
    QMessageBox::about(NULL, "About", "The test button was clicked!");
}
