#include<stdio.h>
float getGrade(int score);

void main(){
	int score;
	float grade;
	do{
		printf("Enter a score: ");
		scanf("%d",&score);
		grade = getGrade(score);
		
		if(grade != -1){
			if(grade <= 3.0){
				printf("Passed");
			} else {
				printf("Failed");
			}
		} else {
			printf("Error. Try again\n");
		}
	}while(grade==-1);
}

float getGrade(int score){
	float ret;
	if(score >= 0 && score <=40){
		ret = 1 + 0.1 * (40 - score);
	} else {
		ret = -1;	
	}
	return ret;
}
