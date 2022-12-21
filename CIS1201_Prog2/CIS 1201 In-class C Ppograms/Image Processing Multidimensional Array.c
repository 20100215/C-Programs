#include <stdio.h>
int x,y; 
int solve (int ans[x][y]);
void check (int a, int b, int* n);
int main(){
	int a,b;
	scanf("%d %d",&x,&y);
	int ans[x][y];
	for(a=0;a<x;a++){
		for(b=0;b<y;b++){
			scanf("%d",&ans[a][b]);
		}
	}
	printf("\nNumber of objects: %d",solve(ans));
	return 0;
}
int solve (int ans[x][y]){
	int retval;
	int a,b;
	for(a=0;a<x;a++){
		for(b=0;b<y;b++){
			if(ans[a][b]==1){
				check(a,b,&ans[a][b]);
				retval++;
	}	}	}
	return retval;
}
void check(int a, int b, int*n){
	if(a>=0 && b>=0 && a<x && b<y && *n==1){
		*n=2;
		check(a-1,b-1,n-y-1);
		check(a-1,b,n-y);
		check(a-1,b+1,n-y+1);
		check(a,b-1,n-1);
		check(a,b+1,n+1);
		check(a+1,b-1,n+y-1);
		check(a+1,b,n+y);
		check(a+1,b+1,n+y+1);
	}	
}
