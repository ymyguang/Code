#include <iostream>
using namespace std;

void merge(int array[], int left, int m, int right)
{
    int aux[7] = {0}; // 临时数组 （若不使用临时数组，将两个有序数组合并为一个有序数组比较麻烦）
    int i;            //第一个数组索引
    int j;            //第二个数组索引
    int k;            //临时数组索引
    i = left, j = m + 1, k = 0;
    for (; k <= right - left;) {
        if (i == m + 1){
            aux[k++] = array[j++];
            continue;
        }                                                                                                                                                                                                               if (j == right + 1)
        {
            aux[k++] = array[i++];
            continue;
        }
        if (array[i] > array[j])
            aux[k++] = array[i++];
        else
            aux[k++] = array[j++];
    }

    for (i = left, j = 0; i <= right; i++, j++)
        array[i] = aux[j];
}

void mergesort(int l, int r, int arr[])
{
    int mid = (l + r) / 2;
    if (l < r){
        mergesort(l, mid, arr);
        mergesort(mid + 1, r, arr);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int a[] = {6, 5445, 5353, 3553, 5};
    mergesort(0, 4, a);
    for (int i = 0; i <= 4; i++)
        cout << a[i] << " ";
    return 0;
}