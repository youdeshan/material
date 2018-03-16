#include "view/mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <qfile.h>
#include <qtextstream.h>
#include <QFileInfo>
#include <QFileDialog>
#include <QCloseEvent>

#include "view/user_info_window.h"
#include "view/user_info_window_ext.h"
#include "view/gl_widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    //QToolBar* toolbar = addToolBar(tr("&File"));
    //toolbar->addAction(openAction);

    ui->setupUi(this);

    //ui->label->setText(u8"Hello, welcome to QT world! »¶Ó­ÓÎµÂÉ½£¡");
    //ui->menu_file->addSeparator();

    /* Add menu item(QAction) for save */
    //QAction* save_action = new QAction(tr("&Save(&S)"), this);
    //QIcon save_icon(":/res/save_file");
    //save_action->setIcon(save_icon);
    //save_action->setShortcut(QKeySequence(tr("Ctrl+S")));
    //save_action->setStatusTip(tr("Save file"));
    //connect(save_action, &QAction::triggered, this, &MainWindow::OnSaveFile);
    //ui->menu_file->addAction(save_action);

    //ui->mainToolBar->addSeparator();
    //ui->mainToolBar->addAction(save_action);
    is_untitled_ = true;
    cur_file_name_ = tr("Unname.txt");
    setWindowTitle(cur_file_name_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnNewFile() {
    //QDialog* dlg = new QDialog(this);
    //dlg->setMinimumSize(QSize(300, 200));
    //dlg->setWindowTitle(tr("New file dialog"));
    //dlg->setAttribute(Qt::WA_DeleteOnClose); // destroy the dialog when closing the dialog
    //dlg->show();
    if (MaybeSave()) {
        is_untitled_ = true;
        cur_file_name_ = tr("Unname.txt");
        setWindowTitle(cur_file_name_);

        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

void MainWindow::OnOpenFile() {
    if (MaybeSave()) {
        QString file_name = QFileDialog::getOpenFileName(this, tr("Open file"));
        if (file_name.isEmpty()) return;

        LoadFile(file_name);
        ui->textEdit->setVisible(true);
    }
}

void MainWindow::OnSaveFile() {
    //QDialog* dlg = new QDialog(this);
    //dlg->setMinimumSize(QSize(300, 200));
    //dlg->setWindowTitle(tr("Save file dialog"));
    //dlg->setAttribute(Qt::WA_DeleteOnClose); // destroy the dialog when closing the dialog
    //dlg->show();

    Save();
}

void MainWindow::OnSaveAsFile() {
    SaveAs();
}

void MainWindow::OnCloseFile() {
    if (MaybeSave()) ui->textEdit->setVisible(false);
}

void MainWindow::OnExit() {
    if (MaybeSave()) ui->textEdit->setVisible(false);
    qApp->quit();
}

void MainWindow::OnUndo() {
    ui->textEdit->undo();
}

void MainWindow::OnCut() {
    ui->textEdit->cut();
}

void MainWindow::OnCopy() {
    ui->textEdit->copy();
}

void MainWindow::OnPaste() {
    ui->textEdit->paste();
}

void MainWindow::test_click() {
    QMessageBox::about(NULL, "About", "The test button was clicked!");
}

void MainWindow::on_user_info_click() {
    UserInfoWindow* user_info_win = new UserInfoWindow(this);
    user_info_win->show();
}

void MainWindow::on_user_info_ext_click() {
    UserInfoWindowExt* user_info_win = new UserInfoWindowExt(this);
    user_info_win->show();
}

void MainWindow::on_opengl_widget_click() {
  QWidget* w = new QWidget(this, Qt::Window);

  QVBoxLayout* layout = new QVBoxLayout();
  GLWidget* gl_widget = new GLWidget(w);
  layout->addWidget(gl_widget);

  w->setLayout(layout);
  w->show();
}

bool MainWindow::MaybeSave() {
    if (ui->textEdit->document()->isModified()) {
        int ret = QMessageBox::warning(this, tr("Multiple text editor"),
            tr("The document has been modified.\n""Do you want to save your changes?"),
            QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
            QMessageBox::Save);

        switch (ret) {
        case QMessageBox::Save:
            return Save();
        case QMessageBox::Cancel:
            return false;
        default:
            break;
        }
    }
    return true;
}

bool MainWindow::Save() {
    return is_untitled_ ? SaveAs() : SaveFile(cur_file_name_);
}

bool MainWindow::SaveAs() {
    QString file_name = QFileDialog::getSaveFileName(this, tr("Save as"), cur_file_name_);
    if (file_name.isEmpty()) return false;
    return SaveFile(file_name);
}

bool MainWindow::SaveFile(const QString& file_name) {
    QFile file(file_name);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Multiple document editor"), tr("Cannot write file %1: \n %2.").arg(file_name).arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << ui->textEdit->toPlainText();
    QApplication::restoreOverrideCursor();
    
    is_untitled_ = false;
    cur_file_name_ = QFileInfo(file_name).canonicalFilePath();
    setWindowTitle(cur_file_name_);
    return true;
}

bool MainWindow::LoadFile(const QString& file_name) {
    QFile file(file_name);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Multiple document editor"), tr("Cannot read file %1: \n %2.").arg(file_name).arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    ui->textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    is_untitled_ = false;
    cur_file_name_ = QFileInfo(file_name).canonicalFilePath();
    setWindowTitle(cur_file_name_);
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event) {
    MaybeSave() ? event->accept() : event->ignore();
}
