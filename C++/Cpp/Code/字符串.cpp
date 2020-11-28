#include <stdio.h>
int main()
{
	char ch[110],x;
	int N,n,m,ans;
	scanf("%d",&N);
	for (int i = 0;i < N;i++){
		ans = 0;
		scanf("%d%d",&m,&n);
		getchar();
		while (1){
			x = getchar();
			if (x == '\n'||x == '\r') break;
			else ch[ans++] = x;
		}
		if (n > ans-1) n = ans-1;
		for (int j = m; j <= n;j++){
			printf("%c",ch[j]);
		}
		printf("\n");
	}
	return 0;
 } 
