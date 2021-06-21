#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "array.c"

int main() {
    Vector* array = new_vector(16);
    print(array);
    for (int i = 0; i < 31 ; ++i) {
        push(array,i);
    }
    print(array);
    for (int i = 0; i < 31 ; ++i) {
        insert(array,i,18);
    }
    print(array);
    for (int i = 0; i < 31 ; ++i) {
        pop(array);
    }
    print(array);
    delete(array,19);
    print(array);
    push(array,14);
    find(array,14);
    print(array);
    remove_item(array,14);
    print(array);
    vector_destroy(array);
    return 0;
}
