/*
 *   ADT Stack -  Cursor-based Implementation
 *   Header file for stack operations
 *
 *   By Wayne Dayata
 *   9/12/2021
 *
 *   Note: In driver program, define the DATATYPE through typedef
 */

#define MAX 128

#ifndef STACK_H
#define STACK_H

typedef char DATATYPE;

typedef struct{
	DATATYPE data;
	int next;
}Nodetype;

typedef struct{
	Nodetype Nodes[MAX];
	int Avail;
}VHeap;

typedef int Stack; /* The value here stores the TOP element*/

/*Virtual heap simulation functions*/
void initVirtualHeap(VHeap *VH);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int node);

void initialize(Stack *S); /* initializes stack to be logically empty */
void push(VHeap *VH, Stack *S, DATATYPE elem); /* inserts the element x at the top of the stack */
void pop(VHeap *VH, Stack *S); /* deletes the top element of the Stack S */
DATATYPE top(VHeap VH, Stack S); /* returns the element at the top of the Stack S */
int isEmpty(Stack S); /* returns 1 if stack is empty and 0 if false */

void initVirtualHeap(VHeap *VH){
   int ndx;
   VH->Avail = MAX - 1;
   for (ndx = 0; ndx < MAX; ndx++){
      VH->Nodes[ndx].next = ndx - 1;
   }
}

int allocSpace(VHeap *VH){               /* similar to deleteFirst() (taking from unused cells) */
   int cell;
   cell = VH->Avail;
   if (cell != -1){                      /*check if there is still available cell */
      VH->Avail = VH->Nodes[cell].next;  /*update Avail to next available cell*/
      VH->Nodes[cell].next = -1;         /*block access to other nodes*/
   }
   return cell;
}

void deallocSpace(VHeap *VH, int cell){  /* similar to insertFirst() (linking with unused cells) */
   if (cell >= 0 && cell < MAX){
      VH->Nodes[cell].next = VH->Avail;  /*connects returned cell to rest of the VHeap*/
      VH->Avail = cell;                  /*make the cell readily available*/
   }
}

void initialize(Stack *S){
	*S = -1;
}

void push(VHeap *VH, Stack *S, DATATYPE elem){ /*insertFirst() in linked list*/
	Stack temp;
	temp = allocSpace(VH);
	if(temp != -1){
		VH->Nodes[temp].data = elem;
		VH->Nodes[temp].next = *S;
		*S = temp;
	}
}

void pop(VHeap *VH, Stack *S){ /*deleteFirst() in linked list*/
	if (*S != -1){
		Stack temp;
		temp = *S;
		*S = VH->Nodes[temp].next;
		deallocSpace(VH,temp);	
	}
}

DATATYPE top(VHeap VH, Stack S){
	return VH.Nodes[S].data;
}

int isEmpty(Stack S){
	return (S == -1) ? 1 : 0;
}

#endif

