#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const glm::vec3 positionDefault = glm::vec3(0.0f, 0.0f, 0.3f);
const glm::vec3 frontDefault = glm::vec3(0.0f, 0.0f, -1.0f);
const glm::vec3 upDefault = glm::vec3(0.0f, 1.0f, 0.0f);

const float yawDefault = -90.0f;
const float pitchDefault = 0.0f;
const float moveSpeedDefault = 2.5f;
const float mouseSensitivityDefault = 0.1f;
const float zoomDefault = 45.0;

class Camera {
public:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    
    float yaw;
    float pitch;
    float moveSpeed;
    float mouseSensitivity;
    float zoom;

Camera::Camera(glm::vec3 position = positionDefault, glm::vec3 up = upDefault,
    float yaw = yawDefault, float pitch = pitchDefault);
    //Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
    glm::mat4 getViewMatrix();
    void processKeyboard(Camera_Movement direction, float deltaTime);
    void processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
    //void processMouseScroll(float yoffset);
    
private:
    void updateCameraVectors();
};

#endif //__CAMERA_H__