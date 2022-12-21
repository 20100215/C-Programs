/*
 *   ADT Stack - Array Implementation
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
	DATATYPE data[MAX];
	int top;
}Stack;

void initialize(Stack *S); /* initializes stack to be logically empty */
void push(Stack *S, DATATYPE elem); /* inserts the element x at the top of the stack */
void pop(Stack *S); /* deletes the top element of the Stack S */
DATATYPE top(Stack S); /* returns the element at the top of the Stack S */
int isEmpty(Stack S); /* returns 1 if stack is empty and 0 if false */

void initialize(Stack *S){
	S->top = -1;
}

void push(Stack *S, DATATYPE elem){ /*insertLast() in arrays*/
	if (S->top < MAX - 1){
		S->top++;
		S->data[S->top] = elem;	
	}
}

void pop(Stack *S){
	if (S->top > -1){
		S->top--;	
	}
}

DATATYPE top(Stack S){
	return S.data[S.top];
}

int isEmpty(Stack S){
	return (S.top == -1) ? 1 : 0;
}

#endif
