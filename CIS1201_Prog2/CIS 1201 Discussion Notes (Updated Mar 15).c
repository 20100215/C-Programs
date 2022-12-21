#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int changeA_X(List L){
	int count=0;
	LIST temp;
	
	for (temp=L; temp!=NULL; temp=temp->next){
		if(temp->data=='A'){
			temp->data='X';
			count++;
		}
	}
	
	return count;
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
	
	
	Exercise: Multiplication of fractions

	int* multFrac (int a[],int b[]);	
	
	void main(){
		
		int a[2]={2,3};
		int b[2]={3,2};
		int* ans = multFrac(a,b);
		printf("%d %d",ans[0], ans[1]);
		
	}
	
	int* multFrac(int a[],int b[]){
		int* ans = (int*) malloc (2*sizeof(int));
		ans[0]=a[0]*b[0];
		ans[1]=a[1]*b[1];
		
		int larger,smaller,temp;
		if (ans[0]<ans[1]) {larger = ans[1]; smaller=ans[0];}
		else {larger = ans[0]; smaller=ans[1];}
		
		while (smaller >0){
			temp=larger;
			larger=smaller;
			smaller = temp % smaller;
		}
		ans[0]/=larger;
		ans[1]/=larger;
		
		return ans;
	}
	
	
	My problem: Sorting n-letter words alphabetically
	A review of pointers, arrays, chars, strings, sorting algorithms
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
		}
	}
	
	
	Mar 1: Mixing arrays and structures

	typedef struct{
   		char LName[16];
		char FName[24];
		char Mi;
	}Nametype;
	
	typedef struct {
		Nametype name;
		unsigned int ID;
		char Course[8];
		int YrLevel;
	} Studtype;	
	
	typedef struct {
		Studtype Stud[SIZE];
		int count;
	} StudList;
	
	StudList List;
		
	void main(){
		scanf("%d",&List.Stud[4].ID);
		printf("%s",List.Stud[19].name.FName);
		strcpy(List.Stud[0].Course,"BSCS");
		printf("%d",List.count);
		printf("%c",Stud[0].name.FName[49);
	}
	
	March 15 - File functions
	
	FILE *fopen(const char *filename, const char *mode)
		filename - This is the C string containing the name of the file to be opened.
		mode - This is the C string containing a file access mode. It includes - r,w a,r+,w+,a+
		
		This function returns a FILE pointer. Otherwise, NULL is returned and the global
		variable errno is set to indicate the error.
	
	int fclose(FILE *stream)
		stream - This is the pointer to a FILE object that specifies the stream to be closed.
		
		This method returns zero if the stream is successfully closed. On failure, EOF is returned.
		
	size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
		ptr - This is the pointer to a block of memory with a minimum size of size*nmemb bytes.
		size - This is the size in bytes of each element to be read.
		nmemb - This is the number of elements, each one with a size of size bytes.
		stream - This is the pointer to a FILE object that specifies an input stream.
		
		The total number of elements successfully read are returned as a size_t object,
		which is an integral data type. If this number differs from the nmemb parameter,
		then either an error had occurred or the End Of File was reached.
	
	size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
		ptr - This is the pointer to the array of elements to be written.
		size - This is the size in bytes of each element to be written.
		nmemb - This is the number of elements, each one with a size of size bytes.
		stream - This is the pointer to a FILE object that specifies an output stream.

		This function returns the total number of elements successfully returned as a size_t object, 
		which is an integral data type.	If this number differs from the nmemb parameter,
		it will show an error.

	int fseek(FILE *stream, long int offset, int whence)
		stream - This is the pointer to a FILE object that identifies the stream.
		offset - This is the number of bytes to offset from whence.
		whence - This is the position from where offset is added.
		It is specified by one of the following constants -
			SEEK_SET Beginning of file
			SEEK_CUR Current position of the file pointer
			SEEK_END End of file
			
		This function returns zero if successful, or else it returns a non-zero value.

	long int ftell(FILE *stream)
		stream - This is the pointer to a FILE object that identifies the stream.
		
		This function returns the current value of the position indicator. If an error occurs, 
		-1L is returned, and the global variable errno is set to a positive value.
		
	void rewind(FILE *stream)
		stream - This is the pointer to a FILE object that identifies the stream.

	
	March 29 - Linked list basics - definition and accessing/traversal
	
	typedef struct cell{
		char data;
		struct cell* link;
	}Celltype,*LIST;
	
	void main(){
		
		LIST L = (Celltype*)malloc(sizeof(Celltype));
		L->data = 'U';
		LIST temp;
		
		for(temp=L;temp!=NULL;temp=temp->link){
			printf("%c", temp->data);
		}	
	
		for(temp=L;temp!=NULL;){
			printf("%c", temp->data);
			temp=temp->link;
		}
	}

	void displayListElem(LIST L){
		LIST temp;
		for(temp=L;temp!=NULL;temp=temp->link){
			printf("%c", temp->data);
		}
	}

	void insertFirst (List * L, char ch){
		LIST temp = (LIST) malloc (sizeof(cell));
		temp -> data = ch;
		temp -> link = *L;
		*L = temp;
	}
	
	
*/
