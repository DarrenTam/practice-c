//
// Created by Darren on 06/20/2021.
//
#include <stdlib.h>
#include <printf.h>
#include <string.h>

Vector *new_vector(int capacity) {
    Vector *arr = malloc(sizeof(struct Vector));
    arr->size = 0;
    arr->capacity = capacity;
    arr->data = (int *) malloc(sizeof(int) * capacity);
    return arr;
}

void vector_destroy(Vector *vector_pointer) {
    free(vector_pointer);
    free(vector_pointer->data);
}

int size(Vector *vector_pointer) {
    return vector_pointer->size;
}

void insert(Vector *vector_pointer, int item, int index) {
    if (vector_pointer->size + 1 > vector_pointer->capacity) {
        upsize(vector_pointer);
    }
    memmove(vector_pointer->data + index + 1, vector_pointer->data + index,
            (vector_pointer->size - index) * sizeof(int));
    vector_pointer->data[index] = item;
    vector_pointer->size++;

}

bool is_empty(Vector *vector_pointer) {
    return vector_pointer->size == 0;
}

int get_by_index(Vector *vector_pointer, int index) {
    return vector_pointer->data[index];
}

void push(Vector *vector_pointer, int item) {
    if (vector_pointer->size + 1 > vector_pointer->capacity) {
        upsize(vector_pointer);
    }
    vector_pointer->data[capacity(vector_pointer)] = item;
    vector_pointer->size++;
}

void prepend(Vector *vector_pointer, int item) {
    vector_pointer->data[0] = item;
    vector_pointer->size++;
}

int find(Vector *vector_pointer, int item) {
    int result = 0;
    for (int i = 0; i < vector_pointer->size; ++i) {
        if (vector_pointer->data[i] == item) {
            result = i;
        }
    }
    return result;
}

void remove_item(Vector *vector_pointer, int item) {
    if (vector_pointer->size - 1 < vector_pointer->capacity / 2) {
        downsize(vector_pointer);
    }

    for (int i = 0; i < vector_pointer->size; ++i) {
        if (vector_pointer->data[i] == item) {
            delete(vector_pointer, i);
        }
    }
}

void delete(Vector *vector_pointer, int index) {
    if (vector_pointer->size - 1 < vector_pointer->capacity / 2) {
        downsize(vector_pointer);
    }
    memmove(vector_pointer->data + index, vector_pointer->data + index + 1,
            (vector_pointer->size - index) * sizeof(int));
    vector_pointer->size--;
}

int pop(Vector *vector_pointer) {
    if (vector_pointer->size - 1 < vector_pointer->capacity / 2) {
        downsize(vector_pointer);
    }
    vector_pointer->size--;
    return vector_pointer->data[vector_pointer->size - 1];
}


void upsize(Vector *vector_pointer) {
    int new_capacity = vector_pointer->capacity * growthFactor;
    int *new_data = (int *) realloc(vector_pointer->data, sizeof(int) * new_capacity);
    vector_pointer->data = new_data;
    vector_pointer->capacity = new_capacity;
}

void downsize(Vector *vector_pointer) {
    int new_capacity = vector_pointer->capacity / growthFactor;
    int *new_data = (int *) realloc(vector_pointer->data, sizeof(int) * new_capacity);
    vector_pointer->data = new_data;
    vector_pointer->capacity = new_capacity;
}

int capacity(Vector *vector_pointer) {
    return vector_pointer->size;
}

void print(Vector *vector_pointer) {
    printf("The size of vector is  : %d\n", vector_pointer->size);
    printf("The capacity of vector is : %d\n", vector_pointer->capacity);

    printf("Items in vector:\n");
    for (int i = 0; i < vector_pointer->size; ++i) {
        printf("%d: %d\n", i, *(vector_pointer->data + i));
    }
}




