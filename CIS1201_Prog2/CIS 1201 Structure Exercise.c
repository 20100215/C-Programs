#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int num;
	int den;
}Frac;

Frac* AddFrac (Frac x, Frac y);
Frac* SubtFrac (Frac x, Frac y);
Frac* MultFrac (Frac x, Frac y);
Frac* DivFrac (Frac x, Frac y);
int LCM (int x, int y);
int GCF (int x, int y);
void displayFrac(Frac* ans);

void main(){
	Frac x,y;
	int op;
	printf("Enter first numerator, first denominator, second numerator, second denominator\n");
	scanf("%d %d %d %d", &x.num, &x.den, &y.num, &y.den);
	printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division\n");
	fflush(stdin);
	scanf("%d",&op);
	Frac* ans;
	
	switch (op){
		case 1:{
			ans=AddFrac(x,y);
			break;
		}
		case 2:{
			ans=SubtFrac(x,y);
			break;
		}
		case 3:{
			ans=MultFrac(x,y);
			break;
		}
		case 4:{
			ans=DivFrac(x,y);
			break;
		}
	}
	displayFrac(ans);
}

Frac* AddFrac (Frac x, Frac y){
	int gcf;
	Frac* ans = (Frac*)malloc(sizeof(Frac));
	ans->den = LCM(x.den,y.den);
	ans->num = ans->den/x.den*x.num + ans->den/y.den*y.num;
	gcf = GCF(ans->num,ans->den);
	if (gcf != 1){
		ans->num/=gcf;
		ans->den/=gcf;
	}
	return ans;
}

Frac* SubtFrac (Frac x, Frac y){
	int gcf;
	Frac*ans = (Frac*)malloc(sizeof(Frac));
	ans->den = LCM(x.den,y.den);
	ans->num = ans->den/x.den*x.num - ans->den/y.den*y.num;
	gcf = GCF(ans->num,ans->den);
	if (gcf != 1){
		ans->num/=gcf;
		ans->den/=gcf;
	}
	return ans;
}

Frac* MultFrac (Frac x, Frac y){
	int gcf;
	Frac*ans = (Frac*)malloc(sizeof(Frac));
	ans->num = x.num*y.num;
	ans->den = x.den*y.den;
	gcf = GCF(ans->num,ans->den);
	if (gcf != 1){
		ans->num/=gcf;
		ans->den/=gcf;
	}
	return ans;
	
}

Frac* DivFrac (Frac x, Frac y){
	int gcf;
	Frac*ans = (Frac*)malloc(sizeof(Frac));
	ans->num = x.num*y.den;
	ans->den = x.den*y.num;
	gcf = GCF(ans->num,ans->den);
	if (gcf != 1){
		ans->num/=gcf;
		ans->den/=gcf;
	}	
	return ans;
}

int LCM (int x, int y){
	int retval, larger, num;
	num = larger = (x>y)?x:y;
	while (num % x !=0 && num % y != 0){
		num += larger;
	}
	return num;
}

int GCF (int x, int y){
	int retval, smaller, larger, temp;
	if (x>y){
		larger = x;
		smaller = y;
	} else {
		larger = y;
		smaller = x;
	}
	while (smaller > 0){
		temp = larger;
		larger = smaller;
		smaller = temp % larger;
	}
	return larger;
}

void displayFrac(Frac*ans){
	printf("Answer: %d/%d", ans->num, ans->den);
}
