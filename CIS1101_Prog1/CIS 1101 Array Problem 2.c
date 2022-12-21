#include<stdio.h>
#include<stdlib.h>
int* getIntegers();
void editArray(int A[]);
char checkArray(int A[]);

void main(){
	int *p=getIntegers();
	editArray(p);
	printf("%c",checkArray(p));
}

int* getIntegers(){
	int x;
	int *retval = (int*)calloc(16,sizeof(int));
	for (x=0;x<16;x+=4){
		scanf("%d",&retval[x]);
	}	
	return retval;
}

void editArray(int A[]){
	int x;
	for(x=0;x<16;x++){
		if(x%4!=0){
			A[x]=A[x/4*4]%10;
			A[x/4*4]/=10;
		}
	}
}

char checkArray(int A[]){
	int x,sum=0;
	char retval;
	for(x=0;x<16;x++){
		if(x%2==0){
			A[x]*=2;
			if(A[x]>9){
				A[x]=A[x]/10+A[x]%10;
			}
		}
		sum+=A[x];
	}
	if(sum%10==0){
		retval='Y';
	} else {
		retval='N';
	}
	return retval;
}
