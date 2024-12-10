using namespace std;

#include <iostream>
#include "ArrayUtil.h"

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * 冒泡排序
 * 比较相邻的元素，如果前一个比后一个大，交换之。
 * 第一趟排序第1个和第2个一对，比较与交换，随后第2个和第3个一对比较交换，这样直到倒数第2个和最后1个，将最大的数移动到最后一位。
 * 第二趟将第二大的数移动至倒数第二位
 */
void bubbleSort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[i]) {
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main() {
    int *arr = create_random_array(10, 20, 100);
    bubbleSort(arr, 10);
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
