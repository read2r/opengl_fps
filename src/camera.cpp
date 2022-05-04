#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : front(frontDefault), moveSpeed(moveSpeedDefault), zoom(zoomDefault),
    position(position), worldUp(up), yaw(yaw), pitch(pitch), mouseSensitivity(mouseSensitivityDefault)
{
    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, position + front, up);
}

void Camera::processKeyboard(Camera_Movement direction, float deltaTime) {
    float velocity = moveSpeed * deltaTime;
    glm::vec moveFront = glm::normalize(glm::cross(worldUp, right));
    if(direction == FORWARD) {
        position += moveFront * velocity;
    }
    if(direction == BACKWARD) {
        position -= moveFront * velocity;
    }
    if(direction == LEFT) {
        position -= right * velocity;
    }
    if(direction == RIGHT) {
        position += right * velocity;
    }
}

void Camera::processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch) {
    xoffset *= mouseSensitivity;
    yoffset *= mouseSensitivity;

    yaw += xoffset;
    pitch += yoffset;
    
    if(constrainPitch) {
        if(pitch > 89.0f) {
            pitch = 89.0f;
        }
        if(pitch < -89.0f) {
            pitch = -89.0f;
        }
    }

    updateCameraVectors();
}

void Camera::updateCameraVectors() {
    glm::vec3 curFront;
    curFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    curFront.y = sin(glm::radians(pitch));
    curFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(curFront);
    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}