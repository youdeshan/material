#ifndef USER_INFO_WINDOW_EXT_H
#define USER_INFO_WINDOW_EXT_H

#include <QWidget>

namespace Ui {
    class UserInfoWindowExt;
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
class UserInfoWindowExt : public QWidget {
    Q_OBJECT

public:
    explicit UserInfoWindowExt(QWidget *parent = 0);
    ~UserInfoWindowExt();

    private slots:
    void on_submit_clicked();
    void on_cancel_clicked();

private:
    Ui::UserInfoWindowExt *ui;
};

#endif // USER_INFO_WINDOW_EXT_H
