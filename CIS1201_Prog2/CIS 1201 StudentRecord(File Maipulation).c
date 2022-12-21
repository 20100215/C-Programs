/* The includes and defines */
#include <stdio.h>
#include <string.h>
#define SIZE 50

/* Definition of Structure */
typedef struct{
    char LName[16];
    char FName[24];
    char MI;
}Nametype;

typedef struct{
	Nametype Name;
	unsigned int ID;
	char Course[8];
	int Year;
}Studtype;

typedef struct{
    Studtype Stud[SIZE];
	int count;
}Studlist;

int main () {
	
	//Ask miss the question read type, post the code.
	Studlist currentList =  {{	{{"Dayata","Wayne Matthew",'A'},20100215,"BSCS",1},
							{{"Dayata","Vladymir",'A'},20100231,"BSCS",1},
							{{"Sayson","Elikah Belle",'C'},20100333,"BSIT",1},
							{{"Dayata","Aylmer Leif",'S'},20100170,"BSCS",1},
							{{"Paguntalan","Keziah",'E'},20100292,"BSA",1}
						}, 5};
	
	int x;
	Studtype test;
	FILE *fp;
	fp = fopen("newtest","w+");  //working: rb, rb+, wb+, ab+, the rest gives garbage
	if (fp!=NULL){
		for(x=0;x<5;x++){
			fwrite(&currentList.Stud[x],sizeof(Studtype),1,fp);
		}
		rewind(fp);
		for(x=0;x<5;x++){
			fseek(fp,x*sizeof(Studtype),0);
			fread(&test,sizeof(Studtype),1,fp);
			if(strcmp(test.Name.LName,"Dayata")==0){
				strcpy(test.Name.LName,"Lim");
			}	
			fseek(fp,x*sizeof(Studtype),0);
			fwrite(&test,sizeof(Studtype),1,fp);
		}
		rewind(fp);
		for(x=0;x<5;x++){
			fread(&test,sizeof(Studtype),1,fp);
			printf("%-18s ", test.Name.LName);
			printf("%-26s ", test.Name.FName);
			printf("%-3c ", test.Name.MI);
			printf("%-10d ", test.ID);
			printf("%-10s ", test.Course);
			printf("%d\n", test.Year);  			
		}
		
		fclose(fp);
	}
	return 0;
}
