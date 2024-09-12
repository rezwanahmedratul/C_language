#include<stdio.h>

int main()
{
    double a,b,c;
    int x;
    scanf("%lf %lf %lf",&a,&b,&c);
    
    if(a>b && a>c)
       {
         x=1;
       }
    else if(b>c && b>a)
       {
         x=2;
       }
    else if(c>a && c>b)
       {
         x=3;
       }
       
    switch(x)
       {
         case 1:
             if((b+c)>a)
               {
                 printf("Perimetro = %.1lf\n",a+b+c);
               }
             else
               {
                 printf("Area = %.1lf\n",(c*(a+b))/2);
               } 
               
             break;
          
         case 2:
             if((a+c)>b)
               {
                 printf("Perimetro = %.1lf\n",a+b+c);
               }
             else
               {
                 printf("Area = %.1lf\n",(c*(a+b))/2);
               } 
               
             break;
         
         case 3:
             if((a+c)>c)
               {
                 printf("Perimetro = %.1lf\n",a+b+c);
               }
             else
               {
                 printf("Area = %.1lf\n",(c*(a+b))/2);
               } 
               
             break;     
         
       }
    
    return 0;
}
