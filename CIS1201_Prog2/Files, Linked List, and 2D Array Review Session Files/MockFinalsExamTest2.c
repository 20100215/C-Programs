#include<stdio.h>
#define N 5

void main(){
	FILE* fp = fopen("Test2.bin","wb");
    int ctr, x, y = sizeof(int), z;
    if(fp!=NULL){
      for(ctr=x=0; ctr<N; ctr++){
         x = N % (ctr + 3) + N;
         if(x==5)
            fseek(fp,0,0);
         fwrite(&x,y,1,fp);
      }
      z = ftell(fp);
      fclose(fp);
    }
    
    fp = fopen("Test2.bin","r");
    while(fread(&x,y,1,fp)!=0){
    	printf("%d ",x);
	}
	printf("   %d",ftell(fp));
	fclose(fp);
}
