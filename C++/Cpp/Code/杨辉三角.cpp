#include <stdio.h>
int main()
{
	int i,n,m;
	int j;
	int a[10][10];
	
	for(;scanf("%d",&m)!=EOF;){
		for(int ii = 0;ii < 10;ii++)
			for (int jj = 1;jj < 10;jj++)
				a[ii][jj] = 0;
		
		for(i=0;i<m;i++){
		    a[i][0]=1;
		    for(j=0;j<=i;j++){
			    if(j==0) 
			        a[i][j]=a[0][0];
			    else if(i>=1&&j>=1&&i!=j)  
			        a[i][j]=a[i-1][j]+a[i-1][j-1];
			    else if(j==i) 
			        a[i][j]=a[i-1][j-1];
		    }
		}
		
		for(i=0;i<m;i++)  { 
			for(j=0;j<i;j++)
			    printf("%d ",a[i][j]);	
			printf("%d",a[i][i]);
			printf("\n");
		}
	}
}

