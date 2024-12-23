#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Windowing/windowing.h"
#include <stdio.h>
#include <stdbool.h>

int windowInitialize(Window* wind) {
    //initialize glfw and set window hints before creating the window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, wind->glVersionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, wind->glVersionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, wind->glProfile);

    wind->windowPtr = glfwCreateWindow(wind->width, wind->height, wind->title, NULL, NULL);
    if (wind->windowPtr == NULL) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(wind->windowPtr);
    glfwSwapInterval(0);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize glad\n");
        glfwTerminate();
        return -1;
    }

    glViewport(0, 0, wind->width, wind->height);
    glfwSetFramebufferSizeCallback(wind->windowPtr, wind->frame_buffer_callback_pointer);

    return 0;
}