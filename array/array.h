//
// Created by Darren on 06/20/2021.
//

#ifndef PRACTICE_C_ARRAY_H
#define PRACTICE_C_ARRAY_H

#include <stdbool.h>
#include <assert.h>

const int growthFactor = 2;
const int shirkFactor = 2;

typedef struct Vector {
    int size;
    int capacity;
    int *data;
} Vector;

Vector *new_vector(int capacity);

void vector_destroy(Vector *vector_pointer);

int size(Vector *vector_pointer);

int capacity(Vector *vector_pointer);

bool is_empty(Vector *vector_pointer);

int get_by_index(Vector *vector_pointer, int index);

void push(Vector *vector_pointer, int item);

void insert(Vector *vector_pointer, int item, int index);

void prepend(Vector *vector_pointer, int item);

int pop(Vector *vector_pointer);

void print(Vector *vector_pointer);

void upsize(Vector *vector_pointer);

void downsize(Vector *vector_pointer);

void delete(Vector *vector_pointer, int index);

void remove_item(Vector *vector_pointer, int item);

int find(Vector *vector_pointer, int item);

#endif //PRACTICE_C_ARRAY_H
