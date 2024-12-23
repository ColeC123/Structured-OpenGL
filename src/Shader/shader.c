#include "glad/glad.h"
#include "Shader/shader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* shaderFileToString(char* path) {
    char tempFileBuff[150];
    FILE* file = fopen(path, "r");

    if (file == NULL) {
        printf("Shader file does not exist or was incorrectly specified\n");
        exit(-1);
    }

    fseek(file, 0L, SEEK_END);
    int fileSize = (int)ftell(file);
    char* shaderSource = (char*)malloc(fileSize);
    fseek(file, 0L, SEEK_SET);
    int fileCount = 0;
    while (fgets(tempFileBuff, 150, file)) {
        for (int i = 0; tempFileBuff[i] != '\0' && fileCount < fileSize - 1; i++) {
            shaderSource[fileCount] = tempFileBuff[i];
            fileCount++;
        }
    }
    shaderSource[fileCount] = '\0';
    fclose(file);

    return shaderSource;
}

int shaderProgramCreate(ShaderProgram* program) {
    int success;
    char infoLog[512];

    program->programID = glCreateProgram();

    //Create and compile vertex shader
    char* shaderSource = shaderFileToString(program->vertex.path);
    program->vertex.shaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(program->vertex.shaderID, 1, &shaderSource, NULL);
    glCompileShader(program->vertex.shaderID);
    free(shaderSource);

    glGetShaderiv(program->vertex.shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(program->vertex.shaderID, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n", infoLog);
        exit(-1);
    }

    //Create and compile fragment shader
    shaderSource = shaderFileToString(program->fragment.path);
    program->fragment.shaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(program->fragment.shaderID, 1, & shaderSource, NULL);
    glCompileShader(program->fragment.shaderID);
    free(shaderSource);

    glGetShaderiv(program->fragment.shaderID, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(program->fragment.shaderID, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n", infoLog);
        exit(-1);
    }

    /*
    Implement the compilation and craeton of the other shader types later on when necessary
    */

   glAttachShader(program->programID, program->vertex.shaderID);
   glAttachShader(program->programID, program->fragment.shaderID);
   glLinkProgram(program->programID);

   glGetShaderiv(program->programID, GL_LINK_STATUS, &success);
   if (!success) {
        glGetProgramInfoLog(program->programID, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING::COMPILATION_FAILED\n%s\n", infoLog);
        exit(-1);
   }

   glDeleteShader(program->vertex.shaderID);
   glDeleteShader(program->fragment.shaderID);

   return 0;
}