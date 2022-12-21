#include<stdio.h>
#include<stdlib.h>
#define row 4
#define col 3

typedef int MyMatrix[row][col];

void addv1A(MyMatrix A, MyMatrix B); /* static 2D array */
void addv1B(MyMatrix A, MyMatrix B); /* static array of integer pointers - each ptr points to dynamic array of col=3 integers */
int** addv2(MyMatrix A, MyMatrix B); /* dynamic array of integer pointers - each ptr points to dynamic array of col=3 integers - THE CORRECT ONE */
void display1(MyMatrix A);
void display2(int** A); /*note the change of datatype*/

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
				
	printf("\nFor addv1A (sum is in the function)\n");
	addv1A(A,B);
	
	printf("\nFor addv1B (sum is in the function)\n");
	addv1B(A,B);
	
	printf("\nFor Addv2 (sum is stored in C, returned from the function)\n");	
	int** C;
	C = addv2(A,B);		 
	display2(C); /*can't use display1 since there are already dynamic array allocations*/
	
	/*-----------------------
	Note that the address of array[n] is not the same as address of array[n][0] at all times:
	- In statically allocated arrays, they are the same
	- But in dynamically allocated arrays, the integer pointers form an array first (array[n] to array[row-1])
	  then each integer pointer is a pointer to their respective dynamically created array of integers (array[n][0] to array[n][col-1]),
	  hence the order of memory allocation is (array of int pointers -> 1st row of integers -> 2nd row of integers -> ... -> final row of integers.
	-----------------------*/
	
	
	/*Array accessing via pointer*/
	int (*ptr)[col]; /* ptr is a pointer to an array of col=3 integers - this can't be used to access array C*/
	printf("\nint (*ptr)[col]; ");
	
	ptr = A;
	printf("\n  sizeof(A)       = %d",   sizeof(A));
	printf("\n  sizeof(A[0])    = %d",   sizeof(A[0]));
	printf("\n  sizeof(A[0][0]) = %d\n", sizeof(A[0][0]));
	printf("\n  If ptr = A,     then (*ptr == ptr[0]) = %d",         (*ptr == ptr[0])); /* TRUE */
	printf("\n  If ptr = A,     then (*ptr == ptr[0][0]) = %d",      (*ptr == ptr[0][0])); /* FALSE - int* vs int - type mismatch */
	printf("\n  If ptr = A,     then (*ptr == &ptr[0][0]) = %d",     (*ptr == &ptr[0][0])); /* TRUE */
	printf("\n  If ptr = A,     then (*(*ptr) == ptr[0][0]) = %d",   (*(*ptr) == ptr[0][0])); /* TRUE */
	printf("\n  If ptr = A,     then (*(*ptr) == *ptr[0]) = %d",     (*(*ptr) == *ptr[0])); /* TRUE */
	printf("\n  If ptr = A,     then (&ptr[0] == &ptr[0][0]) = %d\n",(&ptr[0] == &ptr[0][0])); /* TRUE for now (they have same addresses) but not in dynamically allocated array -  int** and int* - ptr type mismatch  */
	
	printf("\n  If ptr = A,     then (ptr == ptr[0]) = %d",          (ptr == ptr[0])); /* TRUE for now (they have same addresses) but not in dynamically allocated array - int** and int* - ptr type mismatch */
	printf("\n  If ptr = A,     then (ptr == &ptr[0]) = %d",         (ptr == &ptr[0])); /* TRUE */
	printf("\n  If ptr = A,     then (ptr == ptr[0][0]) = %d",       (ptr == ptr[0][0])); /* FALSE - int** vs int - type mismatch */
	printf("\n  If ptr = A,     then (ptr == &ptr[0][0]) = %d\n",    (ptr == &ptr[0][0])); /* TRUE for now (they have same addresses) but not in dynamically allocated array -  int** and int* - ptr type mismatch  */
	
	printf("\n  If ptr = A,     then *(*(ptr)) = %d ",        *(*ptr)); /* ptr[0][0] = 1 */
	printf("\n  If ptr = A,     then *(*(ptr+2)) = %d ",      *(*(ptr+2))); /* ptr[2][0] = 7 */
	printf("\n  If ptr = A,     then *(*(ptr)+2) = %d ",      *(*(ptr)+2)); /* ptr[0][2] = 3 */
	printf("\n  If ptr = A,     then *(*(ptr+2)+2) = %d\n",   *(*(ptr+2)+2)); /* ptr[2][2] = 9 */
	
	printf("\n  If ptr = A,     then *(*(ptr))+2 = %d",       *(*(ptr))+2); /* ptr[0][0]+2 = 1+2 = 3 */
	printf("\n  If ptr = A,     then *(*(ptr+2)+2)+2 = %d\n", *(*(ptr+2)+2)+2); /* ptr[2][2]+2 = 9+2 = 11 */
	
	ptr = A+1;
	printf("\n  If ptr = A+1,   then *(*ptr) = %d",           *(*ptr)); /* ptr[0+1][0] = 4 */
	printf("\n  If ptr = A+1,   then ptr[1][2] = %d \n",      ptr[1][2]); /* ptr[0+1 +1][2] = ptr[2][2] = 9 */
	
	ptr = A;
	printf("\n  If ptr = A,     then ptr[1][2] = %d",        ptr[1][2]); /* 6 */
	ptr = &A[0];
	printf("\n  If ptr = &A[0], then ptr[1][2] = %d",        ptr[1][2]); /* 6 */
	ptr++;
	printf("\n  After ptr++,    then ptr[1][2] = %d\n",       ptr[1][2]); /* ptr[++1][2] = ptr[2][2] = 9 */

	
	int ** ptrC; /* ptr is a pointer to dynamically allocated array C - the sum of matrix A and B - this can't be used to access array A*/
	printf("\n\nint ** ptrC; ");
	
	ptrC = C;
	printf("\n  sizeof(C)       = %d",   sizeof(C));
	printf("\n  sizeof(C[0])    = %d",   sizeof(C[0]));
	printf("\n  sizeof(C[0][0]) = %d\n", sizeof(C[0][0]));
	printf("\n  If ptrC = C,    then ptrC[1][2] = %d \n",              ptrC[1][2]); /* 24 */
	
	printf("\n  If ptrC = C,    then (*ptrC == ptrC[0]) = %d",         (*ptrC == ptrC[0])); /* TRUE */
	printf("\n  If ptrC = C,    then (*ptrC == ptrC[0][0]) = %d",      (*ptrC == ptrC[0][0]));  /* FALSE - int* vs int - type mismatch */
	printf("\n  If ptrC = C,    then (*ptrC == &ptrC[0][0]) = %d",     (*ptrC == &ptrC[0][0])); /* TRUE */
	printf("\n  If ptrC = C,    then (*(*ptrC) == ptrC[0][0]) = %d",   (*(*ptrC) == ptrC[0][0])); /* TRUE */
	printf("\n  If ptrC = C,    then (*(*ptrC) == *ptrC[0]) = %d",     (*(*ptrC) == *ptrC[0])); /* TRUE */
	printf("\n  If ptrC = C,    then (&ptrC[0] == &ptrC[0][0]) = %d\n",(&ptrC[0] == &ptrC[0][0])); /* FALSE! */
	 
	printf("\n  If ptrC = C,    then (ptrC == ptrC[0]) = %d",          (ptrC == ptrC[0])); /* FALSE! */
	printf("\n  If ptrC = C,    then (ptrC == &ptrC[0]) = %d",         (ptrC == &ptrC[0])); /* TRUE */
	printf("\n  If ptrC = C,    then (ptrC == ptrC[0][0]) = %d",       (ptrC == ptrC[0][0])); /* FALSE */
	printf("\n  If ptrC = C,    then (ptrC == &ptrC[0][0]) = %d\n",    (ptrC == &ptrC[0][0])); /* FALSE! */

}

