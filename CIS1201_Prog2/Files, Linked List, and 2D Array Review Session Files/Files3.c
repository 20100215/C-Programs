#include<stdio.h>
#include<string.h>

/*Scenario: Changing all instances of BSIT course to BSICT*/

typedef struct{
	int ID;
	char name[16];
	char course[8];
	int yrLevel;
}person; /* size: 32 bytes */

void main(){
	char filename[10];
	printf("Enter filename: ");
	gets(filename);
	person temp;
	int ctr=0;
	
	FILE* fp = fopen(filename,"r+");
	if (fp!=NULL){
		while(fread(&temp,sizeof(person),1,fp)!=0){
			if(strcmp(temp.course,"BSIT")==0){
				strcpy(temp.course,"BSICT");
				fseek(fp,ctr*sizeof(person),SEEK_SET);
				fwrite(&temp,sizeof(person),1,fp);
				fseek(fp,(ctr+1)*sizeof(person),SEEK_SET);
			}
			ctr++;
		}
		fclose(fp);
	}
}

