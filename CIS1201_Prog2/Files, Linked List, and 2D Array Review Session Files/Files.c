#include<stdio.h>
#include<string.h>

typedef struct{
	int ID;
	char name[16];
	char course[8];
	int yrLevel;
}person; /* size: 32 bytes */

person A[3] = { {1000,"DDDD","BSIT",1},
				{2000,"BBBB","BSCS",2},
				{3000,"CCCC","BSIT",3},
			  };
int count = sizeof(A)/sizeof(person); 
/*count = 3*/

void main(){
	char filename[10];
	printf("Enter filename: ");
	gets(filename);
	FILE* fp = fopen(filename,"w");
	if (fp!=NULL){
		fwrite(A,sizeof(person),count,fp);		
		fclose(fp);
	}
}
