#ifndef GL_WINDOW_H
#define GL_WINDOW_H

#include <QOpenGLWidget>

class GLWindow : public QOpenGLWidget{
    Q_OBJECT

public:
    explicit GLWindow(QWidget *parent = 0);
    ~GLWindow();

    private slots:
    void on_submit_clicked();
    void on_cancel_clicked();

private:
    Ui::UserInfoWindow *ui;
};

#endif // USER_INFO_WINDOW_H
