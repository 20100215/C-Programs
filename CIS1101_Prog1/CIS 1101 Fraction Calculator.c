#include <stdio.h>

/* function prototypes */
int getnum();
int getLCM(int,int);
int getGCD(int,int);

int main(){
	/* variable declarations */
	int format,i1,i2,n1,n2,d1,d2,op,LCM,n,d,GCD;
	
	/* program description */
	printf("****************FRACTION CALCULATOR BY WAYNE****************\n");
	printf("******This program computes operation of two fractions******\n\n");
	
	/* user input */
	printf("Choose format: Enter 1 for a/b _ c/d  or 2 for a b/c _ d e/f \n");
	format = getnum();
	if (format == 1){
		printf("\nEnter 4 positive numbers (a to d), separate each number by a single space\n");
		printf("(Refer to above format)\n");
		n1 = getnum();
		d1 = getnum();
		n2 = getnum();
		d2 = getnum();
	} else if (format == 2) {
		printf("\nEnter 6 positive numbers (a to f), separate each number by a single space\n");
		printf("(Refer to above format)\n");
		i1 = getnum();
		n1 = getnum();
		d1 = getnum();
		i2 = getnum();
		n2 = getnum();
		d2 = getnum();
		n1 = i1 * d1 + n1;
		n2 = i2 * d2 + n2;
	} else {
		printf("\nInvalid input, please restart program!");
		exit(0);
	}
	if (d1==0 || d2==0) {
		printf("\nInvalid input (Divide by zero error), please restart program!");
		exit(0);
	}
	
	printf("\nChoose operation:\n");
	printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication, and 4 for division\n");
	op = getnum();
	
	/* perform operation */
	switch(op){
		case 1: /*addition*/
			printf("\nResult:\n%d/%d + %d/%d = ",n1,d1,n2,d2);
			d = LCM = getLCM(d1,d2);
			n1 = LCM / d1 * n1;
			n2 = LCM / d2 * n2;
			n = n1 + n2;
			break;
		case 2: /*subtraction*/
			printf("\nResult:\n%d/%d - %d/%d = ",n1,d1,n2,d2);
			d = LCM = getLCM(d1,d2);
			n1 = LCM / d1 * n1;
			n2 = LCM / d2 * n2;
			n = n1 - n2;
			break;
		case 3: /*multiplication*/
			printf("\nResult:\n%d/%d * %d/%d = ",n1,d1,n2,d2);
			n = n1 * n2;
			d = d1 * d2;
			break;
		case 4: /*division*/
			if (n2==0){
				printf("\nInvalid input (Divide by zero error), please restart program!");
				exit(0);
			}
			printf("\nResult:\n%d/%d / %d/%d = ",n1,d1,n2,d2);
			n = n1 * d2;
			d = d1 * n2;
			break;
		default:
			printf("\nInvalid input, please restart program!");
			exit(0);
	}
	
	/* check for lowest terms */
	if (n<0)
		GCD= getGCD(-n,d);
	else
		GCD = getGCD(n,d);
		
	if (GCD>0){
		n /= GCD;
		d /= GCD;
	}

	/* display result */
	if (n%d==0)
	    printf("%d\n",n/d);
	else if (n<d)
		printf("%d/%d\n",n,d);
	else
		printf("%d/%d or %d %d/%d\n",n,d,n/d,n%d,d);
	
	return 0;
}

/* function definitions */
int getnum() {
	int num;
	scanf("%d",&num);
	return num;
}

int getLCM(int a, int b){
	int LCM;
	int larger,smaller;
	LCM = larger = (a>b)?a:b;
	smaller = (a<b)?a:b;
	while (LCM % smaller != 0) 
		LCM += larger;
	return LCM;
}

int getGCD(int a, int b){
	int GCD;
	int larger,smaller;
	larger = (a>b)?a:b;
	GCD = smaller = (a<b)?a:b;
	while (GCD > 0){
		GCD = larger % smaller;
		larger = smaller;
		smaller = GCD;
	}
	return larger;
}
