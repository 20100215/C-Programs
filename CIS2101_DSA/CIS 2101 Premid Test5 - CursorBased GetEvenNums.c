/*
 * 9/22/2021
 * CIS 2101 Premidterm Exam Test 5 Problem
 * Cursor-based Implementation of List
 *
 *   Problem Specification:  Given the list of integers, function getEven()
 *   will remove from the list all the even numbers and put them in the new list.
 *   The new list will be returned to the calling function.
 *
 */

#include<stdio.h>

typedef struct{
	int data;
	int link;
}NodeType;

typedef struct{
	NodeType heap[100];
	int Availlist;
}VHEAP,*VHeap;

typedef struct{
	int elemPtr;
	VHeap VH;
}cursorList;

cursorList getEven(cursorList *L);
void display(cursorList L);

void main(){
	
	VHEAP V = {{{10,1},{11,2},{12,3},{13,4},{14,5},{16,6},{17,7},{19,8},{20,9},{22,-1}},10};
	cursorList A = {0,&V};
	
	printf("Before: "); display(A);
	cursorList B = getEven(&A);
	printf("After (Old): "); display(A);
	printf("After (New): "); display(B);
	
}

cursorList getEven(cursorList *L){
	cursorList Even = {-1,L->VH};
	int *trav, *ptr, tempNode;
	
	ptr = &Even.elemPtr;
	for(trav = &L->elemPtr; *trav != -1;){
		if(L->VH->heap[*trav].data % 2 == 0){
			tempNode = *trav;
			*trav = L->VH->heap[tempNode].link;
			*ptr = tempNode;
			ptr = &L->VH->heap[*ptr].link;
		} else {
			trav = &L->VH->heap[*trav].link;
		}
	}
	*ptr = -1;
	return Even;
}

void display(cursorList L){
   int trav;
   for(trav = L.elemPtr; trav != -1; trav = L.VH->heap[trav].link){
   	  printf("%d ",L.VH->heap[trav].data);
   }	
   printf("\n");
}
