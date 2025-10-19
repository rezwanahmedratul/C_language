#include<stdio.h>
#include<stdlib.h>

int Strlen(char *str)
{
    int l = 0;
    while(str[l]) {         l++;     }
    return l;
}

char *SubString(char *str,int st, int nofc)
{
    int i=0;
    char *sub = (char *)malloc(nofc);
    if(st+nofc > Strlen(str))
    {
        sub = "";
    }
    else
    {
        while(nofc>0)
        {
            sub[i] = str[st+i];
            i++;
            nofc--;
        }

        sub[i] = '\0';
    }
    return sub;
}

char *Concate(char *str1,char *str2)
{
    int i,l1,l2;
    l1 = Strlen(str1);  l2 = Strlen(str2);
    char *cont = (char *)malloc(l1 + l2);
    for(i=0;i<l1;i++)
        cont[i] = str1[i];
    for(i=0;i<l2;i++)
        cont[l1+i] = str2[i];
    cont[l1+l2] = '\0';
    return cont;
}
int Index(char *str,char *pat)
{
    int R = Strlen(pat);
    int S = Strlen(str);
    int L, K = 0, Max = S - R + 1;
    while(K < Max)
    {
        for(L = 0; L < R; L++)
        {
            if(pat[L] != str[K + L])
                goto S5;
        }
        return K;
        S5  : K= K +1;
    }
    return -1;
}
char *Insert(char *str,int in,char *pat)
{


}
char *Replace(char *str,char *pat,char *tar)
{

}

char *Delete(char *str,int st, int nofc)
{

}


void main()
{
    char op;
    int st, nofc, Loc;
    char Str1[100],Str2[100],*Sub;
    while(1)
    {
        printf("\n1. Input a String\n");
        printf("2. Length of the String\n");
        printf("3. Display the String\n");
        printf("4. Sub-string of the String\n");
        printf("5. Concatenation of two String\n");
        printf("6. Indexing of a Pattern\n");
        printf("7. Replace of a String by another String\n");
        printf("8. Insertion of a String by a Pattern\n");
        printf("9. Delete of a String\n");
        printf("A. Replace All of a String\n");
        printf("B. Delete All of a String\n");

        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("\nEnter a line of text string:\n");
            gets(Str1);
            break;
        case '2':
            printf("\nThe length of the string is %d",Strlen(Str1));
            break;
        case '3':
            printf("\nInputted Sting is :\n");
            puts(Str1);
            break;
        case '4':
            printf("\nEnter starting : ");
            scanf("%d",&st);
            printf("\nEnter No of Character : ");
            scanf("%d",&nofc);
            Sub = SubString(Str1,st,nofc);
            printf("\nThe Substring is\n");
            puts(Sub);
            break;
        case '5':
            printf("\nEnter second string\n");
            gets(Str2);
            printf("\nThe Concatenation of Strings is\n");
            puts(Concate(Str1,Str2));
            break;
        case '6':
            printf("\nEnter Pattern string\n");
            gets(Str2);
            Loc = Index(Str1,Str2);
            if(Loc >= 0)
                printf("\nPattern Found in Location %d\n",Loc);
            else
                printf("\nPattern Not Found\n");
            break;
        case '0':
            exit(0);
            break;
        }
    }
}
