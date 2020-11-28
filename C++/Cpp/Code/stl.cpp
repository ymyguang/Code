#include<iostream>
#include<cstdio>
using namespace std;
int t[200005],g[200005];//t是桶，t[i]表示值为i的数在集合中两两相加出现了几次，g[i]表示值为i的数是否在集合中，1为在，0为不在
int n,a[105],ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];//读入
        g[a[i]]=1;//在集合中赋值为1
    }
    for (int i=1;i<n;i++){//枚举
        for (int j=i+1;j<=n;j++){
            t[a[i]+a[j]]++;//被加出来了
        }
    }
    for (int i=1;i<=200002;i++){
        if (t[i]>0&&g[i]) ans++;//判断是否满足，满足ans++
    }
    cout<<ans<<endl;
    return 0;
}
