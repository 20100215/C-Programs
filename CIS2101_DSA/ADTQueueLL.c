#define MAX 4
#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	char elem;
	struct cell* next;
}*node;

typedef struct{
	node front;
	node rear;
}Queue;

void initQueue(Queue *Q);
int isFull(Queue Q);
int isEmpty(Queue Q);
void enqueue(Queue *Q, char ch);
void dequeue(Queue *Q);
char front(Queue Q);

/*custom functions to be done using queue function calls*/
void displayQueue(Queue *Q);

void main(){
	Queue A;
	initQueue(&A);
	printf("%d\n",isEmpty(A));
	displayQueue(&A);	
	enqueue(&A,'a');
	enqueue(&A,'b');
	enqueue(&A,'c');
	enqueue(&A,'d'); //should not be accepted
	printf("%d\n",isEmpty(A));
	printf("%d\n",isFull(A));
	displayQueue(&A);	
	displayQueue(&A);
	dequeue(&A);
	displayQueue(&A);
}

void initQueue(Queue *Q){
	Q->front=NULL;
	Q->rear=NULL;	
}

int isFull(Queue Q){
	return 0;	
}

int isEmpty(Queue Q){
	return (Q.front == NULL) ? 1 : 0;	
}

void enqueue(Queue *Q, char ch){
	node temp;
	
	temp = (node)malloc(sizeof(struct cell));
	if(temp!=NULL){
		temp->elem = ch;
		temp->next = NULL;
		if(Q->front == NULL){
			//element is the first element
			Q->front = Q->rear = temp;
		} else {
			Q->rear = Q->rear->next = temp; 
		}
	}	
}

void dequeue(Queue *Q){
	node temp;
	
	if(Q->front != NULL){
		temp = Q->front;
		Q->front = temp->next;
		free(temp);
		if(Q->front == NULL){
			//element is the only remaining
			Q->rear = NULL;
		}
	}
}

char front(Queue Q){
	if(isEmpty(Q) == 0){
		return Q.front->elem;
	}
}

void displayQueue(Queue *Q){
	Queue temp;
	char ch;
	
	initQueue(&temp);
	while(isEmpty(*Q) == 0){
		ch = front(*Q);
		printf("%c",ch);
		dequeue(Q);
		enqueue(&temp,ch);
	}
	printf("\n");
	
	while(isEmpty(temp) == 0){
		ch = front(temp);
		dequeue(&temp);
		enqueue(Q,ch);
	}	
	
}
