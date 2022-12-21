#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}*LinkList;

void initList(LinkList *L);
void insertLast(LinkList *L, int elem);
void populateList(LinkList *L);
void displayList(LinkList L);

/* Main problem */
LinkList getEven(LinkList *L);

void main(){
	LinkList A, Even;
	
	initList(&A);
	printf("\nTask 1: ");
	displayList(A);
	populateList(&A);
	printf("\nTask 2: ");
	displayList(A);
	Even = getEven(&A);
	printf("\nTask 3 (Even numbers): ");
	displayList(Even);
	printf("\nTask 3 (Original List): ");
	displayList(A);
}

void initList(LinkList *L){
	*L = NULL;
}

void insertLast(LinkList *L, int elem){
	LinkList *trav;
	for(trav = L; *trav != NULL; trav = &(*trav)->link){}
	*trav = (LinkList)malloc(sizeof(struct node));
	(*trav)->data = elem;
	(*trav)->link = NULL;
}

void populateList(LinkList *L){
	insertLast(L,4);
	insertLast(L,10);
	insertLast(L,3);
	insertLast(L,6);
	insertLast(L,7);
	insertLast(L,1);
}

void displayList(LinkList L){
	LinkList trav;
	if(L == NULL){
		printf("List is empty");
	} else {
		for (trav=L; trav!=NULL; trav=trav->link){
			printf("%d ",trav->data);
		}
	}
}

LinkList getEven(LinkList* L){
	LinkList Even = NULL;
	LinkList *trav, *ptr, temp;
	ptr = &Even;
	for(trav=L; *trav!= NULL;){
		if ((*trav)->data % 2 == 0){
			temp = *trav;
			*trav = temp->link;
			*ptr = temp;
			ptr = &(*ptr)->link;
		} else {
			trav=&(*trav)->link;
		}
	}
	*ptr = NULL;
	return Even;
}
