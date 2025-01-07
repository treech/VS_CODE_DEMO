using namespace std;

#include <iostream>
#include "ArrayUtil.h"

void msort(int *arr, int *tempArr, int left, int right);

void printArr(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void merge(int *arr, int *tempArr, int left, int mid, int right) {
    // 左半区第一个未排序的元素
    int l_pos = left;
    // 右半区第一个未排序的元素
    int r_pos = mid + 1;
    // 临时数组元素的下标
    int pos = left;

    // 合并
    while (l_pos <= mid && r_pos <= right) {
        if (arr[l_pos] < arr[r_pos]) {  // 左半区第一个剩余元素更小
            tempArr[pos++] = arr[l_pos++];
        } else {                        // 右半区第一个剩余元素更小
            tempArr[pos++] = arr[r_pos++];
        }
    }

    // 合并左半区剩余的元素
    while (l_pos <= mid) {
        tempArr[pos++] = arr[l_pos++];
    }

    // 合并右半区剩余的元素
    while (r_pos <= right) {
        tempArr[pos++] = arr[r_pos++];
    }

    // 把合并后的临时数组放回原数组
    while (left <= right) {
        arr[left] = tempArr[left];
        left++;
    }
}

void msort(int *arr, int *tempArr, int left, int right) {
    // 只有一个元素的区域，不需要进行归并，本身就是有序的
    if (left >= right)return;
    // 找中间点
    int mid = (left + right) >> 1;
    // 递归划分左半区
    msort(arr, tempArr, left, mid);
    // 递归划分右半区
    msort(arr, tempArr, mid + 1, right);
    // 合并已经排序的部分
    merge(arr, tempArr, left, mid, right);
}

void mergeSort(int arr[], int len) {
    int *tempArr = (int *) malloc(sizeof(int) * len);
    if (tempArr) {
        msort(arr, tempArr, 0, len - 1);
        free(tempArr);
    } else {
        printf("malloc array memory error");
    }
}

int main() {
    int arr[] = {9, 5, 2, 7, 12, 4, 3, 1, 11};
    int len = 9;
    printArr(arr, len);
    mergeSort(arr,len);
    printArr(arr, len);
    return 0;
}
