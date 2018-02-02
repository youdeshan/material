#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QCloseEvent;
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void test_click();
    void on_user_info_click();
    void on_user_info_ext_click();
    void OnNewFile();
    void OnOpenFile();
    void OnSaveFile();
    void OnSaveAsFile();
    void OnCloseFile();
    void OnExit();
    void OnUndo();
    void OnCut();
    void OnCopy();
    void OnPaste();

private:
    bool MaybeSave();
    bool Save();
    bool SaveAs();
    bool SaveFile(const QString& file_name);
    bool LoadFile(const QString& file_name);

    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;

    bool is_untitled_;
    QString cur_file_name_;
};

#endif // MAINWINDOW_H
