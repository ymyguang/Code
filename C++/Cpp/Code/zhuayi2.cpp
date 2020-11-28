# include <cstdio>
# include <cstdlib>
//void main (void);	
int main ()
{
    int num = 100;
    char str[25];
    itoa(num, str, 1000);
    printf("The number 'num' is %d and the string 'str' is %s. \n" ,
                       num, str);
}
