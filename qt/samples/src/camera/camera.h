#ifndef CAMERA_H_
#define CAMERA_H_

//#include <gl/GL.h>
#include <QtGui/qopengl.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

const GLfloat kYaw = -90.0f;
const GLfloat kPitch = 0.0f;
const GLfloat kSpeed = 0.25f;
const GLfloat kSensitivity = 0.1f;
const GLfloat kZoom = 45.0f;
const glm::vec3 kPosition = glm::vec3(0.0f, 0.0f, 3.0f);
const glm::vec3 kWorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

class Camera {
public:
  enum MoveDirection {
    kForward,
    kBackward,
    kLeft,
    kRight,
    kStatic
  };

  Camera(glm::vec3 position = kPosition,
         glm::vec3 up = kWorldUp,
         GLfloat pitch = kPitch,
         GLfloat yaw = kYaw);
  ~Camera();

  glm::mat4 GetViewMatrix();
  GLfloat zoom() { return zoom_; }

  void ProcessKeyboard(MoveDirection dir);
  void ProcessMouseMovement(GLfloat x_offset, GLfloat y_offset, GLboolean contrain_pitch = true);
  void ProcessMouseScroll(GLfloat y_offset);

  void Reset();

protected:
  void UpdateVectors();

private:
  glm::vec3 position_;
  glm::vec3 front_;
  glm::vec3 up_;
  glm::vec3 right_;
  glm::vec3 world_up_;

  GLfloat pitch_;
  GLfloat yaw_;

  GLfloat zoom_;
};
#endif // CAMERA_H_
