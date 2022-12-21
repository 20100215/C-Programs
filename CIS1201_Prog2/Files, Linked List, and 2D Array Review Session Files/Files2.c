#include<stdio.h>
#include<string.h>

typedef struct{
	int ID;
	char name[16];
	char course[8];
	int yrLevel;
}person; /* size: 32 bytes */

void displayPerson(person temp);

void main(){
	char filename[10];
	printf("Enter filename: ");
	gets(filename);
	person temp;
	
	FILE* fp = fopen(filename,"r");
	if (fp!=NULL){
		while(fread(&temp,sizeof(person),1,fp)!=0){
			displayPerson(temp);
		}
		fclose(fp);
	}
}

void displayPerson(person temp){
	printf("%-4d ",temp.ID);
	printf("%-16s ",temp.name);
	printf("%-8s ",temp.course);
	printf("%d\n",temp.yrLevel);
}

