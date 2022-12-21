#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef struct stud{
     char ID[9], FName[24], MI, LName[16];
     float grades[2]; 
             /*index 0->midterm, index 1->final*/
}studRec;

typedef struct node{
    struct node* LC;
    studRec data;
    struct node* RC;
}*Tree;

typedef struct{
    char courseCode[10];
    char courseName[40];
    int studCount; /*stores number of students*/
    Tree rec;
}classRec;


void initBST(classRec *C);
void displayBST(Tree T);

void inorder(Tree T); //sorted order

void insertMem(Tree *T, studRec node);
void populateBST(Tree *T);
void populate2(Tree *T);

int isMember(Tree T, char ID[]);

void deleteElem(Tree *T, char ID[]);

int checkGrades(classRec *C);

void main(){
	classRec crec;
	
	Tree T;
	/*Task 1*/
	initBST(&crec);
	displayBST(crec.rec);
	/*Task 2*/
	populateBST(&crec.rec);
	displayBST(crec.rec);
	
	printf("\n");
	printf("%d\n",checkGrades(&crec));
	displayBST(crec.rec);	
}

void initBST(classRec *C){
	C->studCount=8;
	C->rec=NULL;	
}

void displayBST(Tree T){
	if(T == NULL){
		printf("\nBST is empty");
	} else {
		printf("\n");
		inorder(T);
	}
}

void inorder(Tree T){ //sorted order
	if(T!=NULL){
		inorder(T->LC);
		printf("\n%-9s ",T->data.ID);
		printf("%-10s ",T->data.FName);
		printf("%-1c. ",T->data.MI);
		printf("%-10s ",T->data.LName);
		printf("%.1f ", T->data.grades[0]);
		printf("%.1f ", T->data.grades[1]);
		inorder(T->RC);
	}
}


void insertMem(Tree *T, studRec node){
	Tree *trav;
	for(trav=T; *trav != NULL && strcmp((*trav)->data.ID,node.ID)!=0;){
		trav = (strcmp(node.ID,(*trav)->data.ID)<0) ? &(*trav)->LC : &(*trav)->RC ;
	}	
	if (*trav==NULL){ //element does not exist
		*trav = (Tree)calloc(1,sizeof(struct node));
		(*trav)->data = node;
	}			
}

void populateBST(Tree *T){
	studRec rec[] = {
		{"10000010","10",'A',"10",{1.5}},
		{"10000005","05",'A',"05",{1.5}},
		{"10000007","07",'A',"07",{1.5}},
		{"10000014","14",'A',"14",{1.5}},
		{"10000012","12",'A',"12",{1.5}},
		{"10000011","11",'A',"11",{1.5}},
		{"10000018","18",'A',"18",{1.5}},
		{"10000015","15",'A',"15",{1.5}},
	};
	
	int x;
	for(x=0;x<8;x++){
		insertMem(T,rec[x]);
	}
	
}

int isMember(Tree T, char ID[]){
	Tree trav;
	for(trav=T; trav != NULL && strcmp(trav->data.ID,ID) != 0;){
		trav = (strcmp(ID,trav->data.ID)<0) ? trav->LC : trav->RC ;
	}	
	return (trav!=NULL) ? 1 : 0 ;
}

void deleteElem(Tree *T, char ID[]){
	Tree *trav, temp, min;
	for (trav=T; *trav!=NULL && strcmp((*trav)->data.ID,ID) != 0;){
		trav = (strcmp(ID,(*trav)->data.ID)<0) ? &(*trav)->LC : &(*trav)->RC ;
	}
	if(*trav!=NULL){ //element found
		temp = *trav;
		if((*trav)->LC == NULL || (*trav)->RC == NULL){ //node has at most 1 child
			*trav = (temp->LC!=NULL) ? temp->LC : temp->RC;
			free(temp);
		} else { //deleteMINsuccessor
			for(trav=&(*trav)->RC; (*trav)->LC!=NULL; trav=&(*trav)->LC){}
			min = *trav;
			temp->data = min->data;
			*trav = min->RC;
			free(min);
		}
	}
}

