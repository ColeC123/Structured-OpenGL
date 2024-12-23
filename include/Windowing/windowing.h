#ifndef WINDOWING_H
#define WINDOWING_H
#include "GLFW/glfw3.h"

typedef struct Window {
    char* title; //The text that is displayed at the top of the window
    int width;
    int height;
    GLFWwindow* windowPtr; //The window pointer for use with GLFW functions, this should initially be set to NULL
    int glVersionMajor;
    int glVersionMinor;
    int glProfile;
    void (*frame_buffer_callback_pointer)(GLFWwindow*, int, int); //The function pointer to the frame buffer callback function called whenever the window is updated
} Window;

int windowInitialize(Window* wind);

#endif