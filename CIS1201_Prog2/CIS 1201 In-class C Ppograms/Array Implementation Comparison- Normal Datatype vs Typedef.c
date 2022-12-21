#include <stdio.h>
#include <stdlib.h>
typedef int arr[5];

int* add1(int a[], int b[], int size);
void display1(int a[], int size);

arr* add2(arr a, arr b);
void display2(arr a);

void main(){
	int A[] = {1,2,3,4,5};
	int B[] = {1,2,3,4,5};
	int*C = add1(A,B,5);
	
	printf("Array C: ");
	display1(C,5);
	printf("\n");
	
	arr D = {1,2,3,4,5};
	arr E = {1,2,3,4,5};
	arr*F = add2(D,E);
	
	printf("Array F: ");
	display2(*F); /*beginning address of the array found in the heap (?) */
	printf("\n");
}

int* add1(int a[], int b[], int size){
	int x;
	int* ret = (int*)malloc(size*sizeof(int));
	for(x=0;x<size;x++){
		ret[x]=a[x]+b[x];
	}
	return ret;
}

void display1(int a[], int size){
	int x;
	for(x=0;x<size;x++){
		printf("%d ", a[x]);
	}
}

arr* add2 (arr a, arr b){
	int x;
	arr* ret = (arr*)malloc(sizeof(arr)); /* the data structure created in C visualization appears to be slightly different than in the add1()*/
	for(x=0;x<5;x++){
		(*ret)[x]=a[x]+b[x]; /*dereferencing needed..*/
	}
	return ret;
}

void display2(arr a){
	int x;
	for(x=0;x<5;x++){
		printf("%d ", a[x]);
	}
}

