#include<stdio.h>
#include<string.h>

int led(char x)
{
  switch (x)
  {
    case '1':
       return(2);
    
    case '2':
       return(5);
    
    case '3':
       return(5);
    
    case '4':
       return(4);
    
    case '5':
       return(5);
    
    case '6':
       return(6);
    
    case '7':
       return(3);
    
    case '8':
       return(7);
       
    case '9':
       return(6);
    
    case '0':
       return(6);
          
  }
}


int main()
{
    int n,L,x,i,p;
    char X[20000];
    
    scanf("%d",&i);
    
    
    for(n=1;n<=i;n++)
      {
        getchar();
        fgets(X,20000,stdin);
        x=strlen(X)-2;
       
        for(L=0,p=0;p<=x;p++)
          L+=led(X[p]);
      
        printf("%d\n",L);
      }
    return 0;
}
    
