#include <stdio.h> 
void displayArray(float bal[],int N)
{
	int x;
	for (x=0;x<N;x++){
		printf("%.2f ",bal[x]);
	}
	printf("\n\n");
}

int updateSavings(float bal[], char tcode[], float A[], int N)
{
int x;
int failedTrans = 0;

for (x=0; x<N; x++)
{
if (tcode[x] == 'D' || tcode[x] == 'd') {
		bal[x] += A[x];
		printf("\n%d.OK",x+1);
} else if (tcode[x] == 'W' || tcode[x] == 'w') {
	if (bal[x] < A[x]) {
	printf("\n%d.Insufficient account balance",x+1);
	failedTrans += 1;
} else {
	bal[x] -= A[x];
	printf("\n%d.OK",x+1);
}
} else if (tcode[x] == 'C' || tcode[x] == 'c') {
	printf("\n%d.OK (Balance of account # %d: %.2f)", x+1, x+1, bal[x]);
} else {
	printf("%d.Incorrect transaction code",x+1);
	failedTrans += 1;
}
}
return failedTrans;
}

void main() {
/* FUNCTION CALL */
float bal[] = {50.00, 40.00, 30.00, 20.00, 10.00};
char tcode[] = {'U', 'c', 'W', 'd', 'W'};
float A[] = {10.00, 20.00, 30.00, 40.00, 50.00};
int N = sizeof(bal) / sizeof(bal[0]);
printf("\nBefore calling updateSavings()\n");
displayArray(bal,N);
printf("\n\nFailed transactions: %d/%d\n\n",updateSavings(bal, tcode, A, N),N);
printf("\nAfter calling updateSavings()\n");
displayArray(bal,N);
}










