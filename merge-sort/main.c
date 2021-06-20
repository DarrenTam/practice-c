#include <stdio.h>

void merge(int numbers[], int low, int mid, int high) {
    int temp[high - low - 1];
    int left_count = low;
    int right_count = mid + 1;
    int temp_count = 0;

    while (right_count <= high && left_count <= mid) {
        if (numbers[left_count] > numbers[right_count]) {
            temp[temp_count] = numbers[right_count];
            temp_count++;
            right_count++;
        } else {
            temp[temp_count] = numbers[left_count];
            temp_count++;
            left_count++;
        }
    }

    while (left_count <= mid) {
        temp[temp_count] = numbers[left_count];
        temp_count++;
        left_count++;
    }

    while (right_count <= high) {
        temp[temp_count] = numbers[right_count];
        temp_count++;
        right_count++;
    }

    temp_count--;
    while (temp_count >= 0) {
        numbers[low+temp_count] = temp[temp_count];
        temp_count--;
    }
}

void merge_sort(int numbers[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        merge_sort(numbers, low, mid);
        merge_sort(numbers, mid + 1, high);
        merge(numbers, low, mid, high);
    }
}

int main() {
    int numbers[9] = {4, 65, 2, -31, 0, 99, 2, 83, 782};
    merge_sort(numbers, 0, 9);
    int loop;
    for (loop = 0; loop < 9; loop++)
        printf("%d ", numbers[loop]);
    return 0;
}