void addv1A(MyMatrix A, MyMatrix B){    /*cant return the address of the array created here since the sum array is locally declared */
	int x,y;
	int ans[row][col]; /*both row and col are static*/
	
	printf("\nsizeof(ans)=%d\n",sizeof(ans)); /* 4 rows * 3 columns * sizeof(int) = 48 bytes */
	
	for(x=0;x<row;x++){
		for(y=0;y<col;y++){
			ans[x][y] = A[x][y] + B[x][y];
		}
	}
	
	display1(ans); /*can't use display2() due to type mismatch - runtime error*/
}

void addv1B(MyMatrix A, MyMatrix B){    /*cant return the address of the array created here since the sum array is locally declared */
                                        /*even if the rows are dynamically allocated still the rows are locally declared*/
	int x,y;
	int *ans[row]; /*array of integer pointers is static but array of dynamic integers is dynamic*/
	
	printf("\nsizeof(ans)=%d\n",sizeof(ans)); /* 4 * sizeof(int) = 32 bytes */
	
	for(x=0;x<row;x++){
		ans[x]=(int*)malloc(col*sizeof(int));	
	}
	
	for(x=0;x<row;x++){
		for(y=0;y<col;y++){
			ans[x][y] = A[x][y] + B[x][y];
		}
	}
	
	display2(ans); /*can't use display1() since there are already dynamic array allocations*/
}


int** addv2(MyMatrix A, MyMatrix B){ /*this function shows the correct malloc() procedure - array can now be returnable*/
	int x,y;
	/*1. Dynamically create an array of integer pointers*/
	/*2. Dynamically create the column of integers for every row */
	
	int ** ret = (int**)malloc(row*sizeof(int*)); /*see NOTE at end of this function*/
	for(x=0;x<row;x++){
		ret[x]=(int*)malloc(col*sizeof(int));
	}
	
	printf("\nsizeof(ret)=%d",sizeof(ret)); /* sizeof(int**) = 8 bytes */
	printf("\nsizeof(ret[0])=%d\n",sizeof(ret[0])); /* sizeof(int*) = 8 bytes */
	
	for(x=0;x<row;x++){
		for(y=0;y<col;y++){
			ret[x][y] = A[x][y] + B[x][y];
		}
	}
	return ret;
	
	/*NOTE: Combining row and col in a single malloc() statement flags an error -> not possible */
}

void display1(MyMatrix A){
	int x,y;
	printf("Value of Array ans = %X\n\n",A);
	for(x=0;x<row;x++){
		printf("Address of Array[%d] = %X\n",x,&A[x]);
		printf("Value of Array[%d]   = %X\n",x,A[x]); /*that is, the address of Array[x][0], or &A[x][0]*/
		for(y=0;y<col;y++){
			printf("%X= %-4d",&A[x][y],A[x][y]);
		}
		printf("\n\n");
	}
}

void display2(int** A){ /*MyMatrix datatype will not work here*/
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
