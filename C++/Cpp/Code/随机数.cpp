#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a; 
    srand(time(NULL));
    a = rand()%2;
    if(a)
       printf("ɾ");
    else printf("��ɾ");
    return 0;
}
