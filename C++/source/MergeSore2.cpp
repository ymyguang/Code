#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int t[7] = {0};  // 临时数组 （若不使用临时数组，将两个有序数组合并为一个有序数组比较麻烦）
    int i = l;       //第一个数组索引
    int j = mid + 1; //第二个数组索引
    int k = 0;       //临时数组索引

    while (k <= r - l)
    {
        while (i <= mid && j <= r)
        {
            if (arr[i] < arr[j])
            {
                t[k++] = arr[i++];
            }
            else
                t[k++] = arr[j++];
        }
        if (i == mid + 1)
        {
            t[k++] = arr[j++];
        }
        else
            t[k++] = arr[i++];
    }

    for (i = l, j = 0; i <= r; i++, j++)
        arr[i] = t[j];
}

void mergesort(int l, int r, int arr[])
{
    int mid = (l + r) / 2;
    if (l < r)
    {
        mergesort(l, mid, arr);
        mergesort(mid + 1, r, arr);
        merge(arr, l, mid, r);
    }
}

int main()
{
    #define MAX 6
    int a[] = {9999, 6, 5445, 5353, 3553, 5, 1};
    mergesort(0, MAX, a);
    for (int i = 0; i <= MAX; i++)
        cout << a[i] << " ";
    return 0;
}