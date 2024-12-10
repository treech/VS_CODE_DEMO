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
    int n = len;
    int newn;
    do {
        newn = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i], arr[i - 1]);
                //记录最后一次交换的位置
                newn = i;
            }
        }
        n = newn;
        cout << "newn:" << newn << endl;
    } while (n > 0);
}

int main() {
    int len = 50;
    int *arr = create_random_array(len, 10, 1000);
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    bubbleSort(arr, len);
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    delete arr;
    return 0;
}
