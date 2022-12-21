/* The includes and defines */
#include <stdio.h>
#include <string.h>
#define SIZE 50

/* Definition of Structure */
typedef struct{
    char LName[16];
    char FName[24];
    char MI;
}Nametype;

typedef struct{
	Nametype Name;
	unsigned int ID;
	char Course[8];
	int Year;
}Studtype;

typedef struct{
    Studtype Stud[SIZE];
	int count;
}Studlist;

Studlist currentList =  {{	{{"Dayata","Wayne Matthew",'A'},20100215,"BSCS",1},
							{{"Roman","Vladymir",'A'},20100231,"BSCS",1},
							{{"Sayson","Elikah Belle",'C'},20100333,"BSIT",1},
							{{"De La Cruz","Aylmer Leif",'S'},20100170,"BSCS",1},
							{{"Paguntalan","Keziah",'E'},20100292,"BSA",1}
						}, 5};

/* Function Prototypes */
Studtype getStudent();
void displayStudent(Studtype student);
void displayList(Studlist* list);
void initializeList(Studlist* list);
void populateList(Studlist* list);
int findElem(Studlist* list);
void addStudent(Studlist* list);

void insertFirst(Studlist* list);
void deleteStudent(Studlist* list);
void sortList(Studlist* list);
void insertSorted(Studlist* list);
void swap(Studtype *x,Studtype *y);

/* Main function */
int main () {
	
	//Ask miss the question read type, post the code.
	Studlist currentList =  {{	{{"Dayata","Wayne Matthew",'A'},20100215,"BSCS",1},
							{{"Roman","Vladymir",'A'},20100231,"BSCS",1},
							{{"Sayson","Elikah Belle",'C'},20100333,"BSIT",1},
							{{"De La Cruz","Aylmer Leif",'S'},20100170,"BSCS",1},
							{{"Paguntalan","Keziah",'E'},20100292,"BSA",1}
						}, 5};
	
	int x;
	Studtype test;
	FILE *fp;
	fp = fopen("newtest","w+");  //working: rb, rb+, wb+, ab+, the rest gives garbage
	if (fp!=NULL){
		for(x=0;x<5;x++){
			fwrite(&currentList.Stud[x],sizeof(Studtype),1,fp);
		}
		
		rewind(fp);
		for(x=0;x<5;x++){
			fread(&test,sizeof(Studtype),1,fp);
			printf("%-18s ", test.Name.LName);
			printf("%-26s ", test.Name.FName);
			printf("%-3c ", test.Name.MI);
			printf("%-10d ", test.ID);
			printf("%-10s ", test.Course);
			printf("%d\n", test.Year);  			
		}
		
		fclose(fp);
	}
	
	
	
	currentList.count=5;
	int isExit=0, option;
	printf("Welcome!");
	while(isExit==0){
		printf("\nEnter 1 to add new student/s");
		printf("\nEnter 2 to display student record list");
		printf("\nEnter 3 to find Student with ID");
		printf("\nEnter 4 to delete a student record");
		printf("\nEnter 5 to initialize/reset list");
		printf("\nEnter 6 to sort list");
		printf("\nEnter 0 to exit program\n");
		fflush(stdin);
		scanf("%d",&option);
		
		switch(option){
			case 1: {
				populateList(&currentList);
				break;
			}
			case 2: {
				displayList(&currentList);
				break;
			}
			case 3: {
				findElem(&currentList);
				break;
			}
			case 4: {
				deleteStudent(&currentList);
				break;
			}
			case 5: {
				initializeList(&currentList);
				break;
			}
			case 6: {
				sortList(&currentList);
				break;
			}
			case 0: {
				isExit=1;
				printf("\nExiting program...");
				break;
			}
			default: {
				printf("\nInvalid input, please try again.\n\n");
				break;
			}
		}	
	}
	return 0;
}

Studtype getStudent(){
	Studtype retval;
	printf("\nEnter Last Name: ");
	fflush(stdin);
	gets(retval.Name.LName);
	printf("\nEnter First Name: ");
	fflush(stdin);
	gets(retval.Name.FName);
	printf("\nEnter Middle Initial: ");
	fflush(stdin);
	scanf("%c",&retval.Name.MI);
	printf("\nEnter ID: ");
	fflush(stdin);
	scanf("%u",&retval.ID);
	printf("\nEnter Course: ");
	fflush(stdin);
	gets(retval.Course);
	printf("\nEnter Year Level: ");
	fflush(stdin);
	scanf("%d",&retval.Year);
	return retval;
}
   
 
void displayStudent(Studtype student){
/* We used the print format - so that all values will be aligned */
	printf("%-18s ", student.Name.LName);
	printf("%-26s ", student.Name.FName);
	printf("%-3c ", student.Name.MI);
	printf("%-10d ", student.ID);
	printf("%-10s ", student.Course);
	printf("%d\n", student.Year);  
}

