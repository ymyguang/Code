#include<stdio.h>
#include<math.h>
int main()
{
	int N,a,b,i,j,e;
	int f=0,f1=0,f2=0;
	scanf("%d",&N);
	for(i=2;i<N;i++){
		f1=0; f2=0;
		for(j=2;j<=sqrt(i);j++)
			if(i%j==0){
				f1=1;         //Å¼Êý 
				break;
			}	               
		if(f1==0){               
			a=i;
			b=N-a;
			for(e=2;e<=sqrt(b);e++)
				if(b%e==0){
					f2=1;      //Å¼Êý 
					break;
				}
			if(f2==0){
				printf("%d = %d + %d",N,a,b);
				f = 1;
    		}
		}
		if(f==1) break;
	}
}
