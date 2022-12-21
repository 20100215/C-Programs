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

void main(){
   FILE * fp;
   char filename[16];
   studtype stud;
   int ctr=0;

   printf("\nEnter file name: ");
   gets(filename);

   fp = fopen(filename,"r+");

   if (fp != NULL){
      while(fread(&stud, sizeof(studtype), 1, fp) != 0){
         if(strcmp(stud.currProg,"BSICT")==0){
            strcpy(stud.currProg,"BSIS");
			fseek(fp,ctr*sizeof(studtype),SEEK_SET);
			fwrite(&stud, sizeof(studtype), 1, fp);
			fseek(fp,(ctr+1)*sizeof(studtype),SEEK_SET); /* Tried placing (++ctr)*sizeof(studtype) then taking out the ctr++ line after, but it didnt work. SEEK_CUR based seeking does not work also. */
         }
         ctr++;
      }
      fclose(fp);
   }
}

