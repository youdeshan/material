#include "gl_widget.h"

#include <QMessageBox>
#include <QMouseEvent>
#include <QKeyEvent>

#include "drawing/render/gl_renderer.h"
#include "drawing/scene/drawable.h"
#include "drawing/scene/graph.h"
#include "camera/camera.h"

GLWidget::GLWidget(QWidget *parent) 
  : QOpenGLWidget(parent), mouse_down_(false) {
  renderer_ = new GLRenderer();

  scene_graph_ = new Graph();
  auto draw_node = new Drawable();
  scene_graph_->AddChild(draw_node);

  setFocusPolicy(Qt::StrongFocus);
}

GLWidget::~GLWidget() {
  if (renderer_) delete renderer_;
  renderer_ = nullptr;

  if (scene_graph_) delete scene_graph_;
  scene_graph_ = NULL;
}

QSize GLWidget::minimumSizeHint() const {
  return QSize(150, 150);
}

QSize GLWidget::sizeHint() const {
  return QSize(800, 600);
}

void GLWidget::initializeGL() {
  renderer_->InitGL();
}

void GLWidget::paintGL() {
  renderer_->Draw();
}

void GLWidget::resizeGL(int w, int h) {
  renderer_->Resize(w, h);
}

void GLWidget::mousePressEvent(QMouseEvent *event) {
  mouse_down_ = true;
  pos_down_[0] = event->x();
  pos_down_[1] = size().height() - event->y();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event) {
  mouse_down_ = false;
}

void GLWidget::mouseMoveEvent(QMouseEvent *event) {
  if (!mouse_down_) return;

  int pos_x = event->x();
  int pos_y = size().height() - event->y();

  GLfloat offset_x = pos_x - pos_down_[0];
  GLfloat offset_y = pos_y - pos_down_[1];
  pos_down_[0] = pos_x;
  pos_down_[1] = pos_y;
  renderer_->camera()->ProcessMouseMovement(offset_x, offset_y);

  update();
}

void GLWidget::wheelEvent(QWheelEvent *event) {
  renderer_->camera()->ProcessMouseScroll(event->delta() > 0 ? 1.0 : -1.0);

  update();
}

void GLWidget::keyPressEvent(QKeyEvent *event) {
   Camera::MoveDirection dir = Camera::kStatic;
    switch (event->key()) {
    case Qt::Key_W:
      dir = Camera::kForward;
      break;
    case Qt::Key_S:
      dir = Camera::kBackward;
      break;
    case Qt::Key_A:
      dir = Camera::kLeft;
      break;
    case Qt::Key_D:
      dir = Camera::kRight;
      break;
    case Qt::Key_R:
      renderer_->camera()->Reset();
      break;
    default:
      break;
    }
    if (dir != Camera::kStatic) {
      renderer_->camera()->ProcessKeyboard(dir);
      update();
    }
}
