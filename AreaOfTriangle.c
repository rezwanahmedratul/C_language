#include<stdio.h>

int main()
{
    float b,h,a; // b=base, h=height, a=area
    
    printf("Enter the Base of the Triangle\n");
    scanf("%f",&b);
    
    printf("Enter the Height of the Triangle\n");
    scanf("%f",&h);
    
    a=.5*b*h;
     
    printf("The area of the Triangle is %.2f square unit\n",a);
 
    return 0;
}
