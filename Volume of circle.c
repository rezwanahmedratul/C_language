#include<stdio.h>

int main()
{
   int R;
   double pi=3.14159,VOLUME;
 
   scanf("%d",&R);
    
   VOLUME=(4*pi*R*R*R)/3;
 
   printf("VOLUME = %.3lf\n",VOLUME);
   
   return 0;
}