#define MAX 4
#include <stdio.h>
#include <stdlib.h>

typedef struct cell{
	char elem;
	int next;
}node;

typedef struct{
	node nodes[MAX];
	int Avail;
}VHeap;

typedef struct{
	int front;
	int rear;
	VHeap *vptr;
}Queue;

VHeap VH; //virtual heap

void initQueue(Queue *Q);
int isFull(Queue Q);
int isEmpty(Queue Q);
void enqueue(Queue *Q, char ch);
void dequeue(Queue *Q);
char front(Queue Q);

/*custom functions to be done using queue function calls*/
void displayQueue(Queue *Q);

void main(){
	
   //initializing virtual heap
   int ndx;
   VH.Avail = MAX - 1;
   for (ndx = 0; ndx < MAX; ndx++){
      VH.nodes[ndx].next = ndx - 1;
   }
	
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
	Q->front=-1;
	Q->rear=-1;	
	Q->vptr = &VH;
}

int isFull(Queue Q){
	return (Q.vptr->Avail == -1) ? 1 : 0;	
}

int isEmpty(Queue Q){
	return (Q.front == -1) ? 1 : 0;	
}

void enqueue(Queue *Q, char ch){
	int temp;
	
	//allocspace()
	temp = Q->vptr->Avail;
	if(temp != -1){
		Q->vptr->Avail = Q->vptr->nodes[Q->vptr->Avail].next;
		
		//inserting
		Q->vptr->nodes[temp].elem = ch;
		Q->vptr->nodes[temp].next = -1;
		if(Q->front == -1){
			//element is the first element
			Q->front = Q->rear = temp;
		} else {
			Q->rear = Q->vptr->nodes[Q->rear].next = temp; 
		}
	}	
}
/*
Ex: front - 2
    rear - 2
    
    Avail: 1
       elem  next
    0    _    -1
    1    _     0
    2    B     -1
    3    A     1

*/
void dequeue(Queue *Q){
	int temp;
	
	temp = Q->vptr->nodes[Q->front].next;
	//deallocspace
	if(Q->front != -1){
		Q->vptr->nodes[Q->front].next = Q->vptr->Avail;
		Q->vptr->Avail = Q->front;
		
		Q->front = temp;
		if(Q->front == -1){
			//element is the only remaining
			Q->rear = -1;
		}
	}
}

char front(Queue Q){
	if(isEmpty(Q) == 0){
		return Q.vptr->nodes[Q.front].elem;
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
