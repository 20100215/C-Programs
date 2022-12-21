#include<stdio.h>
#include<stdlib.h>
/* Linked List Representation of List */
typedef struct node{
   int data;
   struct node *link;
}*List;

void sortV1(List L);
void sortV2(List L);
void reverseV1(List *L);
void reverseV2(List *L);
void display(List L);

int main(){
	printf("%d\n",2);
	List L;
	L = malloc(sizeof(struct node));
	L->data = 5;
	L->link = malloc(sizeof(struct node));
	L->link->data = 2;
	L->link->link = malloc(sizeof(struct node));
	L->link->link->data = 4;
	L->link->link->link = malloc(sizeof(struct node));
	L->link->link->link->data = 10;
	L->link->link->link->link = malloc(sizeof(struct node));
	L->link->link->link->link->data = 3;
	L->link->link->link->link->link = NULL;
	printf("\nBefore: ");
	display(L);
	
	reverseV2(&L);
	
	printf("\nAfter: ");
	display(L);
	return 0;
}

void sortV1(List L) {
	int x,y, temp, count;
	List trav;
	for(trav=L;trav!=NULL;trav=trav->link){
 		   count++; /* 5 */
	}
	for(x=count-1; x>0; x--){
 		trav = L;
 		for(y=0;y<x;y++){
 	   		if(trav->data > trav->link->data) {
 	      		temp = trav->data;
 	      		trav->data = trav->link->data;
 	      		trav->link->data = temp;
 	   		}
	    	trav = trav->link;
 	 	}
	}
}

void sortV2(List L) {
	int temp;
	List trav,end;
	for(end=NULL;L->link!=end;end=trav){
	  for(trav=L;trav->link!=end;trav=trav->link){
	    if(trav->data > trav->link->data) {
	       temp = trav->data;
	       trav->data = trav->link->data;
 	       trav->link->data = temp;
  	    }
 	  }
	}
}

void reverseV1(List *L){
	List prev = NULL;
	List trav, next;
	for(trav=*L; trav!=NULL; trav=next){
    	next = trav->link;
    	trav->link = prev;
    	prev = trav;
  	}
  	*L = prev;
}

void reverseV2(List *L){
   List *trav, temp;
   if(*L!=NULL && (*L)->link!=NULL){
      for(trav=&(*L)->link; *trav!=NULL; ){
         temp = *trav;
         *trav = temp->link;
         temp->link = *L;
         *L = temp;
      }
   }
}


void display(List L){
	List trav;
	for(trav=L;trav!=NULL;trav=trav->link){
		printf("%d ",trav->data);
	}
}
