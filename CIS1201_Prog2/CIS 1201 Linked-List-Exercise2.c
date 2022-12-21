#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}cell, *LIST;

void insertPos(LIST *L, int x, int pos);
void insertSorted(LIST *L, int x);
void findElem(LIST L, int x);
void deletePos(LIST* L, int pos);
void deleteElem(LIST* L, int x);
void displayList(LIST L);

void main(){
	LIST L=NULL;
	insertSorted(&L,4);
	insertSorted(&L,3);
	insertSorted(&L,10);
	insertSorted(&L,7);
	insertSorted(&L,70);
	insertSorted(&L,-4);
	insertSorted(&L,2);
	insertSorted(&L,8);
	insertSorted(&L,4);
	deleteElem(&L,4);
	displayList(L);
}

void insertPos(LIST *L, int x, int pos){
	LIST* ptr;
	int count=1;
	for(ptr=L;*ptr!=NULL && count<pos; ptr=&(*ptr)->next, count++){}
	if(count==pos){
		LIST temp = (LIST)malloc(sizeof(cell));
		if(temp!=NULL){
			temp->data=x;
			temp->next=*ptr;
			*ptr=temp;
		}
	}
}

void insertSorted(LIST *L, int x){
	LIST* ptr;
	for(ptr=L; *ptr!=NULL && x>(*ptr)->data; ptr=&(*ptr)->next){}
	LIST temp = (LIST)malloc(sizeof(cell));
	if(temp!=NULL){
		temp->data=x;
		temp->next=*ptr;
		*ptr=temp;
	}	
}

void insertSorted(LIST *L, int x){
	LIST* ptr;
	for(ptr=L; *ptr!=NULL && x>(*ptr)->data; ptr=&(*ptr)->next){}
	LIST temp = (LIST)malloc(sizeof(cell));
	if(temp!=NULL){
		temp->data=x;
		temp->next=*ptr;
		*ptr=temp;
	}	
}

void deletePos(LIST *L, int pos){
	LIST *ptr;
	int count=1;
	for(ptr=L;*ptr!=NULL && count<pos; ptr=&(*ptr)->next, count++){}
	if(count==pos){
		LIST temp = *ptr;
		*ptr = temp->next;
		free(temp);
	}
}

void deleteElem(LIST *L, int x){
	LIST *ptr;
	LIST temp;
	for(ptr=L;*ptr!=NULL;){
		if(x==(*ptr)->data){
			temp = *ptr;
			*ptr = temp->next;
			free(temp);
		} else {
			ptr=&(*ptr)->next;
		}
	}
}

void displayList(LIST L){
	LIST ptr;
	for(ptr=L;ptr!=NULL;ptr=ptr->next){
		printf("%d ",ptr->data);
	}
	printf("\n");
}

