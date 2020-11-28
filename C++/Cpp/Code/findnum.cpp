	#include<stdio.h>
	
	int i,j,T,n,x,b;
	int a[100] = {0};
	
	int findnum(int b)
	{
		for(;b>0;b--){
		   	if(a[b]==x){
				printf("find!\n");
				break;
			}
		}
		if(b==0)
			printf("no find!");
	}
	
	int main()
	{
		scanf("%d",&T);
		for(i=1;i<=T;i++){
		 	scanf("%d",&n);
			for(j=1;j<=n;j++)
				scanf("%d",&a[j]);
		    scanf("%d",&x);
			findnum(n);
		}
	} 

