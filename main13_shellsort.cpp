using namespace std;

#include <iostream>
#include "ArrayUtil.h"

/**
 * 插入排序（Insertion Sort）基本思想：
 *
 * 将数组分为两个区间：左侧为有序区间，右侧为无序区间。每趟从无序区间取出一个元素，然后将其插入到有序区间的适当位置。
 */


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

void printArr(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertSort(int arr[], int len) {
    int i, j;
    for (i = 1; i < len; i++) {
        int temp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
        }
        if (i != j) {
            arr[j] = temp;
        }
    }
}

void shellSort(int arr[], int len) {
    int group_len = len / 2;
    int i, j, k;
    while (group_len > 0) {
        for (i = 0; i < group_len; i++) {//分组
            for (j = i + group_len; j < len; j += group_len) {
                int temp = arr[j];
                for (k = j; k >= group_len && arr[k - group_len] > temp; k -= group_len) {
                    arr[k] = arr[k - group_len];
                }
                arr[k] = temp;
            }
        }
        group_len /= 2;
    }
}


int main() {
    int len = 10;
    int *arr = create_random_array(len, -100, 100);
    cout << "--------------排序前---------------" << endl;
    printArr(arr, len);
    shellSort(arr, len);
    cout << "--------------排序后---------------" << endl;
    printArr(arr, len);
    delete arr;
    return 0;
}
