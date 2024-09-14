#include<stdio.h>

int main()
{
   double x;
   scanf("%lf",&x);
   
    if(x>=0 && x<=100)
     {
       if(x<=25)
        {
          printf("Intervalo [0,25]\n");
          return 0;
        }
        
       if(x>25 && x<=50)
        {
          printf("Intervalo (25,50]\n");
          return 0;
        }
        
       if(x>50 && x<=75)
        {
         printf("Intervalo (50,75]\n");
         return 0;
        } 
        
       if(x>75 && x<=100)
        {
         printf("Intervalo (75,100]\n");
         return 0;
        }
     }
    else
     {
     printf("Fora de intervalo\n");
     }
   
   return 0;
}
