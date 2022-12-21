#include <stdio.h>
#include <stdlib.h>
#define EMPTY -2
#define DELETED -1
#define SIZE 10

typedef int Dictionary[SIZE];

void initDict(Dictionary D);
void displayDict(Dictionary D);
int hash(int elem);
void insert(Dictionary D, int elem);
void populate(Dictionary D);
int isMember(Dictionary D, int elem);
void deleteMem(Dictionary D, int elem);

/*Challenge functions*/

void main(){
	Dictionary D;
	
	initDict(D);
	displayDict(D);
	
	populate(D);
	displayDict(D);
	
	printf("%d ",isMember(D,28));
	printf("%d ",isMember(D,0));
	printf("%d ",isMember(D,118));
	
	deleteMem(D,48);
	deleteMem(D,10); //not found
	printf("\n%d\n",isMember(D,48));
	
	/* Output: 1 1 0 0 */
	
	displayDict(D);
	insert(D,98);
	insert(D,128);
	insert(D,148);
}

void initDict(Dictionary D){
	int x;
	for(x=0;x<SIZE;x++){
		D[x]=EMPTY;
	}	
}

void displayDict(Dictionary D){
	int x;
	printf("\n");		
	for(x=0;x<SIZE;x++){
		printf("\nIndex %d: ",x);
		switch(D[x]){
			case EMPTY: printf("Empty"); break;
			case DELETED: printf("Deleted"); break;
			default: printf("%d",D[x]); break;
		}
	}
	printf("\n");		
}

int hash(int elem){
	return elem%SIZE;
}
void insert(Dictionary D, int elem){ //insert sorted
	int key, ctr, numdeleted;
	
	ctr = 0;
	numdeleted = 0;
	//search if element exists
	for(key = hash(elem);ctr<SIZE && D[key]!=EMPTY && D[key]!=elem; key=hash(key+1)){
		if (D[key]==DELETED) {
			numdeleted++;
		}
		ctr++;
	}
	if (D[key]==elem) {
		printf("\nElement already exists");
	} else if (ctr==SIZE && numdeleted==0) {
		printf("\nNo more available space");
	} else {
		//insert the element
		for(key = hash(elem); D[key]!=DELETED && D[key]!=EMPTY; key=hash(key+1)){}
		D[key] = elem;
		printf("\nSuccessfully inserted element %d at index %d",elem,key);
	}
}

/*
void insert(Dictionary D, int elem){ //insert sorted
	int key, trav, ctr, numdeleted;
	key = hash(elem);
	ctr = 0;
	numdeleted = 0;
	//search if element exists
	for(trav=key;ctr<SIZE && D[trav]!=EMPTY && D[trav]!=elem; trav=(trav+1)%SIZE){
		if (D[trav]==DELETED) {
			numdeleted++;
		}
		ctr++;
	}
	if (D[trav]==elem) {
		printf("\nElement already exists");
	} else if (ctr==SIZE && numdeleted==0) {
		printf("\nNo more available space");
	} else {
		//insert the element
		for(trav=key; D[trav]!=DELETED && D[trav]!=EMPTY; trav=(trav+1)%SIZE){}
		D[trav] = elem;
		printf("\nSuccessfully inserted element %d at index %d",elem,trav);
	}
}
*/

void populate(Dictionary D){
	insert(D,0);
	insert(D,13);
	insert(D,20);
	insert(D,28);
	insert(D,30);
	insert(D,33);
	insert(D,45);
	insert(D,48);
	insert(D,108);
}

int isMember(Dictionary D, int elem){
	int key, ctr;
	key = hash(elem);
	for(ctr=0; ctr<SIZE && D[key]!=EMPTY && D[key]!=elem; ){
		//key=hash(key+1);
		//key = (key+1)%SIZE;
		key = hash(elem + (++ctr));
	}
	return (D[key]==elem) ? 1 : 0;
}

void deleteMem(Dictionary D, int elem){
	int key, ctr;
	key = hash(elem);
	for(ctr=0; ctr<SIZE && D[key]!=EMPTY && D[key]!=elem; ctr++){
		key=hash(key+1);
		//key = (key+1)%SIZE;
	}
	if (D[key]!=elem) {
		printf("\nElement %d to delete is not found",elem);
	} else {
		D[key] = DELETED;
		printf("\nElement %d is deleted",elem);
	}
}

