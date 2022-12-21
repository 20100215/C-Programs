#include<stdio.h>
#include<stdlib.h>
/* Linked List Representation of List */
typedef struct node{
   int data;
   struct node *link;
}*List;

void sortV1(List L);
void sortV2(List L);
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
	
	/*toggle comments to experiment different versions*/
	sortV1(L);
	//sortV2(L);
	
	printf("\nAfter: ");
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

void sortV1(List L) { /*1 loop*/
    int temp; 
	List trav, end=NULL;
	for(trav=L;end!=L;){
		if(trav->link==end){
			end=trav;
			trav=L;
		} else {
			if (trav->data > trav->link->data){
				temp = trav->data;
				trav->data = trav->link->data;
				trav->link->data = temp;
			}	
			trav=trav->link;
		}
	}
}

void sortV2(List L) { /*2 loops*/
    int temp; 
	List trav, end=NULL;
	for(trav=L;end!=L;end=trav){
		for(trav=L;trav->link!=end;trav=trav->link){
			if (trav->data > trav->link->data){
				temp = trav->data;
				trav->data = trav->link->data;
				trav->link->data = temp;
			}	
		}
	}
}

void display(List L){
	List trav;
	for(trav=L;trav!=NULL;trav=trav->link){
		printf("%d ",trav->data);
	}
}