int checkGrades(classRec *C){ //pass by address since student count and head pointer might change
	int count=0, rear=-1, front=0;
	float finalGrade;
	Tree *tempQueue[SIZE], *current, temp, min; //elements in queue has to be of type pointer to pointer to have it pointed inside the actual tree
	if(C->rec!=NULL){
		for(tempQueue[++rear]=&C->rec;front!=(rear+1)%SIZE;){ //level order traversal
			current = tempQueue[front];
			
			do{ //enter final grade
				finalGrade = 0.0;
				printf("Enter final grade of student %s, %s %c.: ",(*current)->data.LName,(*current)->data.FName,(*current)->data.MI);
				scanf("%f",&finalGrade);
			}while(!((finalGrade>=1.0 && finalGrade<=3.0)||finalGrade==5.0)); //while grade is not in correct input range
			(*current)->data.grades[1]=finalGrade;
			
			if(finalGrade==5.0){ //delete node
			
				temp = *current;
				if(temp->LC==NULL || temp->RC==NULL){ //node has 0 or 1 child
					*current = (temp->LC!=NULL) ? temp->LC : temp->RC;
					if(*current==NULL){
						front=(front+1)%SIZE; //dequeue if no child
					}				
					free(temp);
				} else { //node has 2 children, delete min in right subtree (or you can go for delete max in left subtree also)
					for(current=&(*current)->RC;(*current)->LC!=NULL;current=&(*current)->LC){} //min of a subtree is the furthest possible left child
					min = *current;
					temp->data = min->data; //replace current node with the obtained min successor
					*current = min->RC;
					free(min);
				}
				count++; //add number of students deleted
				C->studCount--; //decrease number of students remaining
			
			} else { //enqueue children and dequeue
			
				if((*current)->LC!=NULL){
					rear=(rear+1)%SIZE;
					tempQueue[rear]=&(*current)->LC;
				}
				if((*current)->RC!=NULL){
					rear=(rear+1)%SIZE;
					tempQueue[rear]=&(*current)->RC;
				}
				front=(front+1)%SIZE;
			
			}
		}
	}
	return count;
}

/*
int checkGrades2(classRec *C){ //pass by address since student count and head pointer might change
	int count=0, rear=-1, front=0;
	float finalGrade;
	BST *tempQueue[SIZE], *current, temp, min; //elements in queue has to be of type pointer to pointer to have it pointed inside the actual tree
	if(C->data!=NULL){
		for(tempQueue[++rear]=&C->data;front!=(rear+1)%SIZE;){ //level order traversal
			current = tempQueue[front];
			
			do{ //input final grade
				finalGrade = 0.0;
				printf("Enter final grade of student %s, %s %c.: ",(*current)->rec.LName,(*current)->rec.FName,(*current)->rec.MI);
				scanf("%f",&finalGrade);
			}while(!((finalGrade>=1.0 && finalGrade<=3.0)||finalGrade==5.0)); //while grade is not in correct input range
			(*current)->rec.grades[1]=finalGrade;                             //While loop is okay but for me do-while is more readable
			
			if(finalGrade==5.0){ //delete node
			
				temp = *current;
				if(temp->left==NULL || temp->right==NULL){ //Case 1: node has 0 or 1 child
					*current = (temp->left!=NULL) ? temp->left : temp->right;
					if(*current==NULL){
						front=(front+1)%SIZE; //dequeue if no child
					}
					free(temp);
				} else { //Case 2: node has 2 children, delete min in right subtree (or you can go for delete max in left subtree also)
					for(current=&(*current)->right;(*current)->left!=NULL;current=&(*current)->left){} //min of a subtree is the furthest possible left child
					min = *current;
					temp->rec = min->rec; //replace current node with the obtained min successor
					*current = min->right;
					free(min);
				}
				count++; //add number of students deleted
				C->studCount--; //decrease number of students remaining
			
			} else { //enqueue children and dequeue
			
				if((*current)->left!=NULL){
					rear=(rear+1)%SIZE;
					tempQueue[rear]=&(*current)->left;
				}
				if((*current)->right!=NULL){
					rear=(rear+1)%SIZE;
					tempQueue[rear]=&(*current)->right;
				}
				front=(front+1)%SIZE;
			
			}
		}
	}
	return count;
}
*/
