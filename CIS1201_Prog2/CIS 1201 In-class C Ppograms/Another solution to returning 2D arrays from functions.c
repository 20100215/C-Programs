#include<stdio.h>
#include<stdlib.h>
#define row 4
#define col 3

typedef int MyMatrix[row][col];

int** addv3(MyMatrix A, MyMatrix B); /* this one will return int(*ret)[3] - beginning address of contiguous 2D array in heap*/
                                     /* A better method since we can allocate a single memory space instead of separating integer pointers and columns */
void display3(int(*A)[col]); /* or int A[][3] */

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
	
	printf("\n  sizeof(A)       = %d",   sizeof(A));
	printf("\n  sizeof(A[0])    = %d",   sizeof(A[0]));
	printf("\n  sizeof(A[0][0]) = %d\n", sizeof(A[0][0]));
	
	
	printf("\nFor Addv2 (sum is stored in C, returned from the function)\n");	
	int(*C)[col];
	C = addv3(A,B);		 
	display3(C); 
	
	/*Array accessing via pointer*/
	int (*ptr)[col]; /* ptr is a pointer to arrays of col=3 integers */
	printf("\nint (*ptr)[col]; ");
	
	ptr = C;
	printf("\n  sizeof(ptr)       = %d",   sizeof(ptr));
	printf("\n  sizeof(ptr[0])    = %d",   sizeof(ptr[0]));
	printf("\n  sizeof(ptr[0][0]) = %d\n", sizeof(ptr[0][0]));
	printf("\n  If ptr = C,     then (*ptr == ptr[0]) = %d",         (*ptr == ptr[0])); /* TRUE */
	printf("\n  If ptr = C,     then (*ptr == ptr[0][0]) = %d",      (*ptr == ptr[0][0])); /* FALSE - int* vs int - type mismatch */
	printf("\n  If ptr = C,     then (*ptr == &ptr[0][0]) = %d",     (*ptr == &ptr[0][0])); /* TRUE */
	printf("\n  If ptr = C,     then (*(*ptr) == ptr[0][0]) = %d",   (*(*ptr) == ptr[0][0])); /* TRUE */
	printf("\n  If ptr = C,     then (*(*ptr) == *ptr[0]) = %d",     (*(*ptr) == *ptr[0])); /* TRUE */
	printf("\n  If ptr = C,     then (&ptr[0] == &ptr[0][0]) = %d\n",(&ptr[0] == &ptr[0][0])); /* TRUE for now (they have same addresses) but not in dynamically allocated array -  int** and int* - ptr type mismatch  */
	
	printf("\n  If ptr = C,     then (ptr == ptr[0]) = %d",          (ptr == ptr[0])); /* TRUE for now (they have same addresses) but not in dynamically allocated array - int** and int* - ptr type mismatch */
	printf("\n  If ptr = C,     then (ptr == &ptr[0]) = %d",         (ptr == &ptr[0])); /* TRUE */
	printf("\n  If ptr = C,     then (ptr == ptr[0][0]) = %d",       (ptr == ptr[0][0])); /* FALSE - int** vs int - type mismatch */
	printf("\n  If ptr = C,     then (ptr == &ptr[0][0]) = %d\n",    (ptr == &ptr[0][0])); /* TRUE for now (they have same addresses) but not in dynamically allocated array -  int** and int* - ptr type mismatch  */
	
	printf("\n  If ptr = C,     then *(*(ptr)) = %d ",        *(*ptr)); /* ptr[0][0] = 1 */
	printf("\n  If ptr = C,     then *(*(ptr+2)) = %d ",      *(*(ptr+2))); /* ptr[2][0] = 7 */
	printf("\n  If ptr = C,     then *(*(ptr)+2) = %d ",      *(*(ptr)+2)); /* ptr[0][2] = 3 */
	printf("\n  If ptr = C,     then *(*(ptr+2)+2) = %d\n",   *(*(ptr+2)+2)); /* ptr[2][2] = 9 */
	
	printf("\n  If ptr = C,     then *(*(ptr))+2 = %d",       *(*(ptr))+2); /* ptr[0][0]+2 = 1+2 = 3 */
	printf("\n  If ptr = C,     then *(*(ptr+2)+2)+2 = %d\n", *(*(ptr+2)+2)+2); /* ptr[2][2]+2 = 9+2 = 11 */
	
	ptr = C+1;
	printf("\n  If ptr = C+1,   then *(*ptr) = %d",           *(*ptr)); /* ptr[0+1][0] = 4 */
	printf("\n  If ptr = C+1,   then ptr[1][2] = %d \n",      ptr[1][2]); /* ptr[0+1 +1][2] = ptr[2][2] = 9 */
	
	ptr = C;
	printf("\n  If ptr = C,     then ptr[1][2] = %d",        ptr[1][2]); /* 6 */
	ptr = &C[0];
	printf("\n  If ptr = &C[0], then ptr[1][2] = %d",        ptr[1][2]); /* 6 */
	ptr++;
	printf("\n  After ptr++,    then ptr[1][2] = %d\n",       ptr[1][2]); /* ptr[++1][2] = ptr[2][2] = 9 */

}

int** addv3(MyMatrix A, MyMatrix B){ /*this function shows the correct malloc() procedure - array can now be returnable*/
	int x,y;
	
	/* Dynamic memory allocation - pointer to arrays of size col=3 integers */
	int(*ret)[col]= (int(*)[col])malloc(row*col*sizeof(int));
	
	printf("\n  sizeof(ret)       = %d",sizeof(ret)); /* sizeof(int(*)[3]) = 8 bytes */
	printf("\n  sizeof(ret[0])    = %d",sizeof(ret[0])); /* sizeof(int[3]) = 12 bytes */
	printf("\n  sizeof(ret[0][0]) = %d\n",sizeof(ret[0][0])); /* sizeof(int) = 4 bytes */
	
	for(x=0;x<row;x++){
		for(y=0;y<col;y++){
			ret[x][y] = A[x][y] + B[x][y];
		}
	}
	return ret;
}

void display3(int(*A)[col]){ /*MyMatrix datatype will not work here*/
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
