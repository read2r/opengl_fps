#ifndef __SHADER_H__
#define __SHADER_H__

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    void use();
    unsigned int getID();
private:
    unsigned int ID;
};

#endif //__SHADER_H__