#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,C[10000000],max=0,maxn=0;  //������Ķ��ģ��Ҽҵ������鿪10000000��˲�俨���������ֲ���һ��������󳤶ȣ�˲����һ�ξ��õ��Ըû��ˣ�max�ǵ������ֵ��maxn���������ֵ��
    cin>>n; //����nֵ
    for(int i=1;i<n;i++)
    {
        cin>>C[i]; //��������
        if(C[i]>C[i-1]) max++; //��ʱ�����һ��������ǰһ������max+1
        else if(max>maxn) //��Ȼ�Ļ�max�͵�ͷ�ˣ��жϺ�maxn�ĸ���
        {
        maxn=max; //���max��maxn�󣬰�maxֵת��maxn������
        max=0;
        }
             else max=0; //���С�ڵ��ھ�ֱ�ӹ���
    }
    cout<<maxn+1; //����Ҳ������Ϊʲô��һ���������˼��ζ���һ���ͼƼ�����ȥ��
        return 0; //�Ұ�return return����
}
