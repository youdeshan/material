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

//void Display() {
//  glClear(GL_COLOR_BUFFER_BIT);
//  glBegin(GL_TRIANGLES);
//  glVertex3f(0.0f, 1.0f, 0.0f);
//  glVertex3f(-1.0f, -1.0f, 0.0f);
//  glVertex3f(1.0f, -1.0f, 0.0f);
//  glEnd();
//  glFlush();
//}

#include <fstream>
void test() {
    std::ifstream ifs("D:\\aaa.txt", std::ifstream::in);
    if (!ifs.good()) {
      std::cout << "failed to open file" << std::endl;
    }
    std::string str((std::istreambuf_iterator<char>(ifs)),
      std::istreambuf_iterator<char>());
    OutputDebugStringA(str.c_str());
    ifs.close();
    return;
}

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
  test();

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


  while (!glfwWindowShouldClose(win)) {
    ProcessInput(win);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(win);
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}
