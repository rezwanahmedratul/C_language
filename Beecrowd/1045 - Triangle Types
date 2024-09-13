#include<stdio.h>

int main()
{
    double x,y,z,A,B,C,m,n;
    scanf("%lf %lf %lf",&x,&y,&z);
    
    m=x>y?x:y;
    A=m>z?m:z;
    
    n=x<y?x:y;
    C=n<z?n:z;
    
    B=(x+y+z)-(A+C);
    
    if(A>=(B+C))
       {
          printf("NAO FORMA TRIANGULO\n");
       }
    else
       {
          if((A*A)==((B*B)+(C*C)))
             {
                printf("TRIANGULO RETANGULO\n");
             }
          if((A*A)>((B*B)+(C*C)))
             {
                printf("TRIANGULO OBTUSANGULO\n");
             }
          if((A*A)<((B*B)+(C*C)))
             {
                printf("TRIANGULO ACUTANGULO\n");   
             }   
          if(A==B && B==C)
             {
               printf("TRIANGULO EQUILATERO\n");
             }
          else if(A==B || B==C || A==C)
             {
               printf("TRIANGULO ISOSCELES\n");
             }       
       }
    
    return 0;
}
