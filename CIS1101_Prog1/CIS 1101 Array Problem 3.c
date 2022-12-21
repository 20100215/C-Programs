#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int getnum();
float* getnums(int x);
float solve(float X[], float Y[], int n);

int main()
{
	printf("Enter number of ordered pairs:\n"); int n = getnum();
	printf("Enter x-values:\n"); float *X = getnums(n);
	printf("Enter y-values:\n"); float *Y = getnums(n);
	printf("\nCorrelation coefficient (r) = %.4f \n", solve(X,Y,n));
	return 0;
}

int getnum(){
	int x;
	scanf("%d",&x);
	return x;
}

float* getnums(int n){
	float *arr = (float*)calloc(n+1,(n+1)*sizeof(float));
	float sum=0;
	int ndx;
	for (ndx=0; ndx<n; ndx++){
		scanf("%f",&arr[ndx]);
		sum+=arr[ndx];
	}
	arr[n]=sum;
	return arr;
}

float solve(float X[], float Y[], int n){
	float XX[n], YY[n], XY[n];
	float sumXX=0, sumYY=0, sumXY=0;
	float r;
	int ndx;
	for (ndx=0; ndx<n; ndx++){
		XX[ndx]=X[ndx]*X[ndx];
		YY[ndx]=Y[ndx]*Y[ndx];
		XY[ndx]=X[ndx]*Y[ndx];
		sumXX+=XX[ndx];
		sumYY+=YY[ndx];
		sumXY+=XY[ndx];
	}
	r=(n*sumXY-X[n]*Y[n])/sqrt((n*sumXX-X[n]*X[n])*(n*sumYY-Y[n]*Y[n]));
	return r;
}
