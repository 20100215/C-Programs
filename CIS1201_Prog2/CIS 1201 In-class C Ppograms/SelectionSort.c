#include <stdio.h>

void selectionSort(int Arr[], int size)
{
	int x,y;
	int minIndex = 0;
	
	for (x=0;x<size;x++){
	
		for (y=x+1;y<size;y++){
			if (Arr[y]<Arr[minIndex]){
				minIndex=y;
			}
		}
		if (minIndex!=0){
			swap(&Arr[0],&Arr[minIndex]);
		}
		
	}

}

void swap(int*x,int*y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void main(){
	int A[10]={5,4,3,2,1,6,7,8,9,8};
	int x=10;
	findSmallest(A,x);
	printf("%d %d",A[0],A[4]);
}


/* check number of occurrences of element X in the array 
int findElement(int A[], int size, int X){
	int ndx,retval;
	for (ndx=0;ndx<size;ndx++){
		if (A[ndx]==X){
			retval++;
		}
	}
	return retval;
*/


/* The load balance problem (Q2 of Prefinals)
int updateLoadBalance(float*bal,int N){
	int num = N;
	float cost = N * 7.50;
	if (cost > 25){
		cost = 25;
	}
	if (*bal < cost){
		num = (int)(*bal/7.50);
		cost = num * 7.50;
	}
	*bal -= cost;
	return num;
}
*/
