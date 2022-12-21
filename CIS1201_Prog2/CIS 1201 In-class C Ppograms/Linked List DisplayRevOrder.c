#include<stdio.h>
#include<stdlib.h>
/* Linked List Representation of List */
typedef struct node{
   int data;
   struct node *link;
}*List;

void display(List L);

int main(){
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
	
	return 0;
}

/*
end = NULL
Beginning: 5 2 4 10 3 ||
1st iteration: 2 4 5 3 || 10
2nd iteration: 2 4 3 || 5 10
3rd iteration: 2 3 || 4 5 10
4th iteration: 2 || 3 4 5 10
5th iteration: || 2 3 4 5 10
end now points to L -> loop exits
*/

void display(List L){
    List trav, end;
    if(L!=NULL){
	    for(end=NULL;end!=L;end=trav){
 			for(trav=L;trav->link!=end;trav=trav->link){}
   		    printf("%d ",trav->data);
    	}
	}
}
