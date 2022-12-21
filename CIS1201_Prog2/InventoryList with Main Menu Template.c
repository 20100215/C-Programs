#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 0XF

typedef enum
{
    HEALING,
    WEAPON,
    OTHER
} type;

typedef struct
{
    char name[20];
    type t;
    char desc[100];
    int qty;
} item;

typedef struct
{
    item i[SIZE];
    int count;
} inventoryType, List;

void initialize(List *);
void printList(List);
void printOnly(List, type);
void printPos(List, pos);
item getItemDetails();
void insertFirst(List *, item);
void insertLast(List *, item);
void insertPos(List *, item, pos);
void insertSorted(List *, item);
int find(List, char *);
int isSorted(List);
void delete (List *, item);
void deletePos(List *, pos);
void makeEmpty(List *);
void bubbleSort(List *, mode);    /*1 is ascending, -1 is descending*/
void selectionSort(List *, mode); /*1 is ascending, -1 is descending*/
void insertionSort(List *, mode); /*1 is ascending, -1 is descending*/

int main()
{

    int choice = -1;
    List bag;
    item temp;
    initialize(&bag);

    /*Main menu*/
    while (choice != 0)
    {
        system("cls");
        printf("\n=====================");
        printf("\n      MAIN MENU      ");
        printf("\n=====================");
        printf("\n");
        printf("\n [1] Insert new item (first position) ");
        printf("\n [2] Insert new item (last position) ");
        printf("\n [3] Insert new item (specified position) ");
        printf("\n [4] Insert new item (sorted position) ");
        printf("\n [5] Display list ");
        printf("\n [6] Display at position ");
        printf("\n [7] Search item ");
        printf("\n [8] Delete item ");
        printf("\n [9] Delete at position ");
        printf("\n [10] Reset list ");
        printf("\n [11] Check if list is sorted ");
        printf("\n [12] Sort list (bubble sort) ");
        printf("\n [13] Sort list (selection sort) ");
        printf("\n [14] Sort list (insertion sort) ");
        printf("\n\n [0] Exit ");
        printf("\n=====================");
        printf("\nChoice: ");
        fflush(stdin);
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            temp = getItemDetails();
            insertFirst(&bag, temp);
            break;
        case 2:
            temp = getItemDetails();
            insertLast(&bag, temp);
            break;
        case 3:
            temp = getItemDetails();
            printf("\nEnter position to insert: [1-%d]", bag.count + 1);
            insertPos(&bag, temp);
            break;
        case 4:
            temp = getItemDetails();
            if (isSorted(bag) == 1)
            {
                insertSorted(&bag, temp);
            }
            else
            {
                insertLast(&bag, temp);
            }
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        }
    }

    return 0;
}

void initialize(List *)
{
}

void printList(List)
{
}

void printOnly(List, type)
{
}
void printPos(List, pos)
{
}
item getItemDetails();
void insertFirst(List *, item);
void insertLast(List *, item);
void insertPos(List *, item, pos);
int find(List, char *);
void makeEmpty(List *);
void sort(List *, mode); /*1 is ascending, -1 is descending*/

inventoryType inventory;
