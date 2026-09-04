#ifndef TEST_C_VECTOR_H
#define TEST_C_VECTOR_H

#include <stdlib.h>
#include <string.h>

typedef struct
{
    void* data;
    size_t size, capacity, elem_size;
} Vector;

static void vector_init(Vector* v, size_t elem_size)
{
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->elem_size = elem_size;
}

static void vector_push(Vector* v, const void* elem)
{
    if (v->size == v->capacity)
    {
        v->capacity = v->capacity ? v->capacity * 2 : 4;
        v->data = realloc(v->data, v->capacity * v->elem_size);
    }
    memcpy((char*)v->data + v->size * v->elem_size, elem, v->elem_size);
    v->size++;
}

static void* vector_get(Vector* v, size_t index)
{
    return (char*)v->data + index * v->elem_size;
}

static void vector_free(Vector* v)
{
    free(v->data);
    v->data = NULL;
    v->size = v->capacity = 0;
}

#endif //TEST_C_VECTOR_H
