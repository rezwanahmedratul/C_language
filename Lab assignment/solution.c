#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct L{
    int info;
    struct L *next;
};

typedef struct L LinkList;

LinkList *CreateList(LinkList *,int);
void Traverse(LinkList *);
void ListSort(LinkList *);
LinkList *SearchUSL(LinkList *S, int);
LinkList *SearchSL(LinkList *, int);

void main()
{
    int nofn,Item;
    LinkList *Start,*Loc;
    srand(time(NULL));
    char op;
    while(1)
    {
        printf("\n1. Create a Link List Using Random Numbers\n");
        printf("2. Create a Link List Using Inputted Numbers\n");
        printf("3. Display the Linked List\n");
        printf("4. Sort the Linked List\n");
        printf("5. Search an Item from Linked List (Unsorted)\n");
        printf("6. Search an Item from Linked List (Sorted)\n");
        printf("7. Insert an Item into the Linked List\n");
        printf("8. Delete an Item from the Linked List\n");
        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            Start = NULL;
            printf("\nEnter amount of Node : ");
            scanf("%d",&nofn);
            Start = CreateList(Start,nofn);
            break;
        case '2':

            break;
        case '3':
            printf("\nThe Linked List is\n");
            Traverse(Start);
            break;
        case '4':
            printf("\nThe Sorted Linked List is\n");
            ListSort(Start);
            Traverse(Start);
            break;

        case '5':
            printf("\nEnter the Item for search : ");
            scanf("%d",&Item);
            Loc=SearchUSL(Start,Item);
            if(Loc==NULL) printf("Item is not in the list.\n");
            else printf("Item found at location : %d.  Item is %d\n",Loc,Loc->info);
            break;

        case '6':
            printf("\nEnter the Item for search : ");
            scanf("%d",&Item);
            Loc=SearchUSL(Start,Item);
            if(Loc==NULL) printf("Item is not in the list.\n");
            else printf("Item found at location : %d.  Item is %d\n",Loc,Loc->info);
            break;
        case '0':
            exit(0);
            break;
        }
    }
}

LinkList *CreateList(LinkList *List,int nofn)
{
    int item;
    LinkList *Ptr;
    while(nofn)
    {
        item = (rand() % 1000) + 1;
        if(List == NULL)
        {
            List = (LinkList *)malloc(sizeof(LinkList));
            List->info = item;
            List->next = NULL;
            Ptr = List;
        }
        else
        {
            Ptr->next = (LinkList *)malloc(sizeof(LinkList));
            Ptr = Ptr->next;
            Ptr->info = item;
            Ptr->next = NULL;
        }
        nofn--;
    }
    return List;
}
void Traverse(LinkList *List)
{
    LinkList *Ptr;
    Ptr = List;
    while(Ptr != NULL)
    {
        printf("%5d",Ptr->info);
        Ptr = Ptr->next;
    }
}
void ListSort(LinkList *List)
{
    int temp;
    LinkList *iPtr,*jPtr;
    iPtr = List;
    while(iPtr != NULL)
    {
        jPtr = iPtr->next;
        while(jPtr != NULL)
        {
            if(iPtr->info > jPtr->info)
            {
                temp = iPtr->info;
                iPtr->info = jPtr->info;
                jPtr->info = temp;
            }
            jPtr = jPtr->next;
        }
        iPtr = iPtr->next;
    }
}


LinkList *SearchUSL(LinkList *Start, int Item){
    LinkList *i;
    for(i=Start;i->next!=NULL;i=i->next){
        if (i->info == Item) return i;
    }
    return NULL;
}

LinkList *SearchSL(LinkList *Start, int Item){
    LinkList *i;
    for(i=Start;i->next!=NULL && i->info <= Item;i=i->next){
        if (i->info == Item) return i;
    }
    return i;
}
