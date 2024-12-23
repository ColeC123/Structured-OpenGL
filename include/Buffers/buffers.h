#ifndef BUFFERS_H
#define BUFFERS_H

typedef struct IntVector {
    int* buff;
    unsigned int size;
    unsigned int memsize;
} IntVector;

//memsize must start out as 1 for doubling to work properly with implemenation of append function
#define DEFAULT_INTVECTOR (IntVector){.buff = NULL, .size = 0, .memsize = 1}

typedef struct FloatVector {
    float* buff;
    unsigned int size;
    unsigned int memsize;
} FloatVector;

#define DEFAULT_FLOATVECTOR (FloatVector){.buff = NULL, .size = 0, .memsize = 1}

typedef struct UIntVector {
    unsigned int* buff;
    unsigned int size;
    unsigned int memsize;
} UIntVector;

#define DEFAULT_UINTVECTOR (UIntVector){.buff = NULL, .size = 0, .memsize = 1}

int intVectorAppend(IntVector* vector, int value);

int floatVectorAppend(FloatVector* vector, float value);

int uintVectorAppend(UIntVector* vector, unsigned int value);

#endif