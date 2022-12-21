#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort(char a[],int wordLen);

void main(){
	char string[]="eat ask dog pie did ago doh bye bet zip yes";
	int wordLen = 3;
	sort(string,wordLen);
	printf("%s",string);
}

void sort(char a[],int wordLen){
	int size = strlen(a);
	int x,min,y;
	char temp[wordLen];
	//apply selection sort
	for (x=0;x<size-(wordLen+1);x+=(wordLen+1)){
		min=x;
		for(y=x+(wordLen+1);y<size;y+=(wordLen+1)){
			if(strncmp(a+y,a+min,wordLen)<0){
				min=y;
			}		
		}
		strncpy(temp,a+min,wordLen);
		strncpy(a+min,a+x,wordLen);
		strncpy(a+x,temp,wordLen); 
		//repeat for other elements
	}
}
