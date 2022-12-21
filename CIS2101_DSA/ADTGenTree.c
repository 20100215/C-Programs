/*
 *   ADT General Tree Implementation using Array and Linked List
 *   By Wayne Dayata
 *   10/2/2021
 */

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef int DATATYPE;

typedef struct cell{
   int child;
   struct cell* link;
}*childList;

typedef struct node{
   DATATYPE label;
   int parent; /* -1: Root, -2: Not exist */
   childList cList;
}NodeType;
   
typedef struct{
   int root; /* -1: Empty tree / No root */
   NodeType node[SIZE];
}Tree;

/*Initialization and tree manipulation*/
void initialize(Tree *T);
void populateTree(Tree *T);
void insertRoot(Tree *T, DATATYPE label);
void insertLeaf(Tree *T, int parent, DATATYPE label);
void deleteLeaf(Tree *T, DATATYPE label);

/*Core operations*/
/*V1 - parent pointer rep., V2 - list of children rep.*/
DATATYPE label(Tree T, int node);
int root(Tree T);
int isLeafV1(Tree T, int node);
int isLeafV2(Tree T, int node);
int parentV1(Tree T, int node); 
int parentV2(Tree T, int node);
int leftmostChildV1(Tree T, int node);
int leftmostChildV2(Tree T, int node);
int rightSiblingV1(Tree T, int node);
int rightSiblingV2(Tree T, int node);

/*ADT General Tree Traversal*/
void displayPreorderRecur(Tree T, int node);
void displayPostorderRecur(Tree T, int node);
void displayPreorderNonRecur(Tree T, int node);
void displayPostorderNonRecur(Tree T, int node);

/*Custom operations*/
int height(int node, Tree T);
int depth(int node, Tree T);
int* getAncestors(int node, Tree T);
int* getDescendants(int node, Tree T);
int* pathFromRootV1(int node, Tree T);
int* pathFromRootV2(int node, Tree T);
Tree merge(DATATYPE data, Tree T1, Tree T2);

void main(){
	/*testing of functions*/
	Tree T;
	initialize(&T);
	populateTree(&T);
	
	int x;
	for(x=0;x<SIZE;x++){
		printf("\n index %d -- %d %d %d",x, T.node[x].label, T.node[x].parent, T.node[x].cList);
	}
	
	
	printf("\n");
	
	printf("\nPreorder (with recursion): ");
	displayPreorderRecur(T,0);
	
	printf("\nPreorder (without recursion): ");
	displayPreorderNonRecur(T,0);
		
	printf("\nPostorder (with recursion): ");
	displayPostorderRecur(T,0);
	
	printf("\nPostorder (without recursion): ");
	displayPostorderNonRecur(T,0);
	
	printf("\n");
	
	printf("%d ",root(T)); // 0
	printf("%d ",isLeafV1(T,4)); // 1
	printf("%d ",isLeafV1(T,5)); // 0	
	
	printf("%d ",label(T,parentV1(T,4))); // 2
	printf("%d ",label(T,parentV2(T,4))); // 2
	printf("%d ",label(T,parentV1(T,0))); // -1
	printf("%d ",label(T,parentV2(T,0))); // -1
	
	printf("%d ",label(T,leftmostChildV1(T,2))); // 4
	printf("%d ",label(T,leftmostChildV2(T,2))); // 4
	printf("%d ",label(T,leftmostChildV1(T,3))); // 6
	printf("%d ",label(T,leftmostChildV2(T,8))); // -1
	
	printf("%d ",label(T,rightSiblingV1(T,7))); // 8
	printf("%d ",label(T,rightSiblingV2(T,7))); // 8
	printf("%d ",label(T,rightSiblingV1(T,3))); // -1
	printf("%d ",label(T,rightSiblingV2(T,3))); // -1
	
	deleteLeaf(&T,3);  //Error: not leaf
	deleteLeaf(&T,9);  //Error: not exist
	
	deleteLeaf(&T,4);
	printf("\n%d ",label(T,leftmostChildV1(T,2))); // 5
	
}

void populateTree(Tree *T){
	insertRoot(T,0);
	insertLeaf(T,0,1);
	insertLeaf(T,0,2);
	insertLeaf(T,0,3);
	insertLeaf(T,2,4);
	insertLeaf(T,2,5);
	insertLeaf(T,3,6);
	insertLeaf(T,5,7);
	insertLeaf(T,5,8);
}

void initialize(Tree *T){
	int x;
	T->root = -1;
	for(x=0; x<SIZE; x++){
		T->node[x].parent = -2;
		T->node[x].label = -2;
		T->node[x].cList = NULL;
   }
}

void insertRoot(Tree *T, DATATYPE label){
	int x;
	if(T->root == -1){
		T->node[0].label = label;
		T->node[0].parent = -1; 
		T->root = 0;
	} else {
		for(x=0; x<SIZE && T->node[x].parent != -2; x++){}
		if (x<SIZE){
			T->node[T->root].parent = x;
			T->node[x].label = label;
			T->node[x].parent = -1;
			T->node[x].cList = (childList)calloc(1,sizeof(struct cell));
			T->node[x].cList->child = T->root;
			T->root = x;
		} else {
			printf("Error: Array List is full!\n");
		}
	}
}

