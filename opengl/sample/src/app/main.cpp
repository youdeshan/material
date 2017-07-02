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

//#include <GL/glew.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "utils/shader_util.h"
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
  { GL_VERTEX_SHADER, "triangles.vert" },
  { GL_FRAGMENT_SHADER, "triangles.frag" },
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
  GLuint program = LoadShaders(shaders);
  GLfloat vertices[] = {
      -0.5f, -0.5f, 0.0f,
      0.5f, -0.5f, 0.0f,
      0.0f, 0.5f, 0.0f
  };

  GLuint VAO, VBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  while (!glfwWindowShouldClose(win)) {
    ProcessInput(win);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glfwSwapBuffers(win);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);

  glfwTerminate();
  return 0;
}
