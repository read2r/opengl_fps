#ifndef __SHADER_H__
#define __SHADER_H__

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    void use();
    unsigned int getID();
    void setMat4(const char *name, const glm::mat4 value);
private:
    unsigned int ID;
};

#endif //__SHADER_H__