#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}cell, *LIST;

LIST findEven(LIST L);
void insertFirst(LIST *L, int x);
void displayList(LIST L);
void deleteElement(LIST *L, int x);

void main(){
	LIST L=NULL;
	LIST M=NULL;
	insertFirst(&L,4); // pass by address of the pointer's value since the address pointed to by L will be changed
	insertFirst(&L,3);
	insertFirst(&L,4);
	insertFirst(&L,2);
	insertFirst(&L,5);
	insertFirst(&L,4);
	displayList(L); //pass a copy of the pointer's value since nothing will be manipulated
	M = findEven(L);
	displayList(M);
	deleteElement(&L,4);
	displayList(L);
}

LIST findEven(LIST L){
	LIST new = NULL;
	LIST temp;
	for(temp=L;temp!=NULL;temp=temp->next){
		if(temp->data%2==0){
			insertFirst(&new,temp->data);
		}
	}
	return new;
}

void insertFirst (LIST * L, int x){
   LIST temp = (LIST) malloc (sizeof(cell));
   temp -> data = x;
   temp -> next = *L;
   *L = temp;
}

/*
void insertFirst (List * L, char ch){
   LIST temp = (LIST) malloc (sizeof(cell));
   temp -> data = ch;
   temp -> link = *L;
   *L = temp;
}
*/

void displayList(LIST L){
	LIST temp;
	for(temp=L;temp!=NULL;temp=temp->next){
		printf("%d ",temp->data);
	}
	printf("\n");
}

void deleteElement(LIST *L, int x){ //delete all occurrences of the element
	LIST temp=*L, prev=NULL;
	while(temp!=NULL && temp->data==x){ //checking if head pointer is the item to be deleted
		*L=temp->next;
		free(temp);
		temp=*L;
	}
	while(temp!=NULL){ //check rest of linked list
		if(temp->data==x){ //delete
			prev->next=temp->next;
			free(temp);
			temp=prev->next;
		}else{ //move pointers
			prev=temp;
			temp=temp->next;
		}
	}
}
