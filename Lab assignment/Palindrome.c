#include <stdio.h>

int main()
{
    char a[30],b[30];
    int length,count=0;
    printf("Enter a word = ");
    scanf("%s",a);
    for(length=0;a[length]!='\0';length++);
    
    for(int i=0,j=length-1;i<length;i++,j--)
        b[j]=a[i];
    
    for(int i=0;i<length;i++)
        if(a[i]==b[i])
            count++;
   
    if(count==length)
        printf("Yes, This word is a Palindrome.\n");
    else 
        printf("No, This word isn't a Palindrome.\n");
   
    return 0;
}
