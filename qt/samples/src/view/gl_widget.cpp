#include "gl_widget.h"

#include <QMessageBox>

GLWidget::GLWidget(QWidget *parent) 
  : QOpenGLWidget(parent) {
}

GLWidget::~GLWidget() {
}

QSize GLWidget::minimumSizeHint() const {
  return QSize(150, 150);
}

QSize GLWidget::sizeHint() const {
  return QSize(800, 600);
}

void GLWidget::initializeGL() {

}

void GLWidget::paintGL() {

}

void GLWidget::resizeGL(int w, int h) {

}
