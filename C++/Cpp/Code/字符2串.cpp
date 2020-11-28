#include <stdio.h>
int n;
int a, b;
char input[110] ;

int main() {
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
    	scanf("%d%d",&a,&b);
    	scanf("%s",&input);
        for (int i = a; input[i] && i <= b; i++) {
           	 printf("%d",input[i]);
        }
    }
    return 0;
}