void displayList(Studlist* list){
    int x;
    printf("\n===== Displaying student record list =====\n");
    printf("\nLast Name          First Name                 MI  ID         Course     Year Level\n");
    for(x = 0; x < list->count; x++){
		displayStudent(list->Stud[x]);
    }
}

void initializeList(Studlist* list){
    int ndx;
	for(ndx=list->count;ndx>=0;ndx--){
		strcpy(list->Stud[ndx].Name.FName,"                       ");
		strcpy(list->Stud[ndx].Name.LName,"               ");
		list->Stud[ndx].Name.MI=0;
		list->Stud[ndx].ID=0;
		strcpy(list->Stud[ndx].Course,"       ");
		list->Stud[ndx].Year=0;
	}
	list->count=0;
	printf("\nList successfully initialized.\n\n");
}

void populateList(Studlist* list){
	int x,N;
	printf("\nEnter number of students to add: ");
	fflush(stdin);
	scanf("%d",&N);
	for(x=1;x<=N;x++){
		printf("\nFor new student %d of %d:",x,N);
		addStudent(list);
	}
	printf("\n%d student entries successfully added.\n\n",N);
}

int findElem(Studlist* list){
/* We passed Studlist by address instead of pointer so that we won’t occupy too much memory. */
/* Passing by copy will create another copy of the list in this function while passing by address will just pass the pointer */
	int x, retVal = 0;
	unsigned int ID;
	printf("\nEnter Student ID: ");
	fflush(stdin);
	scanf("%u",&ID);

	for(x = 0; x < list->count && retVal == 0; x++){
		if (list->Stud[x].ID == ID){
      		retVal = x+1;
      		printf("\nStudent found at row #%d\n\n", x);
    	}
	}
	if (retVal == 0){
		printf("\nError: Student ID not found\n\n");
	}
	return retVal;
}


void addStudent(Studlist *list){
    int x;
	if(list->count >= SIZE){
		printf("\nList out of space. Try deleting record or re-initializing list.\n\n");
    }else{
   		printf("\nEnter 1 to insert at end of list");
   		printf("\nEnter 2 to insert at beginning of list");
   		printf("\nEnter 3 to insert at proper position in sorted list ");
   		fflush(stdin);
   		scanf("%d",&x);
   		
   		switch(x){
   			case 1: {
   				list->Stud[list->count] = getStudent();
   				printf("\nStudent successfully added to list");
				break;
			   }	
			case 2: {
				insertFirst(list);
				break;
			}
   			case 3: {
   				sortList(list);
   				insertSorted(list);
				break;
			}
		}
   		list->count++;
    }
}

void insertFirst(Studlist* list){
	int x;
	Studtype newStud = getStudent();
	for(x=list->count;x>=0;x--){
		list->Stud[x+1] = list->Stud[x];
	}
	list->Stud[0] = newStud;
	printf("\nStudent entry successfully inserted to beginning of list.\n\n");
}

void deleteStudent(Studlist* list){
	int x = findElem(list), y;
	int ndx=list->count-1;
	
	if(x!=0){
		list->count--;
		
		for(;x<list->count;x++){
			list->Stud[x] = list->Stud[x+1];
		}
		
		strcpy(list->Stud[ndx].Name.FName,"                       ");
		strcpy(list->Stud[ndx].Name.LName,"               ");
		list->Stud[ndx].Name.MI=0;
		list->Stud[ndx].ID=0;
		strcpy(list->Stud[ndx].Course,"       ");
		list->Stud[ndx].Year=0;
		
		printf("\nStudent entry successfully deleted.\n\n");
	}
}

void sortList(Studlist* list){
	int x,y;
	for(x=0; x < list->count-1; x++){
		for(y=0; y < list->count-x-1; y++){
			if(list->Stud[y].ID > list->Stud[y+1].ID){
				swap(&list->Stud[y], &list->Stud[y+1]);
			}
		}
	}
	printf("\nList successfully sorted.\n\n");
}

void insertSorted(Studlist* list){
	int x,y;
	Studtype newStud = getStudent();
	
	for(x=0; x < list->count && list->Stud[x].ID < newStud.ID; x++){}
	for(y=list->count-1; y>=x; y--){
		list->Stud[y+1] = list->Stud[y];
	}
	list->Stud[x]=newStud;
	printf("\nStudent entry successfully inserted to proper position in sorted list.\n\n");
}

void swap(Studtype *x,Studtype *y){
	Studtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/*****

Common mistakes observed: 
Using dot operator on a pointer to a structure instead of arrow
Logical comparison, using = instead of ==
Passing by Struct value vs passing struct by address to the function
Accessing an array within a structure (na kuwangan ug array data type) List[x] was used instead of List.Stud[x]
	
*****/

