#include<stdio.h>

int main()
{
    int d,m,y,D,M,Y,DD,MM,YY,days;
  
    printf("Enter current date in this format DD MM YYYY.\n");
    scanf("%d %d %d",&d,&m,&y);
  
 
    if(m>12)
     {
       printf("\nOoops...Wrong Input.\nMonth cannot be greater than 12.\n");
     }
 
    else if(d>31)
     { 
       printf("\nOoops...Wrong Input.\nThere are only 30 days in a month.\n");
     }

    else
    {  
       printf("\nEnter your date of birth in this format DD MM YYYY.\n");
       scanf("%d %d %d",&D,&M,&Y);
    
       if(Y>y)
         {
            printf("\nOoops...Wrong Input.\nBirth year cannot be greater than Present year.\n");
         }
       
       else if(M>12)
         {
            printf("\nOoops...Wrong Input.\nMonth cannot be greater than 12.\n");
         }
   
       else if(D>31)
         { 
            printf("\nOoops...Wrong Input.\nThere are only 30 days in a month.\n");
         }
                  
       else
         {
            days=((y*365)+(m*30)+d)-((Y*365)+(M*30)+D);
            YY=days/365;
            MM=(days%365)/30;
            DD=(days%365)%30;
       
            printf("\nYour age is %d Years %d Months and %d Days.\n",YY,MM,DD);
         }
    }
    
    return 0;
}
