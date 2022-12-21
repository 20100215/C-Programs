#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
	char name[24];
	int Stewartisguapo;
}AA;

typedef AA Atable[20];

void initialize(Atable *A){
	char x[10]="Hello";
	int ctr;
	for(ctr=0;ctr<20;ctr++){
		strcpy((*A)[ctr].name,x);
	}
}

void initialize2(Atable A){
	char x[10]="Hello2";
	int ctr;
	for(ctr=0;ctr<20;ctr++){
		strcpy(A[ctr].name,x);
	}
}

void print(Atable *A){
	int ctr;
	for(ctr=0;ctr<20;ctr++){
		printf("%s\n",((*A)[ctr].name));
	}
	printf("\n\n");
}

void print2(Atable A){
	int ctr;
	for(ctr=0;ctr<20;ctr++){
		printf("%s\n",(A[ctr].name));
	}
	printf("\n\n");
}

void main(){
	
	char ch = '1';
	printf("%d", isalpha(ch) || isspace(ch));
	
	
	Atable table;
	initialize(&table);
	print(&table);
	print2(table);
	
	Atable table2;
	initialize2(table2);
	print(&table2);
	print2(table2);
}
