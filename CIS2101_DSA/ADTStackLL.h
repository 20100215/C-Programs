/*
 *   ADT Stack - Linked List Implementation
 *   Header file for stack operations
 *
 *   By Wayne Dayata
 *   9/12/2021
 *
 *   Note: In driver program, define the DATATYPE through typedef
 */

#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

typedef char DATATYPE;

typedef struct node{
	DATATYPE data;
	struct node* next;
}*Stack;

void initialize(Stack *S); /* initializes stack to be logically empty */
void push(Stack *S, DATATYPE elem); /* inserts the element x at the top of the stack */
void pop(Stack *S); /* deletes the top element of the Stack S */
DATATYPE top(Stack S); /* returns the element at the top of the Stack S */
int isEmpty(Stack S); /* returns 1 if stack is empty and 0 if false */

void initialize(Stack *S){
	*S = NULL;
}

void push(Stack *S, DATATYPE elem){ /*insertFirst() in linked list*/
	Stack temp;
	temp = (Stack)malloc(sizeof(struct node));
	if(temp != NULL){
		temp->data = elem;
		temp->next = *S;
		*S = temp;
	}
}

void pop(Stack *S){ /*deleteFirst() in linked list*/
	if (*S != NULL){
		Stack temp;
		temp = *S;
		*S = (*S)->next;
		free(temp);	
	}
}

DATATYPE top(Stack S){
	return S->data;
}

int isEmpty(Stack S){
	return (S == NULL) ? 1 : 0;
}

#endif

