#include<stdio.h>

int main()
{
    int x=1,i=0;
    double a,b,c;
    
    do
    {
      while(i<=1 && x==1) 
       {
        scanf("%lf",&c);
        if(c>=1 && c<=10)
         {
           if(i==0)
             {
               a=c;
               i++;
             }  
           else if(i==1)
             {
               b=c;
               i++;
             }  
            
         }
        
        else
          printf("nota invalida\n"); 
       }
       
      if(i==2 && x==1)
       {    
         printf("media = %.2lf\n",(a+b)/2.0);
         i=0; 
       }

      do
       {
         printf("novo calculo (1-sim 2-nao)\n");
         scanf("%d",&x); 
         
         if(x==1)
           break;
         else if(x==2)  
           exit(0);
         else
           continue;
       } while(x!=1);   
      
    }while(x==1);
  
    return 0;
}
