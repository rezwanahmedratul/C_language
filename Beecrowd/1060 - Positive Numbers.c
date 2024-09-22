#include<stdio.h>

int main()
{
    int p=0,i;
    double n;
    for (i=1;i<=6;i++)
      {
        scanf("%lf",&n);
        if(n>=0)
          p++;
      }
    
    printf("%d valores positivos\n",p);
    return 0;
}
