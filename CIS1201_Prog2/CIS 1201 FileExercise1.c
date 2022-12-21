#include <stdio.h>
#include <string.h>

typedef struct{
   char Fname[24];
   char Lname[16];
   char MI;
}nametype;

typedef struct{
   unsigned int ID;
   nametype name;
   char currProg[8];
   int yrLevel;
}studtype;

studtype stud[6]={  {1001,"AAAA","AAA",'A',"BSCS",1},
					{1002,"BBBB","BBB",'B',"BSICT",1},
					{1003,"CCCC","CCC",'C',"BSIT",1},
					{1004,"DDDD","DDD",'D',"BSICT",1},
					{1005,"EEEE","EEE",'E',"BSICT",1},
					{1006,"FFFF","FFF",'F',"BSIT",1}, 
				};

void main(){
   FILE * fp;
   char filename[16];
   int ctr;

   printf("\nEnter file name: ");
   gets(filename);
   
   fp = fopen(filename,"w");
   if (fp != NULL){
      fwrite(stud, sizeof(studtype), 6, fp);
      fclose(fp);
   }
}
