#include<stdio.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    
    if(a>b)
       {
          a%b ? printf("Nao sao Multiplos\n") : printf("Sao Multiplos\n");
       }
    else
       {
          b%a ? printf("Nao sao Multiplos\n") : printf("Sao Multiplos\n");
       }   
    return 0;
}
