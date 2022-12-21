#include<stdio.h>
#include<stdlib.h>
typedef struct to_do_task {
  int time;        /*  task time in minutes  */  
}TDT;

/* Linked List Representation of List */
typedef struct node{
   TDT task;
   struct node *nextTask;
}*taskLList;

void sortListByTime(taskLList L);
void display(taskLList L);

void main(){
	taskLList L;
	L = malloc(sizeof(struct node));
	L->task.time = 5;
	L->nextTask = malloc(sizeof(struct node));
	L->nextTask->task.time = 2;
	L->nextTask->nextTask = malloc(sizeof(struct node));
	L->nextTask->nextTask->task.time = 4;
	L->nextTask->nextTask->nextTask = malloc(sizeof(struct node));
	L->nextTask->nextTask->nextTask->task.time = 10;
	L->nextTask->nextTask->nextTask->nextTask = malloc(sizeof(struct node));
	L->nextTask->nextTask->nextTask->nextTask->task.time = 3;
	L->nextTask->nextTask->nextTask->nextTask->nextTask = NULL;
	printf("\nBefore: ");
	display(L);
	sortListByTime(L);
	printf("\nAfter: ");
	display(L);
}

void sortListByTime(taskLList L) {
   TDT temp; /*used when swapping*/
   taskLList trav, trav2, end=NULL;
   /*applying bubble sort - push larger elements forward*/
   for(trav=L; trav->nextTask!=end; trav=trav->nextTask){
      for(trav2=L; trav2->nextTask->nextTask!=end; trav2=trav2->nextTask){
         if(trav2->task.time > trav2->nextTask->task.time){ 
            /*swap data in current and next node*/
            temp = trav2->task;
            trav2->task = trav2->nextTask->task;
            trav2->nextTask->task = temp;
         }
      }
      end=trav->nextTask;
   }
}

void display(taskLList L){
	taskLList trav;
	for(trav=L;trav!=NULL;trav=trav->nextTask){
		printf("%d ",trav->task.time);
	}
}
