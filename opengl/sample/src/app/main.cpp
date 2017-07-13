//#include <GL/glut.h>
//
//void Display() {
//  glClear(GL_COLOR_BUFFER_BIT);
//  glBegin(GL_TRIANGLES);
//  glVertex3f(0.0f, 1.0f, 0.0f);
//  glVertex3f(-1.0f, -1.0f, 0.0f);
//  glVertex3f(1.0f, -1.0f, 0.0f);
//  glEnd();
//  glFlush();
//}
//
//int main(int argc, char* argv[]) {
//  glutInit(&argc, argv);
//  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//  glutInitWindowPosition(100, 100);
//  glutInitWindowSize(400, 400);
//  glutCreateWindow("Hello world!");
//  glutDisplayFunc(&Display);
//  glutMainLoop();
//  return 0;
//}
#include <iostream>
#include <cmath>

//#include <GL/glew.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "shader/shader_program.h"
#include "shader/shader_info.h"

//void Display() {
//  glClear(GL_COLOR_BUFFER_BIT);
//  glBegin(GL_TRIANGLES);
//  glVertex3f(0.0f, 1.0f, 0.0f);
//  glVertex3f(-1.0f, -1.0f, 0.0f);
//  glVertex3f(1.0f, -1.0f, 0.0f);
//  glEnd();
//  glFlush();
//}

ShaderInfo shaders[] = {
  { GL_VERTEX_SHADER, "glsl/triangles.vert" },
  { GL_FRAGMENT_SHADER, "glsl/triangles.frag" },
  { GL_NONE, NULL }
};

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT= 600;

void framebuffer_size_callback(GLFWwindow* win, int width, int height) {
    glViewport(0, 0, width, height);
}

void ProcessInput(GLFWwindow* win) {
    if (glfwGetKey(win, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(win, true);
    }
}

int main(int argc, char* argv[]) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow* win = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello opengl!", NULL, NULL);
  if (win == NULL) {
    std::cout << "Failed to create GLFW window!" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(win);
  glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);

  // glad: load all opengl function pointers
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return -1;
  }

//  glewExperimental = GL_TRUE;
//  if (glewInit() != GLEW_OK) {
//    std::cout << "Failed to initialize GLEW!" << std::endl;
//    return -1;
//  }
  ShaderProgram program(shaders);
  GLfloat vertices[] = {
      0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,// top right
      0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,// bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,// bottom left
      -0.5f, 0.5f, 0.0f, 1.0f, 0.5f, 0.0f ,0.0f, 1.0f// top left
  };

  GLuint indices[] = {
      0, 1, 3,
      //1, 2, 3
      3, 2, 1
  };

  GLuint VAO, VBO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(3 * sizeof(GL_FLOAT)));
  glEnableVertexAttribArray(1);

  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (void*)(6 * sizeof(GL_FLOAT)));
  glEnableVertexAttribArray(2);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  // Remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO
  // You should unbind the EBO after VAO is unbinded.
  // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // Load and create a texture0
  GLuint texture0;
  glGenTextures(1, &texture0);
  glBindTexture(GL_TEXTURE_2D, texture0);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  GLint width, height, nrChannels;
  stbi_set_flip_vertically_on_load(true);
  GLubyte* data = stbi_load("resources/texture/container.jpg", &width, &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture0." << std::endl;
  }
  stbi_image_free(data);
  glBindTexture(GL_TEXTURE_2D, 0);

  // Load and create a texture1
  GLuint texture1;
  glGenTextures(1, &texture1);
  glBindTexture(GL_TEXTURE_2D, texture1);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  data = stbi_load("resources/texture/awesomeface.png", &width, &height, &nrChannels, 0);
  if (data) {
    // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture1." << std::endl;
  }
  stbi_image_free(data);
  glBindTexture(GL_TEXTURE_2D, 0);

  program.Use();
  program.SetInt("texture0", 0);
  program.SetInt("texture1", 1);

  // Draw in wireframe polygons
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // Cull face
  //glEnable(GL_CULL_FACE);
  //glCullFace(GL_BACK);
  //glFrontFace(GL_CCW);

  while (!glfwWindowShouldClose(win)) {
    ProcessInput(win);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Be sure to activate the shader before any calls to glUniform
    program.Use();
    glBindVertexArray(VAO);

    // Bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture0);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture1);

    // Update shader uniform, app exchanges data with shader by uniform
    //GLfloat time_val = glfwGetTime();
    //GLfloat green_val = sin(time_val) / 2.0f + 0.5f;
    //GLint vertex_loc = glGetUniformLocation(program, "ourColor");
    //glUniform4f(vertex_loc, 0.0f, green_val, 0.0f, 1.0f);

    // Draw triangles by vertex
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    
    // Draw triangles by indices
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
    glfwSwapBuffers(win);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
  glDeleteTextures(1, &texture0);

  glfwTerminate();
  return 0;
}
