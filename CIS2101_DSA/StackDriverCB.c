#include<stdio.h>
/*change the header file below to test different stack implementations*/
#include "ADTStackCB.h"

/*Sample stack functions*/
void insertBottom(VHeap *VH, Stack *S, char elem);
void displayStack(VHeap *VH, Stack S); /* top to bottom*/

void main(){
	VHeap VH;
	initVirtualHeap(&VH);
	Stack A;
	initialize(&A);
	push(&VH,&A,'a');
	push(&VH,&A,'b');
	push(&VH,&A,'c');
	displayStack(&VH,A); /* c b a */
	insertBottom(&VH,&A,'d');
	displayStack(&VH,A); /* c b a d */
	displayStack(&VH,A); /* c b a d */
}

void insertBottom(VHeap *VH, Stack *S, char elem){
	Stack temp;
	initialize(&temp);
	DATATYPE ch;
	while(isEmpty(*S) == 0){
		ch = top(*VH,*S);
		pop(VH,S);
		push(VH,&temp,ch);
	}
	push(VH,S,elem);
	while(isEmpty(temp) == 0){
		ch = top(*VH,temp);
		pop(VH,&temp);
		push(VH,S,ch);
	}	
}

void displayStack(VHeap *VH, Stack S){
	Stack temp;
	initialize(&temp);
	DATATYPE ch;
	while(isEmpty(S) == 0){
		ch = top(*VH,S);
		printf("%c",ch);
		pop(VH,&S);
		push(VH,&temp,ch);
	}
	while(isEmpty(temp) == 0){
		ch = top(*VH,temp);
		pop(VH,&temp);
		push(VH,&S,ch);
	}
	printf("\n");	
}
