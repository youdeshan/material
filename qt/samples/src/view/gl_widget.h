#ifndef GL_WIDGET_H
#define GL_WIDGET_H

#include <QOpenGLWidget>

class GLWidget : public QOpenGLWidget {
  Q_OBJECT

public:
  explicit GLWidget(QWidget *parent = 0);
  ~GLWidget();

  QSize minimumSizeHint() const override;
  QSize sizeHint() const override;

protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;

  private slots:
};

#endif // GL_WIDGET_H
