#include<stdio.h>
/*change the header file below to test different stack implementations*/
#include "ADTStackArr.h"

/*Sample stack functions*/
void insertBottom(Stack *S, char elem);
void displayStack(Stack *S); /* top to bottom*/

void main(){
	Stack A;
	
	initialize(&A);
	push(&A,'a');
	push(&A,'b');
	push(&A,'c');
	displayStack(&A); /* c b a */
	insertBottom(&A,'d');
	displayStack(&A); /* c b a d */
	displayStack(&A); /* c b a d */
}

void insertBottom(Stack *S, char elem){
	Stack temp;
	char ch;
	
	initialize(&temp);
	while(isEmpty(*S) == 0){
		ch = top(*S);
		pop(S);
		push(&temp,ch);
	}
	push(S,elem);
	while(isEmpty(temp) == 0){
		ch = top(temp);
		pop(&temp);
		push(S,ch);
	}	
}

void displayStack(Stack *S){
	Stack temp;
	char ch;
	
	initialize(&temp);
	while(isEmpty(*S) == 0){
		ch = top(*S);
		printf("%c",ch);
		pop(S);
		push(&temp,ch);
	}
	printf("\n");
	
	while(isEmpty(temp) == 0){
		ch = top(temp);
		pop(&temp);
		push(S,ch);
	}	
}
