#include "random"

int *create_random_array(int len, int low, int high) {
    int *arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % (high - low + 1) + low;
    }
    return arr;
}