#include<stdio.h>
#define SIZE 6
typedef unsigned char elemType;
typedef elemType Stack[SIZE];
/*
 Data structure specification: 
 
 Implements a stack of uppercase character. 
 Index 0 will hold the index of the top element. 
 Elements will be stored at index 1 to 9. 
 Note that an unsigned character in C can hold a number between 0 to 255.
*/

void initStack(Stack S);
elemType top(Stack S);
void push(Stack S, elemType elem);
void pop(Stack S);
void populateStack(Stack S);
void displayStack(Stack S);

void main(){
	Stack A;
	printf("\nTask 1: ");
	initStack(A);
	displayStack(A);
	printf("\nTask 2: %c",top(A));
    printf("\nTask 3: ");
	populateStack(A);
	displayStack(A);
	displayStack(A);	
}

void initStack(Stack S){
	S[0] = 0;
}

elemType top(Stack S){
	return (S[0]==0) ? '*' : S[S[0]];
}

void push(Stack S, elemType elem){
	if(S[0]<SIZE-1){
		S[++S[0]]=elem;
	} else {
		printf("Stack is full!\n");
	}	
}

void pop(Stack S){
	if(S[0]>0){
		S[0]--;	
	} else {
		printf("Stack is empty!\n");
	}
}

void populateStack(Stack S){
	push(S,1);
	push(S,2);
	push(S,3);
	push(S,4);
	push(S,5);
	push(S,6);
}

void displayStack(Stack S){
	Stack temp = {0};
	while(S[0]>0){
		printf("%d ",top(S));
		push(temp,top(S));
		pop(S);
	}
	while(temp[0]>0){
		push(S,top(temp));
		pop(temp);
	}
}
