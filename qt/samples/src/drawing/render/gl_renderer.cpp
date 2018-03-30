#include "drawing/render/gl_renderer.h"

#include <iostream>
#include <ctime>
//#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions_3_3_Compatibility>
#include <QImage>

#include "utils/gl_general.h"
#include "camera/camera.h"

GLfloat vertices[] = {
  // positions          // normals           // texture coords
  -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
  0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
  0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
  0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
  -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
  -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

  -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
  0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
  0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
  0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
  -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
  -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

  -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
  -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
  -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
  -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
  -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
  -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
  0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
  0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
  0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
  0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
  0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

  -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
  0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
  0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
  0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
  -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
  -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

  -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
  0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
  0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
  -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
  -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
};

glm::vec3 objectColor = glm::vec3(1.0f, 0.5f, 0.31f);
glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
//glm::vec3 lightPos = glm::vec3(1.2f, 1.0f, 2.0f);
glm::vec3 lightPos = glm::vec3(0.7f, 0.7f, 0.7f);

GLint LoadTexture(const QString& file_path);

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
  //lightColor.x = std::abs(sin(std::time(nullptr) * 2.0f));
  //lightColor.y = std::abs(sin(std::time(nullptr) * 0.7f));
  //lightColor.z = std::abs(sin(std::time(nullptr) * 1.3f));
  //glm::vec3 diffuseColor = lightColor * glm::vec3(0.5f);
  //glm::vec3 ambientColor = diffuseColor * glm::vec3(0.2f);
  //cube_program_->setUniformValue("light.ambient", QVector3D(ambientColor.x, ambientColor.y, ambientColor.z));
  //cube_program_->setUniformValue("light.diffuse", QVector3D(diffuseColor.x, diffuseColor.y, diffuseColor.z));
  //cube_program_->setUniformValue("light.ambient", QVector3D(0.2f, 0.2f, 0.2f));
  //cube_program_->setUniformValue("light.diffuse", QVector3D(0.5f, 0.5f, 0.5f));
  //cube_program_->setUniformValue("light.specular", QVector3D(1.0f, 1.0f, 1.0f));
  cube_program_->setUniformValue("light.ambient", QVector3D(1.0f, 0.0f, 0.0f));
  cube_program_->setUniformValue("light.diffuse", QVector3D(1.0f, 0.0f, 0.0f));
  cube_program_->setUniformValue("light.specular", QVector3D(1.0f, 0.0f, 0.0f));
  cube_program_->setUniformValue("light.position", QVector3D(lightPos.x, lightPos.y, lightPos.z));
  cube_program_->setUniformValue("material.diffuse", 0);
  cube_program_->setUniformValue("material.specular", QVector3D(0.5f, 0.5f, 0.5f));
  cube_program_->setUniformValue("material.shininess", 32.0f);

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

  // Bind diffuse map
  funcs->glActiveTexture(GL_TEXTURE0);
  funcs->glBindTexture(GL_TEXTURE_2D, texture_id_);

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
  funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)0);
  funcs->glEnableVertexAttribArray(0);

  funcs->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));
  funcs->glEnableVertexAttribArray(1);

  funcs->glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(6 * sizeof(GL_FLOAT)));
  funcs->glEnableVertexAttribArray(2);

  // Init light vao
  funcs->glGenVertexArrays(1, &light_vao_);
  funcs->glBindVertexArray(light_vao_);
  funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)0);
  funcs->glEnableVertexAttribArray(0);

  funcs->glBindBuffer(GL_ARRAY_BUFFER, 0);
  funcs->glBindVertexArray(0);

  // Init texture
  GLint texture_id = LoadTexture(":/res/images/container.png");
  if (texture_id < 0) {
    printf("Failed to load texture image...");
  }
  texture_id_ = texture_id;
}

GLint LoadTexture(const QString& file_path) {
  QImage texture_img;
  if (!texture_img.load(file_path, "PNG")) return -1;

  QImage::Format img_format = texture_img.format();
  GLenum format;
  switch (img_format) {
  case QImage::Format_Mono:
  case QImage::Format_MonoLSB:
  case QImage::Format_Indexed8:
    format = GL_RED;
    break;
  case QImage::Format_RGB32:
    format = GL_RGB;
    break;
  case QImage::Format_ARGB32:
    format = GL_RGBA;
    break;
  default:
    return -1;
  }
  
  QOpenGLFunctions_3_3_Compatibility* funcs = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Compatibility>();
  if (funcs == nullptr) return -1;

  GLuint texture_id;
  funcs->glGenTextures(1, &texture_id);
  funcs->glBindTexture(GL_TEXTURE_2D, texture_id);
  funcs->glTexImage2D(GL_TEXTURE_2D, 0, format, texture_img.width(), texture_img.height(), 0, format, GL_UNSIGNED_BYTE, texture_img.constBits());
  funcs->glGenerateMipmap(GL_TEXTURE_2D);

  funcs->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  funcs->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  funcs->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  funcs->glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  return texture_id;
}
