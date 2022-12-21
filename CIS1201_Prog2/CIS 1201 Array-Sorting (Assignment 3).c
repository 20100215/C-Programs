#include <stdio.h>
#include <stdlib.h>
float* getStats (int size, int A[], int pass);

void main(){
	//test values here
	int numStud = 11, passing = 45;
	int scores[] = {51, 36, 49, 43, 60, 46, 50, 28, 33, 60, 56};
	float* result = getStats (numStud, scores, passing);
	
	int a;
	for (a=0;a<4;a++) printf("%.3f ",result[a]);
}

float* getStats (int size, int A[], int pass){

	//variable declaration and dynamic memory allocation
	int x, y, temp;
	float sum = 0;
	float* retval = (float*) malloc (4 * sizeof(float));
	
	//bubble sort with element addition
	for (x = 0; x < size-1; x++) {
		for (y = 0; y < size-x-1; y++) {
			if (A[y] > A[y+1]) {
				temp = A[y];
				A[y] = A[y+1];
				A[y+1] = temp;
			}
		}
		sum += A[size-x-1];
	}
	sum += A[0];

	//mean and median
	retval[0] = sum/size;
	if(size%2!=0) {
		retval[1] = A[size/2];
	} else {
		retval[1] = (float) ( A[size/2] + A[size/2 - 1] ) / 2;
	}

	//variance computation and index with passing score search
	sum = 0;
	for (x = 0; x < size && A[x] < pass; x++) {
		sum += ( A[x] - retval[0] ) * ( A[x] - retval[0] );
	}
	for (y = x; y < size; y++) {
		sum += ( A[y] - retval[0] ) * ( A[y] - retval[0] );
	}
	
	//variance and passing rate
	retval[2] = sum/size;
	retval[3] = (float) 100 * ( size - x ) / size;

	//return array
	return retval;
}


