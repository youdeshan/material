#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QAction* openAction = new QAction(QIcon(":/images/previous"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::Open);

    //QMenu* file = menuBar()->addMenu(tr("&File"));
    //file->addAction(openAction);

    QToolBar* toolbar = addToolBar(tr("&File"));
    toolbar->addAction(openAction);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Open() {
    //QMessageBox::information(this, tr("Info"), tr("Open"));
    QDialog* dlg = new QDialog(this);
    dlg->setWindowTitle(tr("Hello, Dialog!"));
    dlg->setAttribute(Qt::WA_DeleteOnClose); // destroy the dialog when closing the dialog
    dlg->show();
}
