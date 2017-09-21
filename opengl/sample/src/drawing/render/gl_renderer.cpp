#include "drawing/render/gl_renderer.h"

#include <iostream>
//#include <glad/glad.h>
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader/shader_program.h"
#include "shader/shader_info.h"
#include "camera/camera.h"

#include "drawing/context/context.h"

ShaderInfo shaders[] = {
  { GL_VERTEX_SHADER, "glsl/triangles.vert" },
  { GL_FRAGMENT_SHADER, "glsl/triangles.frag" },
  { GL_NONE, NULL }
};

GLfloat vertices[] = {
  -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
  0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
  -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
  -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

  -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
  0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
  0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
  0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
  -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
  -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

  -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
  -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
  -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
  -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
  -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
  -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
  0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
  0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
  0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

  -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
  0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
  0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
  0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
  -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
  -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

  -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
  -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
  -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

glm::vec3 cubePositions[] = {
  glm::vec3(0.0f,  0.0f,  0.0f),
  glm::vec3(2.0f,  5.0f, -15.0f),
  glm::vec3(-1.5f, -2.2f, -2.5f),
  glm::vec3(-3.8f, -2.0f, -12.3f),
  glm::vec3(2.4f, -0.4f, -3.5f),
  glm::vec3(-1.7f,  3.0f, -7.5f),
  glm::vec3(1.3f, -2.0f, -2.5f),
  glm::vec3(1.5f,  2.0f, -2.5f),
  glm::vec3(1.5f,  0.2f, -1.5f),
  glm::vec3(-1.3f,  1.0f, -1.5f)
};


GLRenderer::GLRenderer(IContext* context) : IRenderer(context), program_(NULL), camera_(NULL), mix_val_(0.2) {
  InitGL();
}

GLRenderer::~GLRenderer() {
  if (program_) delete program_;
  program_ = NULL;

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

  context_->SetCurrent();
  glViewport(0, 0, width, height);
}

void GLRenderer::Draw() {
  context_->SetCurrent();

  glBindVertexArray(vao_);
  // Bind textures on corresponding texture units
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture0_);
  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_2D, texture1_);

  glEnable(GL_DEPTH_TEST);

  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Be sure to activate the shader before any calls to glUniform
  program_->Use();
  program_->SetFloat("mixValue", mix_val_);

  glm::mat4 projection;
  projection = glm::perspective(glm::radians(camera_->zoom()), (GLfloat) win_size_[0] / (GLfloat)win_size_[1], 0.1f, 100.0f);
  program_->SetMatrix("projection", glm::value_ptr(projection));

  glm::mat4 view;
  view = camera_->GetViewMatrix();
  program_->SetMatrix("view", glm::value_ptr(view));

  for (GLuint i = 0; i < 10; ++i) {
    glm::mat4 model;
    model = glm::translate(model, cubePositions[i]);
    //model = glm::rotate(model, (GLfloat)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
    program_->SetMatrix("model", glm::value_ptr(model));

    // Draw triangles by vertex
    glDrawArrays(GL_TRIANGLES, 0, 36);
  }

  // Draw triangles by indices
  //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void GLRenderer::InitGL() {
  context_->SetCurrent();

  if (!gladLoadGL()) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return;
  }
  program_ = new ShaderProgram(shaders);
  camera_ = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));

  GLuint VBO, EBO;
  glGenVertexArrays(1, &vao_);
  glGenBuffers(1, &VBO);
  //glGenBuffers(1, &EBO);

  glBindVertexArray(vao_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));
  glEnableVertexAttribArray(1);

  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  // Remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO
  // You should unbind the EBO after VAO is unbinded.
  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // Load and create a texture0
  glGenTextures(1, &texture0_);
  glBindTexture(GL_TEXTURE_2D, texture0_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  //GLfloat border_color[] = { 1.0f, 1.0f, 0.0f, 1.0f };
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
  //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  GLint width, height, nrChannels;
  stbi_set_flip_vertically_on_load(true);
  GLubyte* data = stbi_load("resources/texture/container.jpg", &width, &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else {
    std::cout << "Failed to load texture0." << std::endl;
  }
  stbi_image_free(data);
  glBindTexture(GL_TEXTURE_2D, 0);

  // Load and create a texture1
  glGenTextures(1, &texture1_);
  glBindTexture(GL_TEXTURE_2D, texture1_);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  data = stbi_load("resources/texture/awesomeface.png", &width, &height, &nrChannels, 0);
  if (data) {
    // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else {
    std::cout << "Failed to load texture1." << std::endl;
  }
  stbi_image_free(data);
  glBindTexture(GL_TEXTURE_2D, 0);

  program_->Use();
  program_->SetInt("texture0", 0);
  program_->SetInt("texture1", 1);

  // Draw in wireframe polygons
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // Cull face
  //glEnable(GL_CULL_FACE);
  //glCullFace(GL_BACK);
  //glFrontFace(GL_CCW);
}
