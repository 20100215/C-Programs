#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}*List;

void insertFirst (List*A, int elem);
void insertSorted (List*A, int elem);
void displayList(List A);
void deletePos(List *A, int pos);
List createEven(List A);


void main(){
	List L = NULL;
	insertFirst(&L,20);
	insertFirst(&L,10);
	insertFirst(&L,6);
	insertFirst(&L,5);
	printf("Before: ");
	displayList(L);
	
	deletePos(&L,2);
	printf("\nAfter: ");
	displayList(L);
}

void insertFirst (List *A, int elem){
   List temp = (List) malloc (sizeof(struct node));
   temp->data = elem;
   temp->link = *A;
   *A = temp;
}

void insertSorted (List *A, int elem){
   List* trav;
   List temp;
   for(trav = A; *trav != NULL && (*trav)->data < elem ; trav = &(*trav)->link ){}
   /* insertion */
   temp = (List) malloc (sizeof(struct node));
   temp->data = elem;
   temp->link = *trav;
   *trav = temp;
}

void displayList(List A){
	List temp;
    for(temp=A;temp!=NULL;temp=temp->link){
		printf("%d ",temp->data);
	}
}

void deletePos(List *A, int pos){
   List *trav;
   List temp;
   int ctr=1;
   for(trav = A; *trav!=NULL && ctr<pos; trav = &(*trav)->link, ctr++){}
   temp = *trav;
   *trav = temp->link;
   free(temp);
}

List createEven(List A){
	List travOld; /* used to traverse through given list */
	List* travNew; /* used to traverse through new list */
	List temp; /* used during the insertion process */
	List newList = NULL; /* the list to be returned – initialize to NULL */
	
	for(travOld=A; travOld!=NULL; travOld=travOld->link){
		if (travOld->data % 2 == 0) {
			for(travNew=&newList; *travNew!=NULL && (*travNew)->data < travOld->data ; travNew=&(*travNew)->link){}
			temp = (List) malloc (sizeof(struct node));
			temp->data = travOld->data;
			temp->link = *travNew;
			*travNew = temp;
		}
	}
	return newList;
}
