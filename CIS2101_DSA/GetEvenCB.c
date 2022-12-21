#include <stdio.h>
#include <stdlib.h>

#define SIZE 0XA
typedef struct{
    int data;
    int link;
}Nodetype;
typedef struct VHnode {
    Nodetype heap[SIZE];
    int availList;      
}*VHeap;           /* Shared by all cursorList */
typedef struct {
    int elemPtr;    /* Points to the first element of the list */
    VHeap VH;       /* Points to the shared Virtual Heap */
}cursorList;       /*  Definition of the cursor list    */


void initVirtualHeap(VHeap *VH);
void displayVirtualHeap(VHeap VH);
void initCursorList(cursorList *L, VHeap VH);
void insertLast(cursorList *L, int elem);
void populateList(cursorList *L);
void displayList(cursorList L);

/* Main problem */
cursorList getEven(cursorList *L);

void main(){
	
	cursorList A, Even;
	VHeap V;
	
	printf("\nTask 1: \n");
	initVirtualHeap(&V);
	displayVirtualHeap(V);

	printf("\nTask 2: ");
	initCursorList(&A,V);
	displayList(A);
	
	printf("\nTask 3: ");
	populateList(&A);
	displayList(A);
	
	Even = getEven(&A);
	printf("\nTask 4 (Even numbers): ");
	displayList(Even);
	printf("\nTask 4 (Original List): ");
	displayList(A);
	printf("\n");
	displayVirtualHeap(V);
}

void initVirtualHeap(VHeap *VH){
	*VH = (VHeap)calloc(1,sizeof(struct VHnode));
	(*VH)->availList = 0;
	int ndx;
	
	(*VH)->heap[SIZE-1].link = -1;
	for(ndx = SIZE - 2; ndx >= 0; ndx--){
		(*VH)->heap[ndx].link = ndx+1;
	}
}

void displayVirtualHeap(VHeap VH){
	int ndx;
	
	for(ndx = 0; ndx < SIZE; ndx++){
		printf("%5d %5d %5d",ndx,VH->heap[ndx].data,VH->heap[ndx].link);
		printf("\n");
	}
}

void initCursorList(cursorList *L, VHeap VH){
	L->elemPtr = -1;
	L->VH = VH;
}

void insertLast(cursorList *L, int elem){
	int *trav, temp;
	for(trav = &L->elemPtr; *trav != -1; trav = &L->VH->heap[*trav].link){}
	temp = L->VH->availList;
	L->VH->availList = L->VH->heap[L->VH->availList].link;
	*trav = temp;
	L->VH->heap[*trav].data = elem;
	L->VH->heap[*trav].link = -1;
}

void populateList(cursorList *L){
	insertLast(L,4);
	insertLast(L,10);
	insertLast(L,3);
	insertLast(L,6);
	insertLast(L,7);
	insertLast(L,1);
	insertLast(L,2);
}

void displayList(cursorList L){
	int *trav;
	if(L.elemPtr == -1){
		printf("List is empty");
	} else {
		for (trav=&L.elemPtr; *trav!=-1; trav=&L.VH->heap[*trav].link){
			printf("%d ",L.VH->heap[*trav].data);
		}
	}
}

cursorList getEven(cursorList* L){
	cursorList Even = {-1,L->VH};
	int *trav, *ptr, temp;
	ptr = &Even.elemPtr;
	for(trav=&L->elemPtr; *trav!= -1;){
		if (L->VH->heap[*trav].data % 2 == 0){
			temp = *trav;
			*trav = L->VH->heap[temp].link;
			*ptr = temp;
			ptr = &L->VH->heap[*ptr].link;
		} else {
			trav = &L->VH->heap[*trav].link;
		}
	}
	*ptr = -1;
	return Even;
}
