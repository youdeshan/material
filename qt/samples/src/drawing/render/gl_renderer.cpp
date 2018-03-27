#include "drawing/render/gl_renderer.h"

#include <iostream>
//#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Compatibility>

#include "utils/gl_general.h"
#include "camera/camera.h"

GLfloat vertices[] = {
  -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
  0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
  0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
  0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
  -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
  -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

  -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
  0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
  0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
  0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
  -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
  -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

  -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
  -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
  -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
  -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
  -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
  -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
  0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
  0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
  0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
  0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

  -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
  0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
  0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
  0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
  -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
  -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

  -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
  0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
  -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
  -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};

glm::vec3 objectColor = glm::vec3(1.0f, 0.5f, 0.31f);
glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
//glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
glm::vec3 lightPos = glm::vec3(0.7f, 0.7f, 0.7f);

GLRenderer::GLRenderer() : IRenderer(), cube_program_(NULL), camera_(NULL), mix_val_(0.2) {
}

GLRenderer::~GLRenderer() {
  if (cube_program_) delete cube_program_;
  if (lamp_program_) delete lamp_program_;
  cube_program_ = NULL;
  lamp_program_ = NULL;

  if (camera_) delete camera_;
  camera_ = NULL;
}

void GLRenderer::set_mix_val(GLfloat val) {
  mix_val_ = val;
  if (mix_val_ >= 1.0f) mix_val_ = 1.0f;
  if (mix_val_ <= 0.0f) mix_val_ = 0.0f;
}

void GLRenderer::Resize(int width, int height) {
  win_size_[0] = width;
  win_size_[1] = height;

  QOpenGLFunctions_3_3_Compatibility* funcs = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Compatibility>();
  funcs->glViewport(0, 0, width, height);
}

void GLRenderer::Draw() {
  QOpenGLFunctions_3_3_Compatibility* funcs = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Compatibility>();

  funcs->glEnable(GL_DEPTH_TEST);

  funcs->glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  funcs->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  cube_program_->bind();
  cube_program_->setUniformValue("objectColor", QVector3D(1.0f, 0.5f, 0.31f));
  cube_program_->setUniformValue("lightColor", QVector3D(1.0f, 1.0f, 1.0f));
  cube_program_->setUniformValue("lightPos", QVector3D(lightPos.x, lightPos.y, lightPos.z));
  glm::vec3 camera_pos = camera_->position();
  cube_program_->setUniformValue("viewPos", QVector3D(camera_pos.x, camera_pos.y, camera_pos.z));

  glm::mat4 projection;
  projection = glm::perspective(glm::radians(camera_->zoom()), (GLfloat) win_size_[0] / (GLfloat)win_size_[1], 0.1f, 100.0f);
  cube_program_->setUniformValue("projection", QMatrix4x4(glm::value_ptr(glm::transpose(projection))));

  glm::mat4 view;
  view = camera_->GetViewMatrix();
  cube_program_->setUniformValue("view", QMatrix4x4(glm::value_ptr(glm::transpose(view))));

  glm::mat4 model;
  cube_program_->setUniformValue("model", QMatrix4x4(glm::value_ptr(glm::transpose(model))));

  // Render the cube 
  funcs->glBindVertexArray(cube_vao_);
  funcs->glDrawArrays(GL_TRIANGLES, 0, 36);
  funcs->glBindVertexArray(0);
  cube_program_->release();

  lamp_program_->bind();
  lamp_program_->setUniformValue("projection", QMatrix4x4(glm::value_ptr(glm::transpose(projection))));
  lamp_program_->setUniformValue("view", QMatrix4x4(glm::value_ptr(glm::transpose(view))));
  model = glm::mat4();
  model = glm::translate(model, lightPos);
  model = glm::scale(model, glm::vec3(0.2));
  lamp_program_->setUniformValue("model", QMatrix4x4(glm::value_ptr(glm::transpose(model))));

  // Render the light
  funcs->glBindVertexArray(light_vao_);
  funcs->glDrawArrays(GL_TRIANGLES, 0, 36);

  funcs->glBindVertexArray(0);
  lamp_program_->release();
}

void GLRenderer::InitGL() {
  cube_program_ = new QOpenGLShaderProgram();
  cube_program_->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/glsl/colors.vs");
  cube_program_->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/glsl/colors.fs");
  cube_program_->link();

  lamp_program_ = new QOpenGLShaderProgram();
  lamp_program_->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/res/glsl/lamp.vs");
  lamp_program_->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/res/glsl/lamp.fs");
  lamp_program_->link();

  camera_ = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));

  QOpenGLFunctions_3_3_Compatibility* funcs = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Compatibility>();

  GLuint VBO;
  funcs->glGenBuffers(1, &VBO);

  funcs->glBindBuffer(GL_ARRAY_BUFFER, VBO);
  funcs->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  // Init cube vao
  funcs->glGenVertexArrays(1, &cube_vao_);
  funcs->glBindVertexArray(cube_vao_);
  funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)0);
  funcs->glEnableVertexAttribArray(0);

  funcs->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));
  funcs->glEnableVertexAttribArray(1);

  // Init light vao
  funcs->glGenVertexArrays(1, &light_vao_);
  funcs->glBindVertexArray(light_vao_);
  funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GL_FLOAT), (void*)0);
  funcs->glEnableVertexAttribArray(0);

  funcs->glBindBuffer(GL_ARRAY_BUFFER, 0);
  funcs->glBindVertexArray(0);
}
