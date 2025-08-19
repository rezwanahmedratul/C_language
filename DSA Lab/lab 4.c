#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

struct LinkList {
    int info;
    struct LinkList *next;
};

typedef struct LinkList LKL;

LKL *CreateList(LKL *, int);
void Traverse(LKL *);
void ListSort(LKL *);
LKL *SearchUSL(LKL *, int);
LKL *SearchSL(LKL *, int);
LKL *InputList(LKL *, int);
LKL *Insert(LKL *, int);
LKL *Delete(LKL *, int);
void FreeList(LKL *st);

int main() {
    int n;
    LKL *St = NULL, *Loc;
    srand(time(NULL));
    char option;

    while (1) {
        printf("\n1. Create a Link List Using Random Numbers\n");
        printf("2. Create a Link List Using Inputted Numbers\n");
        printf("3. Display the Linked List\n");
        printf("4. Sort the Linked List\n");
        printf("5. Search an Item from Linked List (Unsorted)\n");
        printf("6. Search an Item from Linked List (Sorted)\n");
        printf("7. Insert an Item into the Linked List\n");
        printf("8. Delete an Item from the Linked List\n");
        printf("0. Exit\nEnter your option : ");
        option = getche();

        switch (option) {
        case '1':
            St = NULL;
            printf("\nEnter amount of Node : ");
            scanf("%d", &n);
            St = CreateList(St, n);
            break;

        case '2':
            St = NULL;
            printf("\nEnter amount of Node : ");
            scanf("%d", &n);
            St = InputList(St, n);
            break;

        case '3':
            printf("\nThe Linked List is:\n");
            Traverse(St);
            break;

        case '4':
            printf("\nThe Sorted Linked List is:\n");
            ListSort(St);
            Traverse(St);
            break;

        case '5':
            printf("\nEnter the Item for search : ");
            scanf("%d", &n);
            Loc = SearchUSL(St, n);
            if (Loc == NULL)
                printf("Item is not in the list.\n");
            else
                printf("Item found at location : %p.  Item is %d\n", (void *)Loc, Loc->info);
            break;

        case '6':
            printf("\nEnter the Item for search : ");
            scanf("%d", &n);
            Loc = SearchSL(St, n);
            if (Loc == NULL)
                printf("Item is not in the list.\n");
            else
                printf("Item found at location : %p.  Item is %d\n", (void *)Loc, Loc->info);
            break;

        case '7':
            printf("\nEnter the value you want to insert : ");
            scanf("%d", &n);
            St = Insert(St, n);
            printf("\n%d has been inserted into the list\n", n);
            Traverse(St);
            break;

        case '8':
            printf("\nEnter the item you want to delete : ");
            scanf("%d", &n);
            St = Delete(St, n);
            Traverse(St);
            break;

        case '0':
            FreeList(St);
            exit(0);
            break;
        }
    }
    return 0;
}

LKL *CreateList(LKL *st, int n) {
    LKL *i = NULL, *tmp;
    while (n--) {
        tmp = (LKL *)malloc(sizeof(LKL));
        tmp->info = (rand() % 1000) + 1;
        tmp->next = NULL;

        if (st == NULL) {
            st = tmp;
            i = st;
        } else {
            i->next = tmp;
            i = tmp;
        }
    }
    return st;
}

LKL *InputList(LKL *st, int n) {
    LKL *i = NULL, *tmp;
    printf("Enter %d numbers separated by space:\n", n);
    while (n--) {
        tmp = (LKL *)malloc(sizeof(LKL));
        scanf("%d", &tmp->info);
        tmp->next = NULL;

        if (st == NULL) {
            st = tmp;
            i = st;
        } else {
            i->next = tmp;
            i = tmp;
        }
    }
    return st;
}

void Traverse(LKL *st) {
    LKL *i;
    for (i = st; i != NULL; i = i->next)
        printf("%5d", i->info);
    printf("\n");
}

void ListSort(LKL *st) {
    LKL *i, *j;
    for (i = st; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                i->info = i->info ^ j->info;
                j->info = i->info ^ j->info;
                i->info = i->info ^ j->info;
            }
        }
    }
}

LKL *SearchUSL(LKL *St, int n) {
    LKL *i;
    for (i = St; i != NULL; i = i->next) {
        if (i->info == n)
            return i;
    }
    return NULL;
}

LKL *SearchSL(LKL *St, int n) {
    LKL *i;
    for (i = St; i != NULL && i->info <= n; i = i->next) {
        if (i->info == n)
            return i;
    }
    return NULL;
}

LKL *Insert(LKL *st, int n) {
    LKL *tmp = (LKL *)malloc(sizeof(LKL));
    tmp->info = n;
    tmp->next = NULL;

    if (st == NULL || n < st->info) {
        tmp->next = st;
        return tmp;
    }

    LKL *i = st;
    while (i->next != NULL && i->next->info < n) {
        i = i->next;
    }

    tmp->next = i->next;
    i->next = tmp;

    return st;
}

LKL *Delete(LKL *st, int n) {
    if (st == NULL) {
        printf("List is empty.\n");
        return st;
    }

    LKL *tmp, *prev;

    if (st->info == n) {
        tmp = st;
        st = st->next;
        free(tmp);
        return st;
    }

    prev = st;
    tmp = st->next;
    while (tmp != NULL && tmp->info != n) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        printf("Item not found in list.\n");
        return st;
    }

    prev->next = tmp->next;
    free(tmp);

    return st;
}

void FreeList(LKL *st) {
    LKL *tmp;
    while (st != NULL) {
        tmp = st;
        st = st->next;
        free(tmp);
    }
}
