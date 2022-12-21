#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

typedef struct{
	int numCount;
	char text[SIZE];
}numStatList;

typedef enum{
	TRUE, FALSE
}boolean;

boolean checkNum (numStatList* L){
	boolean ret;
	int x, count=0;
	
	for(x=0;L->text[x]!='\0';x++){
		if(isdigit(L->text[x])!=0){
			for(;L->text[x]!='\0' && isdigit(L->text[x])!=0;x++){}
			count++;
		}
	}
	
	if (L->numCount != count){
		ret = FALSE;
		L->numCount = count;
	} else {
		ret = TRUE;
	}
	
	return ret;
}

void main(){
	
	numStatList l1 = {6,"aa123aa456aa789!!"};
	numStatList l2 = {6,"aa123aa456aa789!!"};
	boolean b1 = checkNum(&l1);
	boolean b2 = checkNum(&l2);
	
	printf("%d %d %d",b1,b2,l2.numCount);
}


/*
	Assignment 1: 
	FUNCTION SPECIFICATION: The function compute will accept as parameters two valus A and B.
	If A is greater than B, the function will multiply A and B, and put the product in A;
	otherwise, the function will put the sum of A and B in A.

	void main(){
		int num1 = 10;
		int num2 = 10;
		compute (&num1, num2);
	}
	
	void compute (int *A, int B) {
		if (*A > B) {
    		*A *= B; 
   		} else { 
    		*A += B;
   		}
	}
	
	
	Assignment 2:
	FUNCTION SPECIFICATION: Function findEven() will accept as parameters an array of positive integers and its size.
	It will find all the even numbers and put them in another array which is to be returned to the calling function.
	In addition, put negative 1 at the end of the array containing the even numbers.
	
	void main(){
		int Arr[] = {1,2,3,4,5,6,7,8,9};
		int size = 9;
		int* Ans = findEven(Arr,size);
		displayArray(Ans,size+1);
		getch();
	}

	int* findEven (int A[], int size){
		int x;
		int y=0;
		int* retval = (int*)malloc((size+1)*sizeof(int));
		for (x=0;x<size;x++){
			if(A[x]%2==0){
				retval[y]=A[x];
				y++;
			}
		}
		retval[y]=-1;
		retval = (int*) realloc (retval, y+1
		return retval;
	}
	
	
	Discussion: Feb 8 - Strings

	char name1[16];
	char name2[16];
	printf("%d\n",strlen(name1));
	printf("%d\n",strlen(name2));
	gets(name1);
	printf("%s\n",name1);
	puts(name1);
	printf("%d\n",strlen(name1));
	scanf("%[^\n]",name2);
	printf("%s\n",name2);
	puts(name2);
	printf("%d\n",strlen(name2));
	
	void main(){
		char str1[4]="USC";
		char str2[4]="ABC";
		printf("%x %x %x \n", str1,str2,str3);
		strcpy(str2,str1);
		puts(str1);
		puts(str2);
	}

	void main(){
		char *str1="USC";
		char *str2="ABC";
		printf("%x %x %x \n", str1,str2,str3);
		strcpy(str2,str1);
		puts(str1);
		puts(str2);
	}
	
	
	Feb 10: Experimenting with Strings
	
	void main(){
		char string[5];
		string[3] = 'A';
		string[4] = '\0';
		puts(string);
		printf("%d",string[0]); 
		
		char a[15]="Good morning";
		char b[15];
		strcpy(b,a+5);
		puts(b);
	}	
	
	
	Feb 10: Sorting algorithms
	
	void bubbleSort(int arr[], int n);
	void selectionSort(int arr[], int n);
	void insertionSort(int arr[], int n);
	void swap(int *xp, int *yp);

	void bubbleSort(int arr[], int n)  
	{  
    	int i, j;  
	    for (i = 0; i < n-1; i++)      
	      
	    // Last i elements are already in place  
	    for (j = 0; j < n-i-1; j++)  
	        if (arr[j] > arr[j+1])  
	            swap(&arr[j], &arr[j+1]);  
	            
	    //can simplify algorithm by breaking if there is no swapping in inner loop	
	}  

	void selectionSort(int arr[], int n)  
	{  
	    int i, j, min_idx;  
  
    	// One by one move boundary of unsorted subarray  
    	for (i = 0; i < n-1; i++)  
    	{  
    	    // Find the minimum element in unsorted array  
    	    min_idx = i;  
    	    for (j = i+1; j < n; j++)  
    	    if (arr[j] < arr[min_idx])  
    	        min_idx = j;  
  
        	// Swap the found minimum element with the first element  
        	swap(&arr[min_idx], &arr[i]);  
    	}  
    
    	//need to go through all elements before swapping
	} 

	void insertionSort(int arr[], int n)  
	{  
	    int i, key, j;  
	    for (i = 1; i < n; i++) 
	    {  
	        key = arr[i];  
	        j = i - 1; 	 
	  
    	    /* Move elements of arr[0..i-1], that are  
    	    greater than key, to one position ahead  
    	    of their current position *//*
    	    while (j >= 0 && arr[j] > key) 
    	    {  
    	        arr[j + 1] = arr[j];  
    	        j = j - 1;  
    	    }  
    	    arr[j + 1] = key;  
    	}  
	}  

	void swap(int *xp, int *yp)  
	{  
	    int temp = *xp;  
	    *xp = *yp;  
	    *yp = temp;  
	}  
	
	
	Assignment 4: 
	FUNCTION SPECIFICATION: Create a function that will group the odd integers in the first
	partition of the array and the even integers in its last partition
	NOTE: Answers may vary, different sorting algorithms can be implemented.
	
	void main(){
		int a[]={2,4,6,1,5,3};
		int size = 6;
		sortoddeven(a,size);
	}	

	void sortoddeven(int a[], int size){
		int lndx=0;
		int rndx=size-1;
		int temp;
		while (lndx<rndx){
			for (;a[lndx]%2!=0;lndx++){}
		for (;a[rndx]%2==0;rndx--){}
			if(lndx<rndx){
				temp = a[lndx];	
				a[lndx]=a[rndx];
				a[rndx]=temp;
		}
	
		for (lndx=0;lndx<size;lndx++){
			printf("%d ",a[lndx]);
		}

	}
	
	
	Feb 17 - Accessing, Manipulating Passing, and Returning Structures
	#include <stdio.h>
	#include <string.h>

	struct infData {
		char fname[24];
		char MI;
		char lname[16];
		int age;
		char gender;
	};

	struct infData inputData();
	void displayData (struct infData info);
	
	void main(){
		struct infData info;
		
		info = inputData(); 
		displayData(info);
	}
	
	struct infData inputData(){
		
		struct infData info;
		
		puts("Input first name:");
		scanf("%[^\n]s",info.fname);
		
		puts("Enter Middle initial");
		fflush(stdin);
		scanf("%c", &info.MI);
		
		puts("Input last name:");
		fflush(stdin);
		scanf("%[^\n]s",info.lname);
		
		puts("Input age:");
		fflush(stdin);
		scanf("%d", &info.age);
		
		puts("Input gender (M/F):");
		fflush(stdin);
		scanf("%c", &info.gender);
		
		return info;
	}	
	
	void displayData (struct infData info){
		puts("You have entered:");
		printf("%s %c. %s\n", info.fname, info.MI, info.lname);
		printf("Age: %d   Gender: %c",info.age, info.gender);
	}
*/
