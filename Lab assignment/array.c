#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Linear(int *,int,int);
void Insert(int *,int *,int,int);
void main()
{
    int i,n,loc,item, Data[10000];
    srand(time(NULL));
    char op;
    while(1)
    {
        printf("\n1. Create an Array\n");
        printf("2. Display the Array\n");
        printf("3. Search an item from the Array(Linear Search)\n");
        printf("4. Search an item from the Array(Binary Search)\n");
        printf("5. Insert an item into the Array\n");
        printf("6. Delete an item from the Array\n");
        printf("7. Sorting Using Bubble Sort\n");
        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("\nEnter the amount of numbers: ");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                Data[i] = (rand() %1000);
            }
            break;
        case '2':
            printf("\nThe %d Numbers are as follows:\n",n);
            for(i=0;i<n;i++)
            {
                printf("%5d",Data[i]);
            }
            break;
        case '3':
            printf("\nEnter the item for linear search : ");
            scanf("%d",&item);
            loc = Linear(Data,n,item);
            if(loc == -1)
                printf("\nItem not Found\n");
            else
                printf("\nItem Found in Location %d\n",loc);
            break;
        case '5':
            printf("\nEnter the Item to insert : ");
            scanf("%d",&item);
            printf("\nEnter the Location to Insert the Item : ");
            scanf("%d",&loc);
            Insert(Data,&n,loc,item);

            break;
        case '0':
            exit(0);
            break;
        }
    }
}

int Linear(int *Data,int N,int Item)
{
    int i;
    for(i=0;i<N;i++)
    {
        if(Data[i] == Item)
            return i;
    }
    return -1;
}

void Insert(int *LA,int *N,int K,int Item)
{
    int J = *N;
    while(J>K)
    {
        LA[J+1] = LA[J];
        J=J-1;
    }
    LA[K] = Item;
    *N = *N+1;
}