void insertLeaf(Tree *T, int parent, DATATYPE label){
	int x;
	childList *trav;
	if (parent>=0 && parent<SIZE && T->node[parent].parent != -2) {
		for(x=0; x<SIZE && T->node[x].parent != -2; x++){}
		if (x<SIZE){
			T->node[x].label = label; 		
			T->node[x].parent = parent;
			for(trav=&T->node[parent].cList; *trav!=NULL; trav=&(*trav)->link){} 
			*trav = (childList)calloc(1,sizeof(struct cell));
			(*trav)->child = x;
			(*trav)->link = NULL;
		} else {
			printf("Error: Array List is full!\n");
		}
	}
}

void deleteLeaf(Tree *T, DATATYPE label){
	int x;
	childList *trav, temp;
	for(x=0; x<SIZE && T->node[x].label!=label; x++){}
	if(x<SIZE){
		if(T->node[x].cList == NULL){
			for(trav=&T->node[T->node[x].parent].cList; (*trav)->child!=x ; trav=&(*trav)->link){}
			temp = *trav;
			*trav = temp->link;
			free(temp);
			T->node[x].parent = -2;
		} else {
			printf("\nError: Node is not a leaf!");
		}
	} else {
		printf("\nError: There is no node containing the said label");
	}
}

DATATYPE label(Tree T, int node){
	DATATYPE dummy = -1; //change here to match datatype
	DATATYPE ret = dummy;
	if(node>=0 && node<SIZE && T.node[node].parent != -2){
		ret = T.node[node].label;
	}
	return ret;
}

int root(Tree T){
	return T.root;
}

int isLeafV1(Tree T, int node){
	int x = 0;
	if(node>=0 && node<SIZE){
		for(; x<SIZE && T.node[x].parent != node; x++){}
	}
	return (x==SIZE) ? 1 : 0;
}

int isLeafV2(Tree T, int node){
	return (node>=0 && node<SIZE && T.node[node].cList==NULL) ? 1 : 0;
}
 
int parentV1(Tree T, int node){
	return (node>=0 && node<SIZE) ? T.node[node].parent : -1;
}

int parentV2(Tree T, int node){
	int x, isMatch = 0;
	childList trav;
	if(node>=0 && node<SIZE){
		for(x=0; x<SIZE && isMatch==0; x++){
			for(trav=T.node[x].cList; trav!=NULL && trav->child != node; trav=trav->link){}
			if(trav!=NULL){
				isMatch = 1;
			}
		}
	}
	return (isMatch==1) ? x-1 : -1;
}

int leftmostChildV1(Tree T, int node){
	int x = -1;
	if (node>=0 && node<SIZE){
		for(x=0; x<SIZE && T.node[x].parent != node; x++){}
	}
	return (x>=0 && x<SIZE) ? x : -1;
}

int leftmostChildV2(Tree T, int node){
	int ret = -1;
	if (node>=0 && node<SIZE && T.node[node].cList!=NULL){
		ret = T.node[node].cList->child;
	}
	return ret;
}

int rightSiblingV1(Tree T, int node){
	int x = -1, parent;
	if (node>=0 && node<SIZE){
		parent = T.node[node].parent;
		for(x=node+1; x<SIZE && T.node[x].parent != parent; x++){}
	}
	return (x>=0 && x<SIZE) ? x : -1;
}

int rightSiblingV2(Tree T, int node){
	int x, isMatch = 0;
	childList trav;
	if(node>=0 && node<SIZE){
		for(x=0; x<SIZE && isMatch==0; x++){
			for(trav=T.node[x].cList; trav!=NULL && trav->child != node; trav=trav->link){}
			if(trav!=NULL){
				isMatch = 1;
				trav=trav->link; //to proceed to the next sibling
			}
		}
	}
	return (isMatch==1 && trav!=NULL) ? trav->child : -1;
}

void displayPreorderRecur(Tree T, int node) {
	int nextNode;
	if(node>=0 && node<SIZE){
		printf("%d ", label(T,node));
		nextNode = leftmostChildV2(T,node);
		while(nextNode != -1){
			displayPreorderRecur(T,nextNode);
			nextNode = rightSiblingV1(T,nextNode);
		}
	}
}

void displayPostorderRecur(Tree T, int node) {
	int nextNode;
	if(node>=0 && node<SIZE){
		nextNode = leftmostChildV2(T,node);
		while(nextNode != -1){
			displayPostorderRecur(T,nextNode);
			nextNode = rightSiblingV1(T,nextNode);
		}
		printf("%d ", label(T,node));
	}
}

void displayPreorderNonRecur(Tree T, int node) {
	int nodes[SIZE] = {}; //the stack
	int top = -1;
	int curNode;
	
	nodes[++top] = node; //push() root
	while(top >= 0){
		curNode = nodes[top];  //pop()
		if(curNode != -1){
			printf("%d ", label(T,curNode));
			nodes[++top] = leftmostChildV2(T,curNode); //push()
		} else {
			curNode = nodes[--top];
			nodes[top] = rightSiblingV1(T,curNode); //push()
		}
	}
}

void displayPostorderNonRecur(Tree T, int node) {
	int nodes[SIZE] = {}; //the stack
	int top = -1;
	int curNode;
	
	nodes[++top] = node; //push() root
	while(top >= 0){
		curNode = nodes[top];  //top()
		if(curNode != -1){
			nodes[++top] = leftmostChildV2(T,curNode); //push()
		} else {
			curNode = nodes[--top];  //top(); pop();
			if(top>=0) printf("%d ", label(T,curNode));
			nodes[top] = rightSiblingV1(T,curNode); //push()
		}
	}
}


