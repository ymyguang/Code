#include <stdio.h>
int main() {
	int sum = 0;
	int a[10];
	for (int i = 0; i <= 9; i++) {
		scanf("%d",&a[i]);
		sum += a[i];
	}
	for (int j = 0; j <= 9; j++) {
		if (a[j]>(sum/10))
			printf ("%d ",a[j]);
	}
}


