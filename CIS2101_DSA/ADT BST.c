#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef struct node{
	int data;
	struct node *LC;
	struct node *RC;
	int height;
}*Tree;

void initBST(Tree *T);
void displayBST(Tree T);

void preorder(Tree T);
void postorder(Tree T);
void inorder(Tree T); //sorted order
void preorderNonRecur(Tree T);
void postorderNonRecur(Tree T);
void inorderNonRecur(Tree T);
void levelorder(Tree T);
void levelorderSeparateLine(Tree T);

void insertMem(Tree *T, int node);
void populateBST(Tree *T);
void populate2(Tree *T);

int isMember(Tree T, int node);

int deleteMax(Tree *T);
int deleteMin(Tree *T);
void deleteElem(Tree *T, int node);

/*Challenge functions*/
void levelorderSeparateLine(Tree T);
int getHeightV1(Tree T);
int getHeightV2(Tree T);
int checkBSTV1(Tree T);
int checkBSTV2(Tree T);
int checkAVLV1(Tree T);
int checkAVLV2(Tree T);
int isCousins(Tree T, int elem1, int elem2);

void main(){
	Tree T;
	/*Task 1*/
	initBST(&T);
	displayBST(T);
	/*Task 2*/
	populateBST(&T);
	displayBST(T);
	/*Task 3*/
	printf("\n%d %d %d",isMember(T,5),isMember(T,15),isMember(T,20));
	/*Task 4*/
	deleteElem(&T,11);
	displayBST(T);
	deleteElem(&T,5);
	displayBST(T);
	deleteElem(&T,10);
	displayBST(T);
	deleteElem(&T,14);
	displayBST(T);
	
	printf("\n\n");
	Tree S = NULL;
	populate2(&S);
	preorder(S);
	printf("\n");
	postorder(S);
	printf("\n");
	inorder(S);
	printf("\n");
	levelorder(S);
	printf("\n\n");
	levelorderSeparateLine(S);
	
	printf("\n%d %d",getHeightV1(S),getHeightV2(S));
}

void initBST(Tree *T){
	*T = NULL;	
}

void displayBST(Tree T){
	if(T == NULL){
		printf("\nBST is empty");
	} else {
		printf("\n");
		levelorder(T);
	}
}

void preorder(Tree T){
	if(T!=NULL){
		printf("%c ",T->data);
		preorder(T->LC);
		preorder(T->RC);
	}	
}

void postorder(Tree T){
	if(T!=NULL){
		postorder(T->LC);
		postorder(T->RC);
		printf("%c ",T->data);
	}	
}

void inorder(Tree T){ //sorted order
	if(T!=NULL){
		inorder(T->LC);
		printf("%c ",T->data);
		inorder(T->RC);
	}
}

void preorderNonRecur(Tree T){
	Tree TempStack[SIZE], current;
	int top=-1;
	
	if(T!=NULL){
		for(TempStack[++top]=T; top!=-1;){
			current = TempStack[top];
			if(current!=NULL){
				printf("%d ", current->data);
				TempStack[++top]=current->LC; //push left child
			} else {
				current = TempStack[--top]; //pop
				TempStack[top]=current->RC; //push right child
			}
		}
	}		
}


void postorderNonRecur(Tree T){
	Tree tempStack[SIZE], dispStack[SIZE], current;
	int top1=-1, top2=-1;
	
	if(T!=NULL){
		for(tempStack[++top1]=T; top1 != -1;){
			current = tempStack[top1--];
			if(current != NULL){
				dispStack[++top2] = current;
				tempStack[++top1] = current->LC;
				tempStack[++top1] = current->RC;	
			}
		}
		for(;top2!=-1;top2--){
			printf("%d ",dispStack[top2]->data);
		}
	}	
}

void inorderNonRecur(Tree T){
	Tree TempStack[SIZE], current;
	int top=-1;
	
	if(T!=NULL){
		for(TempStack[++top]=T; top!=-1;){
			current = TempStack[top];
			if(current!=NULL){
				TempStack[++top]=current->LC; //push left child
			} else {
				current = TempStack[--top]; //pop
				if(top>=0) printf("%d ", current->data);
				TempStack[top]=current->RC; //push right child
			}
		}
	}	
}

void levelorder(Tree T){
	Tree tempQueue[SIZE], current;
	int front=1, rear=0;
	if(T!=NULL){
		for(tempQueue[++rear]=T; front!=(rear+1)%SIZE;){
			current = tempQueue[front];
			front = (front+1)%SIZE;
			if(current!=NULL){
				printf("%c ",current->data);
				rear = (rear+1)%SIZE;
				tempQueue[rear] = current->LC;
				rear = (rear+1)%SIZE;
				tempQueue[rear] = current->RC;	
			}
		}
	}
}

