#include<stdio.h>

int main()
{
    double s;
    scanf("%lf",&s);
    
   if (s<=2000 && s>=0)
        printf("Isento\n");
   
   else if (s>2000 && s<=3000)
        printf("R$ %.2lf\n",((s-2000)*.08));
        
   else if (s>3000 && s<=4500)
        printf("R$ %.2lf\n",((1000*.08)+((s-3000)*.18)));
        
   else if (s>4500)
        printf("R$ %.2lf\n",((1000*.08)+(1500*.18)+((s-4500)*.28)));     
   
    return 0;
}
