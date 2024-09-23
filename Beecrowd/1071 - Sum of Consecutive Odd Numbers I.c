#include<stdio.h>

int main()
{
    int x,y,m=0,b,s;
    scanf("%d %d",&x,&y);
    
    b=x>y?x:y;
    s=(x+y)-b;

    while(s<b)
    {
      s++;
     
      if(s>=b)
        break; 
    
      if(s%2!=0)
       { 
         m=m+s;  
       } 
    }
    
    printf("%d\n",m);
    return 0;
}
