#ifndef OBJECTDATA_H
#define OBJECTDATA_H
#include "Buffers/buffers.h"

typedef struct ObjectData {
    UIntVector indices;
    FloatVector vertices;
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;
} ObjectData;

int objectDataInit(ObjectData* obj);

int objectDataBind(ObjectData* obj);

int objectDataSetBuffers(ObjectData* obj);

int objectDataBuffersDelete(ObjectData* obj);

int objectDataFreeVectors(ObjectData* obj);

int objectDataDestroy(ObjectData* obj);

int objectDataUnbind(ObjectData* obj);

#endif