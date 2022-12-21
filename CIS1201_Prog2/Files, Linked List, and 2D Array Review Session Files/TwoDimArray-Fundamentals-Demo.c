#include<stdio.h>
#include<stdlib.h>

int** AddMatrix(int row, int col, int A[][col], int B[][col]);
void displaysum(int** A, int row, int col);

void main(){
	int A[5][4] = {{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,7}};
	int B[5][4] = {{9,8,7,6},{5,4,3,2},{1,9,8,7}};
	int** sum = AddMatrix(5,4,A,B);
	displaysum(sum,5,4);
}

int** AddMatrix(int row, int col, int A[][col], int B[][col]){
	int x,y;
	
	/*Dynaic memory allocation and addition*/
	int** sum = (int**)malloc(row*sizeof(int*));
	if(sum!=NULL){
		for(x=0;x<row;x++){
			sum[x] = (int*)malloc(col*sizeof(int));
			if(sum[x]!=NULL){
				for(y=0;y<col;y++){
					sum[x][y] = A[x][y] + B[x][y];
				}
			}
		}
	}
	return sum;
}

void displaysum(int** A, int row, int col){
	int x,y;
	for(x=0; x<row; x++){
		for(y=0; y<col; y++){
        	printf("%d ",A[x][y]);
		}
		printf("\n");
	}
}
