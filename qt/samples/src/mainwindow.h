#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

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
    void OnSaveFile();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
