#ifndef GL_WIDGET_H
#define GL_WIDGET_H

#include <QOpenGLWidget>

class GLRenderer;
class Graph;
class QMouseEvent;
class QKeyEvent;
class QWheelEvent;
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

  // Event handler
  void mousePressEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

  private slots:

private:
  GLRenderer* renderer_;
  Graph* scene_graph_;

  bool mouse_down_;
  int pos_down_[2];
};

#endif // GL_WIDGET_H
