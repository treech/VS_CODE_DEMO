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

void insertSort(int arr[], int len) {
    int i, j;
    for (i = 1; i < len; i++) {
        for (j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
}


int main() {
    int len = 10;
    int *arr = create_random_array(len, -30, 30);
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertSort(arr, len);
    cout<<"-----------------------------"<<endl;
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    delete arr;
    return 0;
}
