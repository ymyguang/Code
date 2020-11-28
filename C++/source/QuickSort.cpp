#include <stdio.h>
int a[101], n; //定义全局变量，这两个变量需要在子函数中使用
void quicksort(int left, int right)
{
    int i, j, t, temp;
    if (left > right)
        return;

    temp = a[left]; //temp中存的就是基准数
    i = left;
    j = right;
    while (i != j)
    {
        while (a[j] >= temp && i < j)
            j--;
        while (a[i] <= temp && i < j)
            i++;
        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //最终将基准数归位
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i - 1);  //继续处理左边的，这里是一个递归的过程
    quicksort(i + 1, right); //继续处理右边的 ，这里是一个递归的过程
}
int main()
{
    int i, j, t;
    //读入数据
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    quicksort(1, n); //快速排序调用

    //输出排序后的结果
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);
    getchar();
    getchar();
    return 0;
}