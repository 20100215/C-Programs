#include<stdio.h>
void BubbleSort(int arr[],int size);
void display(int arr[],int size);
void SelectionSort(int arr[],int size);
void insertLast(int arr[],int * size,int newElem,int MaxSize);
void insertSortedV1(int arr[],int * size,int newElem,int MaxSize);
void insertSortedV2(int arr[],int * size,int newElem,int MaxSize);
void findDelete(int arr[],int * size,int newElem,int MaxSize);

int main(){
	int array1[5] = {10,45,12};
	int count=3;
	/*Printing values*/
	display(array1,3);
	
	insertLast(array1,&count, 60,5);
	
	display(array1,count);
	
	SelectionSort(array1,count);
	
	display(array1,count);
	
	insertSortedV2(array1,&count,2,5);
	
	display(array1,count);
	
	findDelete(array1,&count,12,5);
	
	display(array1,count);
	
	return 0;
}

void display(int arr[],int size){
  int x;
  
  printf("\nSHOWING VALUES OF ARRAY\n");
  for(x=0;x<size;x++){
  	printf("%d ",arr[x]);
  }
}

void BubbleSort(int arr[],int size){
	int BE,SE,temp;
	
	for(BE=0;BE<size;BE++){
		for(SE=size-1;SE>BE;SE--){
			if(arr[SE-1]>arr[SE]){
				temp = arr[SE-1];
				arr[SE-1] = arr[SE];
				arr[SE] = temp;
			}
		}
	}
}

void insertLast(int arr[],int * size,int newElem,int MaxSize){
	if(*size < MaxSize){
		arr[*size] = newElem;
		(*size)++;
	}
}

void SelectionSort(int arr[],int size){
	int SE,BE,T,temp;
	
	for(BE=0;BE<size;BE++){
		for(SE=BE,T=SE+1 ; T < size ; T++){
			if(arr[T]<arr[SE]){
				SE=T;
			}
		}
		if(arr[BE]>arr[SE]){
			temp = arr[BE];
			arr[BE] = arr[SE];
			arr[SE] = temp;
		}
	}
}

void insertSortedV1(int arr[],int * size,int newElem,int MaxSize){
	int x;
	/*checking for available space*/
	if(*size<MaxSize){
		for(x=(*size)-1;x>=0 && arr[x]>newElem;x--){
			arr[x+1] = arr[x];
		}
		arr[x+1] = newElem;
		(*size)++;
	}
	
}

void insertSortedV2(int arr[],int * size,int newElem,int MaxSize){
	int x,SE;
	if(*size<MaxSize){
		/*To find position of where newElem should be inserted*/
		for(x=0;x<(*size) && arr[x]<newElem;x++){}
		
		/*shifting the elements to make way for newElem*/
		for(SE=(*size);SE>x;SE--){
			arr[SE] = arr[SE-1];
		}
		arr[x]=newElem;
		(*size)++;
		
	}
}

void findDelete(int arr[],int * size,int newElem,int MaxSize){
	int x;
	/*making sure array is not empty*/
	if(*size>0){
		
		for(x=0; x<(*size) && arr[x]!=newElem;x++){}
		
		if(x<(*size)){
			for(;x<*size;x++){
				arr[x]=arr[x+1];
			}
			--(*size);
		}
		
	}
}


/*  

REMINDER:

passby reference == passby address

passby copy == passby value

    [0]  [1]  [2] [3] [4]  [5]
     [ 12 , 34, 56, 60 ,  ,  ]
       
     count :4,
     maxSize: 6,
     newElem: 12
     
     2 ways to do insert Sorted:
     1. 2 for loops
     	-the 1st loop is used to know the POSITION
     	-the 2nd loop is used to shift some elements to the right
     	  TO MAKE SPACE for the new element
    
    2. 1 loop
     
     
     REMINDER: when inserting, check if there is
     still SPACE (available SPACE)
     
     whenever we insert something
     in the middle(or if we're inserting
	 in a sorted array and
	 putting something in the
	 middle, we shift SOME elements
     to the right
     (this is to give space or the proper space)
     
     which implies that
     
     whenever we delete something in the middle,
     we shift some elements to the left
     (this is to OVERLAP something)
     
     
     int array[6]={23,45,69,78,89};
     int count=5;
     
     wanna delete 45
     1. check if there are any elements to begin with
	 2. we have to FIND if the element exists
     3. if it does, we then delete it
     
     
     to insert Last, we just increment
     our COUNT variable
     then use that variable as the 
     [index] when we insert our new
     element


	TLDR:
	when we insert, we check if its not FULL
	when we delete, we check if its not EMPTY
*/


