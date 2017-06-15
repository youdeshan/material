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

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//void Display() {
//  glClear(GL_COLOR_BUFFER_BIT);
//  glBegin(GL_TRIANGLES);
//  glVertex3f(0.0f, 1.0f, 0.0f);
//  glVertex3f(-1.0f, -1.0f, 0.0f);
//  glVertex3f(1.0f, -1.0f, 0.0f);
//  glEnd();
//  glFlush();
//}

int main(int argc, char* argv[]) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow* win = glfwCreateWindow(800, 600, "Hello opengl!", nullptr, nullptr);
  if (win == nullptr) {
    std::cout << "Failed to create GLFW window!" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(win);

  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cout << "Failed to initialize GLEW!" << std::endl;
    return -1;
  }
  return 0;
}