#define SIZE 30
#include<stdio.h>
#include<stdlib.h>

typedef struct{
   int elem;
   int left;
   int right;
}node;

typedef struct{
	node data;
	int link;
}nodeType;

typedef struct VH{
   nodeType nodes[SIZE];
   int avail;
}*VHeap;

typedef struct{
   int root;
   VHeap vptr;
}BST;

void initVHeap(VHeap* VH);

void insert(BST *T, int elem);
void populate(BST *T);
void inorder(VHeap VH,int T);

BST getEven(BST* T);

void main(){
	VHeap VH = (VHeap)calloc(1,sizeof(struct VH));
	initVHeap(&VH);
	
	BST A = {-1,VH};
	populate(&A);
	printf("\n");
	inorder(VH,A.root);
	
	BST B = getEven(&A);
	printf("\n");
	inorder(VH,A.root);
	printf("\n");
	inorder(VH,B.root);
	
}

void initVHeap(VHeap* VH){
	int x;
	for(x=SIZE-1;x>=0;x--){
		(*VH)->nodes[x].link=x-1;
	}
	(*VH)->avail = SIZE-1;
}

void insert(BST *T, int elem){
	int *trav;
	int temp = T->vptr->avail;
	
	for(trav=&T->root; *trav!=-1 && elem != T->vptr->nodes[*trav].data.elem; ){
		if(elem < T->vptr->nodes[*trav].data.elem){
			trav = &T->vptr->nodes[*trav].data.left;
		} else if (elem > T->vptr->nodes[*trav].data.elem){
			trav = &T->vptr->nodes[*trav].data.right;
		}
	}
	if(*trav==-1){
		T->vptr->avail = T->vptr->nodes[temp].link; 
		T->vptr->nodes[temp].link = -1;
		T->vptr->nodes[temp].data.elem = elem;
		T->vptr->nodes[temp].data.left = -1;
		T->vptr->nodes[temp].data.right = -1;
		*trav = temp;
	} //else element already exists
}

void populate(BST *T){
	insert(T,4);
	insert(T,10);
	insert(T,5);
	insert(T,1);
	insert(T,7);
	insert(T,0);
	insert(T,15);
	insert(T,-3);
	insert(T,-10);
	insert(T,-1);
	insert(T,15); //will not be placed
}

void inorder(VHeap VH, int T){
	if(T!=-1){
		inorder(VH,VH->nodes[T].data.left);
		printf("%d ",VH->nodes[T].data.elem);
		inorder(VH,VH->nodes[T].data.right);
	}
}

BST getEven(BST* T){
	BST Even = {-1,T->vptr};
	int *tempQueue[SIZE], *current, *next, temp, *ptr, front=0, rear=-1, *min;
	if(T->root!=-1){
		for(tempQueue[++rear]=&T->root; front!=(rear+1)%SIZE;){
			current = tempQueue[front];
			if(T->vptr->nodes[*current].data.elem % 2 == 0){
				temp = *current;
				if(T->vptr->nodes[temp].data.left == -1 || T->vptr->nodes[temp].data.right == -1){
					*current = (T->vptr->nodes[temp].data.left != -1) ? T->vptr->nodes[temp].data.left : T->vptr->nodes[temp].data.right;
					if(*current == -1){
						front = (front+1)%SIZE;
					}
				} else {
					for(min=&T->vptr->nodes[*current].data.right ; T->vptr->nodes[*min].data.left != -1; min = &T->vptr->nodes[*min].data.left){}
					*current = *min;
					*min = T->vptr->nodes[*min].data.right;
					T->vptr->nodes[*min].data.left = T->vptr->nodes[temp].data.left;
					T->vptr->nodes[*min].data.left = T->vptr->nodes[temp].data.right;
				}
				for(ptr=&Even.root;*ptr!=-1;){
					if(T->vptr->nodes[temp].data.elem < T->vptr->nodes[*ptr].data.elem){
						ptr = &T->vptr->nodes[*ptr].data.left;
					} else if (T->vptr->nodes[temp].data.elem > T->vptr->nodes[*ptr].data.elem){
						ptr = &T->vptr->nodes[*ptr].data.right;
					}
				}
				*ptr = temp;
				T->vptr->nodes[temp].data.left = -1;
				T->vptr->nodes[temp].data.right = -1;
				
			} else {
				next = &T->vptr->nodes[*current].data.left;
				if(*next != -1){
					rear = (rear+1)%SIZE;
					tempQueue[rear] = next;
				}
				next = &T->vptr->nodes[*current].data.right;
				if(*next != -1){
					rear = (rear+1)%SIZE;
					tempQueue[rear] = next;
				}
				front = (front+1) % SIZE;
			}
		}
	}
	return Even;
}



