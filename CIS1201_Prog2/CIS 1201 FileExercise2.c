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

void displayStudent (studtype stud);

void main(){
   FILE * fp;
   char filename[16];
   studtype stud;

   printf("\nEnter file name: ");
   gets(filename);

   fp = fopen(filename,"r");

   if (fp != NULL){
      while(fread(&stud, sizeof(studtype), 1, fp) != 0){
         displayStudent(stud);
      }
      fclose(fp);
   }
}

void displayStudent (studtype stud){
   printf("%-8d  ", stud.ID);
   printf("%-24s  ",stud.name.Fname);
   printf("%-16s  ",stud.name.Lname);
   printf("%c.  ",stud.name.MI);
   printf("%-8s  ",stud.currProg);
   printf("%d\n",stud.yrLevel);
}
