#include<iostream>
#include<cstdio>
using namespace std;
int t[200005],g[200005];//t��Ͱ��t[i]��ʾֵΪi�����ڼ�����������ӳ����˼��Σ�g[i]��ʾֵΪi�����Ƿ��ڼ����У�1Ϊ�ڣ�0Ϊ����
int n,a[105],ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];//����
        g[a[i]]=1;//�ڼ����и�ֵΪ1
    }
    for (int i=1;i<n;i++){//ö��
        for (int j=i+1;j<=n;j++){
            t[a[i]+a[j]]++;//���ӳ�����
        }
    }
    for (int i=1;i<=200002;i++){
        if (t[i]>0&&g[i]) ans++;//�ж��Ƿ����㣬����ans++
    }
    cout<<ans<<endl;
    return 0;
}
