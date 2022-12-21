#define MAX 10
#include <stdio.h>

typedef struct{
	char elem[MAX];
	int front;
	int rear;
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
	Q->front=1;
	Q->rear=0;	
}

int isFull(Queue Q){
	return (Q.front == (Q.rear + 2) % MAX) ? 1 : 0;	
}

int isEmpty(Queue Q){
	return (Q.front == (Q.rear + 1) % MAX) ? 1 : 0;	
}

void enqueue(Queue *Q, char ch){
	if(isFull(*Q) == 0){
		//increment rear
		Q->rear = (Q->rear + 1) % MAX;
		Q->elem[Q->rear] = ch;
	}
}

void dequeue(Queue *Q){
	if(isEmpty(*Q) == 0){
		//increment front
		Q->front = (Q->front + 1) % MAX;
	}
}

char front(Queue Q){
	if(isEmpty(Q) == 0){
		return Q.elem[Q.front];
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

