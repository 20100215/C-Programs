#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* link;
}*List;

typedef enum{
	TRUE, FALSE
}boolean;

void displayList(List A);
boolean findElem(List A, int elem);
void insertfirst(List *A, int elem);
void insertLast(List *A, int elem);
void insertPos(List *A, int elem, int pos);
List createEvenv3(List A);

void main(){
	List L;
	L = (List)malloc(sizeof(struct node));
	L->data = 5;
	L->link = (List)malloc(sizeof(struct node));
	L->link->data = 20;
	L->link->link = (List)malloc(sizeof(struct node));
	L->link->link->data = 4;
	L->link->link->link = NULL;
	insertLast(&L,40);
	insertPos(&L,22,1);
	displayList(L);
	
	List M = createEvenv3(L);
	printf("\n");
	displayList(M);
}

void displayList(List A){
	List temp;
    for(temp=A;temp!=NULL;temp=temp->link){
		printf("%d ",temp->data);
	}
}

boolean findElem(List A, int elem){
	List temp;
	for(temp=A; temp!=NULL && temp->data < elem; temp=temp->link){}
	return (temp!=NULL && temp->data == elem) ? TRUE : FALSE;
}

void insertfirst(List *A, int elem){
	List temp;
	temp = (List)malloc(sizeof(struct node));
	temp->data = elem;
	temp->link = *A; 
	*A = temp;
}

void insertLast(List *A, int elem){
	List* trav;
	List temp;
	for(trav=A; *trav!=NULL; trav = &(*trav)->link){}
	temp = (List)malloc(sizeof(struct node));
	temp->data = elem;
	temp->link = *trav; 
	*trav = temp;
}

void insertPos(List *A, int elem, int pos){
	List* trav;
	List temp;
	int ctr=1;
	for(trav=A; *trav!=NULL && ctr<pos; trav = &(*trav)->link, ctr++){}
	if(ctr==pos){
		temp = (List)malloc(sizeof(struct node));
		temp->data = elem;
		temp->link = *trav; 
		*trav = temp;
	}
}

List createEvenv3(List A){
	List travOld; /* used to traverse through given list */
	List* travNew; /* used to traverse through new list */
	List temp; /* used during the insertion process */
	List newList = NULL; /* the list to be returned – initialize to NULL */
	for(travOld=A; travOld!=NULL; travOld=travOld->link){
		if (travOld->data % 2 ==0 ) {
			for(travNew=&newList; *travNew!=NULL && (*travNew)->data < travOld->data ; travNew=&(*travNew)->link){}
			temp = (List) malloc (sizeof(struct node));
			temp->data = travOld->data;
			temp->link = *travNew;
			*travNew = temp;
		}
	}
	return newList;
}
