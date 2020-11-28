#include<stdio.h>
int main()
{
	int N,n=0,i=1,j=1,max,maxi;
	int a[1001],b[1001] = {1};
	max=b[1];
	scanf("%d",&N);
	for(;i<=N;i++)
		scanf("%d",&a[i]);
		
	for(i=1;i<=N;i++)	           //
		for(j=i;j<=N;j++){
			if(a[j]==a[i])
				b[i]=b[i]+1;    //
			if(b[i]>max){
				max=b[i];
				maxi = i;
		}	
    }
    printf("%d %d",a[maxi],max);
}

