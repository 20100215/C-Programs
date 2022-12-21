#include<stdio.h>
#include<stdlib.h>
#define row 4
#define col 3

typedef int MyMatrix[row][col];

MyMatrix* addv3(MyMatrix A, MyMatrix B); /* dynamic array of integer pointers - each ptr points to dynamic array of col=3 integers - THE CORRECT ONE */
void display2(MyMatrix A); /*note the change of datatype*/

void main(){
	MyMatrix A = { 	{1,2,3},
					{4,5,6},
					{7,8,9},
					{10,11,12}
				 };
	MyMatrix B = { 	{13,14,15},
					{16,17,18},
					{19,20,21},
					{22,23,24}
				 };
	
	printf("\nFor Addv2 (sum is stored in C, returned from the function)\n");	
	MyMatrix* C;
	C = addv3(A,B);		 
	display2(*C); /* since C is a pointer, dereference C to get to the array's beginning address*/ 
	              /* but display2(C) - without the * symbol - worked but it flagged a type mismatch warning though..*/
	
	/*-----------------------
	The contiguousness of memory space in the dynamically allocated MyMatrix is now the same as before, continuous throughout all rows and columns
	since we are now able to allocate a block of memory good for the sizeof(MyMatrix).
	- However, the accessing and passing to/returning from functions is more tricky since it appears to have the array nested in another "structure" or created another "dimension"
	- This prompted me to dereference the pointer before placing indices
	   '---> Not ret[x][y] , nor *ret[x][y], but it is (*ret)[x][y]...
	   '---> So perhaps ret's datatype is MyMatrix* == int (*)[x][y] instead of ( int[][y] or int(*)[y] )...
	                         Originally,   MyMatrix == int [x][y]  (via typedef), which is same as int[][y] or int (*)[y] but row size is already known.
	-----------------------*/
	
	
	/*Array accessing via pointer to statically allocated MyMatrix A*/
	MyMatrix* ptr = &A; /* ptr = A flags a type mismatch warning; then the statements below each need an extra dereferencing*/
	printf("\nMyMatrix* ptr = &A; ");
	
	printf("\n  sizeof(ptr)          = %d",   sizeof(ptr));
	printf("\n  sizeof(ptr[0])       = %d",   sizeof(ptr[0]));
	printf("\n  sizeof(ptr[0][0])    = %d\n", sizeof(ptr[0][0]));
	
	printf("\n  sizeof(*ptr)         = %d",   sizeof(*ptr));	
	printf("\n  sizeof((*ptr)[0])    = %d",   sizeof((*ptr)[0]));
	printf("\n  sizeof((*ptr)[0][0]) = %d\n", sizeof((*ptr)[0][0]));
	
	printf("\n  ptr[0][0]     = %X", ptr[0][0]);
	printf("\n  &(*ptr)[0][0] = %X", &(*ptr)[0][0]);
	printf("\n  (*ptr)[0][0]  = %d\n", (*ptr)[0][0]); /* 1 */
	
	printf("\n  ptr[0][1]     = %X", ptr[0][1]); /*this increments by 12 bytes - (?)*/
	printf("\n  &(*ptr)[0][1] = %X", &(*ptr)[0][1]); /*this increments by 4 bytes*/
	printf("\n  (*ptr)[0][1]  = %d\n", (*ptr)[0][1]); /* 2 */
	
	printf("\n  ptr[1][2]     = %X", ptr[1][2]);
	printf("\n  &(*ptr)[1][2] = %X", &(*ptr)[1][2]);
	printf("\n  (*ptr)[1][2]  = %d\n", (*ptr)[1][2]); /* 6 */
	
	/*Array accessing via pointer to dynamically allocated MyMatrix C*/
	MyMatrix* ptrC = C; /* ptr = &C flags a type mismatch warning; then the statements below each need an extra dereferencing*/
	printf("\nMyMatrix* ptrC = C; ");
	
	printf("\n  sizeof(ptrC)          = %d",   sizeof(ptrC));
	printf("\n  sizeof(ptrC[0])       = %d",   sizeof(ptrC[0]));
	printf("\n  sizeof(ptrC[0][0])    = %d\n", sizeof(ptrC[0][0]));
	
	printf("\n  sizeof(*ptrC)         = %d",   sizeof(*ptrC));	
	printf("\n  sizeof((*ptrC)[0])    = %d",   sizeof((*ptrC)[0]));
	printf("\n  sizeof((*ptrC)[0][0]) = %d\n", sizeof((*ptrC)[0][0]));
	
	printf("\n  ptrC[0][0]     = %X", ptrC[0][0]);
	printf("\n  &(*ptrC)[0][0] = %X", &(*ptrC)[0][0]);
	printf("\n  (*ptrC)[0][0]  = %d\n", (*ptrC)[0][0]); /* 14 */
	
	printf("\n  ptrC[0][1]     = %X", ptrC[0][1]); /*this increments by 12 bytes - (?)*/
	printf("\n  &(*ptrC)[0][1] = %X", &(*ptrC)[0][1]); /*this increments by 4 bytes*/
	printf("\n  (*ptrC)[0][1]  = %d\n", (*ptrC)[0][1]); /* 16 */
	
	printf("\n  ptrC[1][2]     = %X", ptrC[1][2]);
	printf("\n  &(*ptrC)[1][2] = %X", &(*ptrC)[1][2]);
	printf("\n  (*ptrC)[1][2]  = %d\n", (*ptrC)[1][2]); /* 24 */
	
}

MyMatrix* addv3(MyMatrix A, MyMatrix B){ /*this function shows the correct malloc() procedure - array can now be returnable*/
	int x,y;
	
	MyMatrix *ret= (MyMatrix*)malloc(sizeof(MyMatrix)); /* Can use single malloc() statement to directly allocate memory space for MyMatrix - int[4][3] */
	
	printf("\nsizeof(ret)    = %d",sizeof(ret)); /* sizeof(MyMatrix*) = 8 bytes */
	printf("\nsizeof(*ret)   = %d",sizeof(*ret)); /* dereferencing ret gives direct access to the Matrix (2D array) in heap = 4*3*sizeof(int) = 48 bytes */
	printf("\nsizeof(ret[0]) = %d\n",sizeof(ret[0])); /* 48 bytes also --> ??? */
	
	for(x=0;x<row;x++){
		for(y=0;y<col;y++){
			(*ret)[x][y]= A[x][y] + B[x][y]; /*needs dereferencing of ret --> Both ret[x][y] and *ret[x][y] flagged errors */
		}
	}
	return ret;
	
}

void display2(MyMatrix A){ 
	int x,y;
	printf("Value of Array = %X\n\n",A);
	for(x=0;x<row;x++){
		printf("Address of Array[%d] = %X\n",x,&A[x]);
		printf("Value of Array[%d]   = %X\n",x,A[x]); /*that is, the address of Array[x][0], or &A[x][0]*/
		for(y=0;y<col;y++){
			printf("%X= %-4d",&A[x][y],A[x][y]);
		}
		printf("\n\n");
	}
}
