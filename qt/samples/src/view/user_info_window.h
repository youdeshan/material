#ifndef USER_INFO_WINDOW_H
#define USER_INFO_WINDOW_H

#include <QWidget>

namespace Ui {
    class UserInfoWindow;
}

/*
  This window is layout with gridLayout,
  and put fixed controls in a Widget container, 
  then adjust the alignment of container
  |--------|--------|
  |--------|QWidget-|
  |--------|--------|
  |-----QWidget-----|
*/
class UserInfoWindow : public QWidget {
    Q_OBJECT

public:
    explicit UserInfoWindow(QWidget *parent = 0);
    ~UserInfoWindow();

    private slots:
    void on_submit_clicked();
    void on_cancel_clicked();

private:
    Ui::UserInfoWindow *ui;
};

#endif // USER_INFO_WINDOW_H
