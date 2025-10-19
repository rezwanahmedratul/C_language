#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void traverse(int *a, int l);
int LinearSearch(int *a,int n,int item);
void BubbleSort(int *a,int l);
int BinarySearch(int *a,int st,int end,int item);
void insert(int *a, int *l, int item);
void delete(int *a, int *l, int item);

void main() {
    int i, n = 0, loc, item, a[10000];
    srand(time(NULL));
    char op;
    
    while(1) {
        printf("\n1. Create an Array\n");
        printf("2. Display the Array\n");
        printf("3. Search an item (Linear Search)\n");
        printf("4. Search an item (Binary Search)\n");
        printf("5. Insert an item\n");
        printf("6. Delete an item\n");
        printf("7. Sort using Bubble Sort\n");
        printf("0. Exit\nEnter your option: ");
        op = getche();
        printf("\n");
        
        switch(op) {
            case '1':
                printf("Enter the number of elements: ");
                scanf("%d", &n);
                for(i = 0; i < n; i++) {
                    a[i] = (rand() % 1000) + 1;
                }
                break;

            case '2':
                printf("The %d numbers are:\n", n);
                traverse(a, n);
                break;

            case '3':
                printf("Enter the item to search (Linear): ");
                scanf("%d", &item);
                loc = LinearSearch(a, n, item);
                if(loc == -1)
                    printf("Item not found!\n");
                else
                    printf("Item found at location %d\n", loc);
                break;

            case '4':
                printf("Enter the item to search (Binary): ");
                scanf("%d", &item);
                loc = BinarySearch(a, 0, n-1, item);
                if(loc == -1)
                    printf("Item not found!\n");
                else
                    printf("Item found at location %d\n", loc);
                break;

            case '5':
                printf("Enter the number to insert: ");
                scanf("%d", &item);
                insert(a, &n, item);
                printf("Array after inserting %d:\n", item);
                traverse(a, n);
                break;

            case '6':
                printf("Enter the number to delete: ");
                scanf("%d", &item);
                delete(a, &n, item);
                printf("Array after deleting %d:\n", item);
                traverse(a, n);
                break;

            case '7':
                BubbleSort(a, n);
                printf("Sorted array:\n");
                traverse(a, n);
                break;

            case '0':
                exit(0);
        }
    }
}

void traverse(int *a, int l) {
    for(int i = 0; i < l; i++) {
        printf("%5d", a[i]);
    }
    printf("\n");
}

int LinearSearch(int *a,int n,int item) {
    for(int i = 0; i < n; i++) {
        if(a[i] == item)
            return i;
    }
    return -1;
}

void BubbleSort(int *a,int l) {
    for(int i = 0; i < l-1; i++) {
        for(int j = 0; j < l-i-1; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int BinarySearch(int *a,int st,int end,int item) {
    while(st <= end) {
        int mid = st + (end - st)/2;
        if(item < a[mid]) end = mid - 1;
        else if(item > a[mid]) st = mid + 1;
        else return mid;
    }
    return -1;
}

void insert(int *a, int *l, int item) {
    a[*l] = item;
    (*l)++;
}

void delete(int *a, int *l, int item) {
    int i, found = 0;
    for(i = 0; i < *l; i++) {
        if(a[i] == item) {
            found = 1;
            break;
        }
    }
    if(found) {
        for(int j = i; j < *l-1; j++) {
            a[j] = a[j+1];
        }
        (*l)--;
    } else {
        printf("Item not found!\n");
    }
}
