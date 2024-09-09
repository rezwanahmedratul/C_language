#include<stdio.h>

int main()
{
   int code1,code2,unit1,unit2;
   float VALUE1,VALUE2,price1,price2;
 
   scanf("%d %d %f",&code1,&unit1,&price1);
   scanf("%d %d %f",&code2,&unit2,&price2);
 
   VALUE1=unit1*price1;
   VALUE2=unit2*price2;
   
   printf("Valor a pagar: R$ %.2lf\n",VALUE1);
   printf("Valor a pagar: R$ %.2lf\n",VALUE2);
   
   return 0;
}