#include <iostream>

using namespace std;

/**
 * 选择排序
 * 在一个长度为 N 的无序数组中，第一次遍历 n-1 个数找到最小的和第一个数交换。
 * 第二次从下一个数开始遍历 n-2 个数，找到最小的数和第二个数交换。
 * 重复以上操作直到第 n-1 次遍历最小的数和第 n-1 个数交换，排序完成。
 * @param arr 数组
 * @param len 数组长度
 */
void selectSort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int *create_random_array(int len, int low, int high) {
    int *arr = new int[len];
    for (int i = 0; i < len; i++) {
        arr[i] = rand() % (high - low + 1) + low;
    }
    return arr;
}

int main() {
//    int arr[] = {0, -1, -2, 12,-8};
//    selectSort(arr, sizeof(arr) / sizeof(arr[0]));

    int *arr = create_random_array(10, 20, 100);
    selectSort(arr, 10);
//    for (int i = 0; i < 10; ++i) {
//        cout << arr[i] << " ";
//    }
    for (int i = 0; i < 10; ++i) {
        cout << *(arr+i) << " ";
    }

    return 0;
}
