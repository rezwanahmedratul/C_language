#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct S{
    int info;
    struct S *next;
};

typedef struct S STACK;

STACK *Push(STACK *, int);
int Pop(STACK **);
void main()
{
    int n,x;
    STACK *A = NULL;
    srand(time(NULL));
    char op;
    while(1)
    {
        printf("\n1. Push Operation using Linked List Stack");
        printf("\n2. Pop Operation using Linked List Stack\n");
        printf("0. Exit\nEnter your option : ");

        op = getche();
        switch(op)
        {
        case '1':
            printf("Enter the item for Push : ");
            scanf("%d",&x);
            A = Push(A,x);
            break;
        case '2':
            x = Pop(&A);
            if(x == -1)
                printf("\nStack is Empty\n");
            else
                printf("Popped item is %d",x);
            break;
        case '3':

            break;
        case '4':

            break;
        case '5':

            break;

        case '0':
            exit(0);
            break;
        }
    }
}

STACK *Push(STACK *Top, int item)
{
    STACK *New;
    if(Top == NULL)
    {
        Top = (STACK *)malloc(sizeof(STACK));
        Top->info = item;
        Top->next = NULL;
    }
    else
    {
        New = (STACK *)malloc(sizeof(STACK));
        New->info = item;
        New->next = Top;
        Top = New;
    }
    return Top;
}

int Pop(STACK **Top)
{
    int item;
    if((*Top) != NULL)
    {
        item = (*Top)->info;
        (*Top) = (*Top)->next;
    }
    else
        item = -1;
    return item;
}
