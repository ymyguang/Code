#include <iostream>
using namespace std;
void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void QuickSort(int i, int j, int arr[], int n)
{
    int mid = (i + j) / 2;
    while (1)
    {
        if (mid == 0)
        {
            break; // 左循环结束,退出本次递归调用
        }
        else if (mid == n) // 右侧序列结束，返回
        {
            return;
        }
        while (i < mid)
        {
            if (arr[i] > arr[j])
            {
                Swap(&arr[i], &arr[j]);
            }
            i++;
            j--;
        }
        QuickSort(0, mid, arr, n); // 左侧
    }
    QuickSort(n / 2, n, arr, n); // 右侧
    return;
}

int main()
{
    int a[] = { 8, 9, 1 };
    int len = sizeof(a) / sizeof(int);
    QuickSort(0, len - 1, a, len - 1);
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}