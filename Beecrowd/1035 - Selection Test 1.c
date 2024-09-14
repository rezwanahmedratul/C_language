#include<stdio.h>

int main()
{
   int A,B,C,D,m,n,o,p,q,r,T;
   scanf("%d %d %d %d",&A,&B,&C,&D); 
   m=B>C;
   n=D>A;
   o=(C+D)>(A+B);
   p=C>0;
   q=D>0;
   r=((A%2)==0);
   T=m+n+o+p+q+r;
   if(T==6)
    {
      printf("Valores aceitos\n");
    }
    else
    {
      printf("Valores nao aceitos\n");
    }
   return 0;
}
