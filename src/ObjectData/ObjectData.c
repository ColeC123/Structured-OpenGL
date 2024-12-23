#include "ObjectData/ObjectData.h"
#include <stdio.h>
#include <stdlib.h>
#include "glad/glad.h"

int objectDataInit(ObjectData* obj) {
    glGenVertexArrays(1, &obj->vao);
    glGenBuffers(1, &obj->vbo);
    glGenBuffers(1, &obj->ebo);
    obj->vertices = DEFAULT_FLOATVECTOR;
    obj->indices = DEFAULT_UINTVECTOR;
    return 0;
}

int objectDataBind(ObjectData* obj) {
    glBindVertexArray(obj->vao);
    glBindBuffer(GL_ARRAY_BUFFER, obj->vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->ebo);
    return 0;
}

int objectDataSetBuffers(ObjectData* obj) {
    glBufferData(GL_ARRAY_BUFFER, obj->vertices.size * sizeof(float), obj->vertices.buff, GL_STATIC_DRAW); 
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, obj->indices.size * sizeof(unsigned int), obj->indices.buff, GL_STATIC_DRAW);
    return 0;
}

int objectDataBuffersDelete(ObjectData* obj) {
    glDeleteVertexArrays(1, &obj->vao);
    glDeleteBuffers(1, &obj->vbo);
    glDeleteBuffers(1, &obj->ebo);
    return 0;
}

int objectDataFreeVectors(ObjectData* obj) {
    free(obj->vertices.buff);
    obj->vertices = DEFAULT_FLOATVECTOR;
    free(obj->indices.buff);
    obj->indices = DEFAULT_UINTVECTOR;
    return 0;
}

int objectDataDestroy(ObjectData* obj) {
    objectDataBuffersDelete(obj);
    objectDataFreeVectors(obj);
    return 0;
}

int objectDataUnbind(ObjectData* obj) {
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    return 0;
}