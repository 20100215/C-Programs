#include<stdio.h>

// float computeBMI(float weight, float height);
void computeBMI(float weight, float height, float* BMI);
void workout1(float* weight, int days);
void workout2(float* weight, int days);
void workout3(float* weight, int days);
void workout4(float* weight, int days);

int main(){
  float weight,height,BMI;
  int days;

  printf("Enter the weight (pounds): ");
  scanf("%f",&weight);
  printf("Enter the height (inches): ");
  scanf("%f",&height);
  printf("Enter Days Trained: ");
  scanf("%d",&days);
  // BMI = computeBMI(weight,height);
  computeBMI(weight,height,&BMI);
  printf("\nThe BMI is %.1f",BMI);
  
  if (BMI < 18.5){
    workout1(&weight, days);
  } else if (BMI >= 18.5 && BMI <= 24.9){
    workout2(&weight, days);
  } else if (BMI >= 25 && BMI <= 29.9){
    workout3(&weight, days);
  } else {
    workout4(&weight, days);
  }
  
  printf("\n\nWeight after training: %.3f",weight);
  return 0;
}


void computeBMI(float weight, float height, float* BMI){
  *BMI = 703*(weight/(height*height));
}

void workout1(float* weight, int days){
  float weightGained;
  weightGained = days*0.25;
  *weight += weightGained;
}

void workout2(float* weight, int days){
  float weightGained;
  weightGained = (float)days/7.0*0.05;
  *weight += weightGained;
}

void workout3(float* weight, int days){
  float weightLost;
  weightLost = (float)days/7.0;
  *weight -= weightLost;  
}

void workout4(float* weight, int days){
  float weightLost;
  weightLost = days/7.0*2.5;
  *weight -= weightLost;  
}

// float computeBMI(float weight, float height){
//   float BMI;
//   BMI = 703 x (weight/(height*height));
//   return BMI;
// }

// float computeBMI(float weight, float height){
//   return 703 x (weight/(height*height));
// }

// teddy was here