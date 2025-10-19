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
        for(i=0;i<nofc;i++)
            sub[i] = str[st+i];
    }
    sub[i] = '\0';
    return sub;
}

int Indexing(char *T,char *P)
{
    int L, K, Max, R, S, Index = -1;
    R = Strlen(P);    S = Strlen(T);
    K = 0; Max = S - R;
    while(K<=Max)
    {
        for(L=0;L<R;L++)
            if(P[L] != T[K+L]) goto S5;
        Index = K; return Index;
        S5: K = K + 1;
    }
    return Index;
}

char *Concatenation(char *st1,char *st2)
{
    int i,j,L1 = Strlen(st1);
    int L2 = Strlen(st2);
    char *con = malloc(L1+L2);
    for(i=0;i<L1;i++)
        con[i] = st1[i];
    for(i=0;i<L2;i++)
        con[L1+i] = st2[i];
    con[L1+i] = '\0';
    return con;
}

void main()
{
    char op;
    int st, nofc, Loc;
    char Str1[10],Str2[100];
    while(1)
    {
        printf("\n1. Input a String\n");
        printf("2. Length of the String\n");
        printf("3. Display the String\n");
        printf("4. Sub-string of the String\n");
        printf("5. Concatenation of two String\n");
        printf("6. Indexing of a Sub String\n");
        printf("7. Insertion of a String\n");
        printf("8. Deletion of a Sub String\n");
        printf("9. Replacing of a Sub String\n");
        printf("A. Delete All Pattern\n");
        printf("B. Replace All Pattern\n");
        printf("0. Exit\nEnter your option : ");
        op = toupper(getche());
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
            printf("\nEnter the starting : ");
            scanf("%d",&st);
            printf("\nEnter the No of Character : ");
            scanf("%d",&nofc);
            printf("\nSub String is\n");
            puts(SubString(Str1,st,nofc));
            break;
        case '5':
            printf("\nEnter second string\n");
            gets(Str2);
            printf("\nConcatenation String is\n");
            puts(Concatenation(Str1,Str2));
            break;
        case '6':
            printf("\nEnter Pattern String\n");
            gets(Str2);
            Loc = Indexing(Str1,Str2);
            if(Loc == -1)
                printf("\nPattern Not Found\n");
            else
                printf("\nPattern Found in Location %d\n",Loc);
            break;
        case '7':
            printf("\nEnter Pattern \n");
            gets(Str2);
            printf("\nEnter Location : ");
            scanf("%d",&Loc);
            printf("\nThe Inserting String is\n");
            puts(Insertion(Str1,Loc,Str2));
            break;
        case 'A':
            printf("\nGorar Dim\n");
            break;
        case '0':
            exit(0);
            break;
        }
    }
}
