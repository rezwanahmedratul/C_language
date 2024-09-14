#include<stdio.h>

int main()
{
    int X,Y;
    scanf("%d %d",&X,&Y);
    
    if(X==1)
      {
        printf("Total: R$ %.2lf\n",Y*4.00);
        return 0;
      }
      
    if(X==2)
      {
        printf("Total: R$ %.2lf\n",Y*4.50);
        return 0;
      }
      
    if(X==3)
      {
        printf("Total: R$ %.2lf\n",Y*5.00);
        return 0;
      }
      
    if(X==4)
      {
        printf("Total: R$ %.2lf\n",Y*2.00);
        return 0;
      }
      
    if(X==5)
      {
        printf("Total: R$ %.2lf\n",Y*1.50);
        return 0;
      }
      
    return 0;
}
