#include "random"

int *create_random_array(int len, int low, int high) {
    // 用当前时间作为种子，确保随机数每次都不同
    srand(static_cast<unsigned int>(time(0)));
    int *arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % (high - low + 1) + low;
    }
    return arr;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}