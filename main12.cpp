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

void printArr(int arr[], int len){
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
            swap(arr[j], arr[j - 1]);
        }
    }
}

int main() {
    int len = 10;
    int *arr = create_random_array(len, -100, 100);
    cout << "--------------排序前---------------" << endl;
    printArr(arr,len);
    insertSort(arr, len);
    cout << "--------------排序后---------------" << endl;
    printArr(arr,len);
    delete arr;
    return 0;
}
