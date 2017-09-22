#include "camera/camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, GLfloat pitch, GLfloat yaw) 
  : position_(position), world_up_(up), pitch_(pitch), yaw_(yaw), zoom_(kZoom) {
  UpdateVectors();
}

Camera::~Camera() {
}

glm::mat4 Camera::GetViewMatrix() {
  return glm::lookAt(position_, position_ + front_, up_);
}

void Camera::ProcessKeyboard(MoveDirection dir) {
  //GLfloat velocity = move_speed_ * delta_time;
  GLfloat velocity = kSpeed;

  switch (dir) {
  case kForward:
    position_ += velocity * front_;
    break;
  case kBackward:
    position_ -= velocity * front_;
    break;
  case kLeft:
    position_ -= velocity * right_;
    break;
  case kRight:
    position_ += velocity * right_;
  }
}

void Camera::ProcessMouseMovement(GLfloat x_offset, GLfloat y_offset, GLboolean contrain_pitch) {
  x_offset *= kSensitivity;
  y_offset *= kSensitivity;

  pitch_ += y_offset;
  yaw_ += x_offset;
  if (contrain_pitch) {
    if (pitch_ > 89.0f) pitch_ = 89.0f;
    if (pitch_ < -89.0f) pitch_ = -89.0f;
  }

  UpdateVectors();
}

void Camera::ProcessMouseScroll(GLfloat y_offset) {
  if (zoom_ >= 1.0f && zoom_ <= 45.0f) zoom_ -= y_offset;
  if (zoom_ <= 1.0f) zoom_ = 1.0f;
  if (zoom_ >= 45.0f) zoom_ = 45.0f;
}

void Camera::Reset() {
  position_ = kPosition;
  pitch_ = kPitch;
  yaw_ = kYaw;
  zoom_ = kZoom;

  UpdateVectors();
}

void Camera::UpdateVectors() {
  glm::vec3 front;
  front.x = glm::cos(glm::radians(yaw_)) * glm::cos(glm::radians(pitch_));
  front.y = glm::sin(glm::radians(pitch_));

  front.z = glm::sin(glm::radians(yaw_)) * glm::cos(glm::radians(pitch_));
  front_ = glm::normalize(front);

  right_ = glm::normalize(glm::cross(front_, world_up_));
  up_ = glm::normalize(glm::cross(right_, front_));
}