void levelorderSeparateLine(Tree T){
	Tree tempQueue[SIZE], current;
	int front=1, rear=0, lastNodePos=1;
	if(T!=NULL){
		for(tempQueue[++rear]=T; front!=(rear+1)%SIZE; front=(front+1)%SIZE){
			current = tempQueue[front];
			printf("%c ",current->data);
			if(current->LC!=NULL){
				rear = (rear+1)%SIZE;	
				tempQueue[rear] = current->LC;
			}
			if(current->RC!=NULL){
				rear = (rear+1)%SIZE;
				tempQueue[rear] = current->RC;
			}
			if(front==lastNodePos){
				printf("\n");
				lastNodePos=rear;
			}
		}
	}
}

void insertMem(Tree *T, int node){
	Tree *trav;
	for(trav=T; *trav != NULL && (*trav)->data != node;){
		trav = (node < (*trav)->data) ? &(*trav)->LC : &(*trav)->RC	;
	}	
	if (*trav==NULL){ //element does not exist
		*trav = (Tree)calloc(1,sizeof(struct node));
		(*trav)->data = node;
	}			
}

void populateBST(Tree *T){
	insertMem(T,10);
	insertMem(T,5);
	insertMem(T,7);
	insertMem(T,14);
	insertMem(T,12);
	insertMem(T,11);
	insertMem(T,18);
	insertMem(T,15);
	
}

void populate2(Tree *T){
	char ch[] = "MIDTERMEXAMDATASTRUCTURES";
	int x;
	for(x=0;ch[x]!='\0';x++){
		insertMem(T,ch[x]);
	}
	//deleteElem(T,'D');
	//deleteElem(T,'I');
	//deleteElem(T,'M');
}

int isMember(Tree T, int node){
	Tree trav;
	for(trav=T; trav != NULL && trav->data != node;){
		trav = (node < trav->data) ? trav->LC : trav->RC ;
	}	
	return (trav!=NULL) ? 1 : 0 ;
}

int deleteMax(Tree *T){
	Tree *trav, temp;
	int num = -1;
	for(trav=T; *trav!=NULL && (*trav)->RC!=NULL; trav=&(*trav)->RC){}
	if(*trav!=NULL){ //false when given tree/subtree is empty
		temp = *trav;
		num = temp->data;
		*trav = temp->LC; //replace with next LC if it exists, otherwise NULL
		free(temp);
	}
	return num;	
}

int deleteMin(Tree *T){
	Tree *trav, temp;
	int num = -1;
	for(trav=T; *trav!=NULL && (*trav)->LC!=NULL; trav=&(*trav)->LC){}
	if(*trav!=NULL){ //false when given tree/subtree is empty
		temp = *trav;
		num = temp->data;
		*trav = temp->RC; //replace with next RC if it exists, otherwise NULL
		free(temp);
	}
	return num;	
}

void deleteElem(Tree *T, int node){
	Tree *trav, temp;
	for (trav=T; *trav!=NULL && (*trav)->data != node;){
		trav = (node < (*trav)->data) ? &(*trav)->LC : &(*trav)->RC ;
	}
	if(*trav!=NULL){ //element found
		temp = *trav;
		if((*trav)->LC == NULL || (*trav)->RC == NULL){ //node has at most 1 child
			*trav = (temp->LC!=NULL) ? temp->LC : temp->RC;
			free(temp);
		} else { // node has 2 children -> replace with predecessor (choose ONLY 1 between deleteMin or deleteMax)
			//temp->data = deleteMax(&temp->LC);
			temp->data = deleteMin(&temp->RC);
		}
	}
}

int getHeightV1(Tree T){
	int lH,rH;
	if(T==NULL){
		return -1;
	} else {
		lH = getHeightV1(T->LC);
		rH = getHeightV1(T->RC);
		return (lH>rH)? 1+lH : 1+rH;
	}
}

int getHeightV2(Tree T){
	int H=-1, front=0, rear=-1, lastNodePos=0;
	Tree tempQueue[SIZE], current;
	if(T!=NULL){
		for(tempQueue[++rear]=T; front!=(rear+1)%SIZE; front=(front+1)%SIZE){
			current = tempQueue[front];
			if(current->LC!=NULL){
				rear=(rear+1)%SIZE;
				tempQueue[rear]=current->LC;
			}
			if(current->RC!=NULL){
				rear=(rear+1)%SIZE;
				tempQueue[rear]=current->RC;
			}
			if(front==lastNodePos){
				H++;
				lastNodePos=rear;
			}
		}
	}
	return H;
}

int checkBSTV1(Tree T){
	if(T==NULL){
		return 1;
	} else if (T->LC != NULL && T->LC->data > T->data){
		return 0;
	} else if (T->RC != NULL && T->RC->data < T->data){
		return 0;
	} else {
		return checkBSTV1(T->LC) && checkBSTV1(T->RC);	
	}
}

int checkAVL(Tree T);
int isCousins(Tree T, int elem1, int elem2);
