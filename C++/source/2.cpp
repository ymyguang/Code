#include <iostream>
using namespace std;
void quicksort(int l, int r, int a[])
{
    if (l > r)
        return;
    int t;
    int i = l; // 左指针
    int j = r; // 右指针
    int X = a[l]; // 获取主值

    while (i != j)
    {
        for (; a[j] >= X && i < j; j--); //特别注意：判断关系必须是严格小于或大于
        for (; a[i] <= X && i < j; i++);// 因为需要做的是将基数大小不等的数字移到两侧。
        if (i < j){ 
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[l] = a[i];
    a[i] = X;
    quicksort(l, i - 1, a);
    quicksort(i + 1, r, a);
}
int main()
{
    int a[] = {4, 3, 2,432,223};
    quicksort(0, sizeof(a) / sizeof(int) - 1, a);
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
        cout << a[i] << " ";
    return 0;
}