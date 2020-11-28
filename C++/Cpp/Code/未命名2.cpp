#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,C[10000000],max=0,maxn=0;  //这里真的恶心，我家电脑数组开10000000会瞬间卡死，害我又查了一下数组最大长度，瞬间又一次觉得电脑该换了；max是单次最大值，maxn是永久最大值。
    cin>>n; //输入n值
    for(int i=1;i<n;i++)
    {
        cin>>C[i]; //输入数组
        if(C[i]>C[i-1]) max++; //此时如果这一个数大于前一个数，max+1
        else if(max>maxn) //不然的话max就到头了，判断和maxn哪个大
        {
        maxn=max; //如果max比maxn大，把max值转入maxn并归零
        max=0;
        }
             else max=0; //如果小于等于就直接归零
    }
    cout<<maxn+1; //这里也别问我为什么加一。。。试了几次都少一，就计几补上去了
        return 0; //我爱return return爱我
}
