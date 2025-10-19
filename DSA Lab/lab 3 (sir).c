#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Linear(int *,int,int);
void BubbleSort(int *,int);
int BinarySearch(int *,int,int,int);
int lc = 0;
int bc = 0;
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
                printf("\nItem Found in Location %d, Total Compare %d\n",loc,lc);
            break;
        case '4':
            printf("\nEnter the item for Binary search : ");
            scanf("%d",&item);
            loc = BinarySearch(Data,0,n-1,item);
            if(loc == -1)
                printf("\nItem not Found\n");
            else
                printf("\nItem Found in Location %d, Total Compare %d\n",loc,bc);
            break;
        case '7':
            BubbleSort(Data,n);
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
        lc++;
        if(Data[i] == Item)
            return i;
    }
    return -1;
}

void BubbleSort(int *LA,int N)
{
    int i,j,temp;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(LA[i] > LA[j])
            {
                temp = LA[i];
                LA[i] = LA[j];
                LA[j] = temp;
            }
        }
    }
}

int BinarySearch(int *Data,int LB,int UB,int Item)
{
    int Beg,End,Mid,Loc;
    Beg = LB; End = UB; Mid = (int)((Beg+End)/2);
    while((Beg <= End) && (Data[Mid] != Item))
    {
        bc++;
        if(Item < Data[Mid])
            End = Mid - 1;
        else
            Beg = Mid + 1;
        Mid = (int)((Beg+End)/2);
    }
    bc++;
    if(Data[Mid] == Item)
        Loc = Mid;
    else
        Loc = -1;
    return Loc;
}
