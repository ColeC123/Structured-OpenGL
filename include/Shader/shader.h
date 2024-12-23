#ifndef SHADER_H
#define SHADER_H
#include "glad/glad.h"

typedef struct Shader {
    char* path; //The path to the file containing the shader code
    unsigned int shaderID; //The identifier for this shader for use with opengl functions
} Shader;

typedef struct ShaderProgram {
    unsigned int programID; //The identifier for the shader program
    // The shaders below can be null if they are not to be included in the shader program as a whole
    Shader vertex; 
    Shader tessellation;
    Shader geometry;
    Shader fragment;
    Shader compute;
} ShaderProgram;

//Returns string of memory allocated on the heap, so it must be freed later by the reciever of the pointer
char* shaderFileToString(char* path);

// Creates the shader program using the data in the ShaderProgram struct
int shaderProgramCreate(ShaderProgram* program);

#endif