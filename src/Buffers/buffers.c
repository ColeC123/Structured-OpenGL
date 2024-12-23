#include "Buffers/buffers.h"
#include <stdlib.h>
#include <stdio.h>

int intVectorAppend(IntVector* vector, int value) {
    if (vector->buff == NULL || vector->size + 1 >= vector->memsize) {
        vector->memsize *= 2;
        int* temp = (int*)realloc(vector->buff, vector->memsize * sizeof(int));
        if (temp == NULL) {
            printf("Failed to reallocate memory for intvector\n");
            free(vector->buff);
            exit(-1);
        } else if (vector->buff != temp) {
            vector->buff = temp;
        }
        temp = NULL;
    }

    vector->buff[vector->size] = value;
    vector->size++;

    return 0;
}

int floatVectorAppend(FloatVector* vector, float value) {
    if (vector->buff == NULL || vector->size + 1 >= vector->memsize) {
        vector->memsize *= 2;
        float* temp = (float*)realloc(vector->buff, vector->memsize * sizeof(float));
        if (temp == NULL) {
            printf("Failed to reallocate memory for floatvector\n");
            free(vector->buff);
            exit(-1);
        } else if (vector->buff != temp) {
            vector->buff = temp;
        }
        temp = NULL;
    }

    vector->buff[vector->size] = value;
    vector->size++;

    return 0;
}

int uintVectorAppend(UIntVector* vector, unsigned int value) {
    if (vector->buff == NULL || vector->size + 1 >= vector->memsize) {
        vector->memsize *= 2;
        int* temp = (unsigned int*)realloc(vector->buff, vector->memsize * sizeof(unsigned int));
        if (temp == NULL) {
            printf("Failed to reallocate memory for intvector\n");
            free(vector->buff);
            exit(-1);
        } else if (vector->buff != temp) {
            vector->buff = temp;
        }
        temp = NULL;
    }

    vector->buff[vector->size] = value;
    vector->size++;

    return 0;
}