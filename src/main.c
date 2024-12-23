#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <stdlib.h>
#include "Shader/shader.h"
#include "Windowing/windowing.h"
#include <stdbool.h>
#include "ObjectData/ObjectData.h"
#include "Buffers/buffers.h"

// Below is the current compilation script to output to the build folder
// cl main.c Shader\shader.c Windowing\windowing.c Buffers\buffers.c ObjectData\ObjectData.c /I "C:\OpenGL Libraries\Include" /I "..\include" /Fo: "..\build\" /Fe: "..\build\" /link /subsystem:console /nodefaultlib "..\build\glad.obj" "C:\OpenGL Libraries\Libs\glfw3.lib" kernel32.lib gdi32.lib shell32.lib ucrt.lib user32.lib vcruntime.lib msvcrt.lib

static Window window1; 

void frame_buffer_size_callback(GLFWwindow* wind, int width, int height);

int main(int argc, char** argv) {    
    window1 = (Window) {
        .title = "OpenGL Structured",
        .width = 800,
        .height = 600,
        .glVersionMajor = 4,
        .glVersionMinor = 6,
        .glProfile = GLFW_OPENGL_CORE_PROFILE,
        .windowPtr = NULL,
        .frame_buffer_callback_pointer = frame_buffer_size_callback
    };

    windowInitialize(&window1);

    ShaderProgram shaderProgram;
    shaderProgram.vertex.path = "C:\\Users\\colec\\C Programs\\OpenGL-Structured\\src\\vert.glsl";
    shaderProgram.fragment.path = "C:\\Users\\colec\\C Programs\\OpenGL-Structured\\src\\frag.glsl";

    shaderProgramCreate(&shaderProgram);

    float vertices[] = {
        //top left
        -1.0f, 1.0f, 0.0f,
        //bottom left
        -1.0f, -1.0f, 0.0f,
        //top right
        1.0f, 1.0f, 0.0f, 
        //bottom right
        1.0f, -1.0f, 0.0f
    };

    unsigned int indices[] = {
        //left triangle
        3, 1, 0,
        //right triangle
        3, 0, 2
    };

    ObjectData object;
    objectDataInit(&object);

    for (int i = 0; i < sizeof(vertices) / sizeof(float); i++) {
        floatVectorAppend(&object.vertices, vertices[i]);
    }

    for (int i = 0; i < object.vertices.size; i++) {
        object.vertices.buff[i] *= 0.5f;
    }

    for (int i = 0; i < sizeof(indices) / sizeof(unsigned int); i++) {
        uintVectorAppend(&object.indices, indices[i]);
    }

    objectDataBind(&object);
    objectDataSetBuffers(&object);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glUseProgram(shaderProgram.programID);

    while(!glfwWindowShouldClose(window1.windowPtr)) {
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        if (glfwGetKey(window1.windowPtr, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window1.windowPtr, true);
        }

        glDrawElements(GL_TRIANGLES, object.indices.size, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window1.windowPtr);
        glfwPollEvents();
    }

    objectDataDestroy(&object);

    glfwTerminate();
    return 0;
}

void frame_buffer_size_callback(GLFWwindow* wind, int width, int height) {
    glViewport(0, 0, width, height);
    window1.width = width;
    window1.height = height;
}