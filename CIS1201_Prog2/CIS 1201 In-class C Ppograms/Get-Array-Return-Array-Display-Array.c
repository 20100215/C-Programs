#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* getIntegers(int N);
void displayArray(int A[],int size);

int main(){
	int *Arr;
	Arr=getIntegers(5);
	displayArray(Arr,5);
	
	int C[10];
	int x;
	for (x=0;x<5;x++){
		C[x]=Arr[x];
	}
	displayArray(C,5);
	return 0;
}

int* getIntegers(int N){
	int x;
	int *retval = (int*)malloc(N*sizeof(int));
	for (x=0;x<N;x++){
		scanf("%d",&retval[x]);
	}
	
	return retval;
}

void displayArray(int A[],int size){
	int x;
	for (x=0;x<size;x++){
		printf("%d ",A[x]);
	}
}
