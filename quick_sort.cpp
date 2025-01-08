using namespace std;

#include "ArrayUtil.h"

/**
 * @brief 快速排序
 *        大体思想：比pivot小的换到最前面
 *
 * @param arr 数组
 * @param low 最左边索引
 * @param high 最右边索引
 * @return int 划分位置
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {// 比pivot小的都换到前面
            swap(&arr[j], &arr[i++]);
        }
    }
    // 此时i指向的元素一定大于等于pivot
    swap(&arr[high], &arr[i]);
    return i;
}

/**
 * @brief 递归划分
 * @param arr 数组
 * @param low 左边界下标
 * @param high 右边界下标
 */
void qsort(int arr[], int low, int high) {
    if (low < high) {
        int mid = partition(arr, low, high);
        qsort(arr, low, mid - 1);
        qsort(arr, mid + 1, high);
    }
}

/**
 * @brief 快速排序入口
 * @param arr 数组
 * @param len 数组长度
 */
void quick_sort(int arr[], int len) {
    qsort(arr, 0, len - 1);
}

int main() {
//    int arr[] = {4, 2, 5, 1, 7, 6, 3};
    int len = 10;
    int *arr = create_random_array(len, 0, 20);
    printArr(arr, len);
    quick_sort(arr, len);
    printArr(arr, len);
    return 0;
}
