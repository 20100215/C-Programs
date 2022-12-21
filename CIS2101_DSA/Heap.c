#include<stdio.h>
#include<string.h>

#define SIZE 30

typedef struct{
	int elem[SIZE];
	int lastNdx;  
	int heapLastNdx;
}Heap;

void initialize(Heap *H);
void display(Heap H);

void insertToMin(Heap *H, int elem);
void insertToMax(Heap *H, int elem);

int deleteMin(Heap *H);
void makeMinHeapV1(Heap *H); //insert to initially empty POT
void makeMinHeapV2(Heap *H); //heapify
void makeMaxHeapV1(Heap *H); //insert to initially empty POT
void makeMaxHeapV2(Heap *H); //heapify
void minHeapSort(Heap *H);
void maxHeapSort(Heap *H);

/*Challenge functions*/
int isMinHeap(Heap H);
int isMaxHeap(Heap H);

void main(){
	Heap H = {{23,9,10,4,8,3,44,1,15},8,-1};
	display(H);
	maxHeapSort(&H);
	printf("%d",isMaxHeap(H));
	display(H);
	printf("%d",isMaxHeap(H));
}

void initialize(Heap *H){
	H->lastNdx=-1;
	H->heapLastNdx=-1;
}

void display(Heap H){
	int x,size=H.lastNdx;
	printf("\nContents: ");
	for(x=0;x<=size;x++){
		printf("%d ",H.elem[x]);
	}
	printf("\nElements in heap: %d / %d",H.heapLastNdx+1,H.lastNdx+1);
	printf("\n");
}

void insertToMin(Heap *H, int elem){
	int P,C,isHeap,temp;
	H->elem[++H->heapLastNdx]=elem;
	C=H->lastNdx;
	isHeap=0;
	for(P=(C-1)/2; P>=0 && isHeap==0; P=(C-1)/2){
		if(H->elem[P]<=H->elem[C]){
			isHeap=1;
		} else {
			temp = H->elem[P];
			H->elem[P] = H->elem[C];
			H->elem[C] = temp;
			C = P;
		}
	}
	H->heapLastNdx++;
}

void insertToMax(Heap *H, int elem){
	int P,C,isHeap,temp;
	H->elem[++H->heapLastNdx]=elem;
	C=H->lastNdx;
	isHeap=0;
	for(P=(C-1)/2; P>=0 && isHeap==0; P=(C-1)/2){
		if(H->elem[P]>=H->elem[C]){
			isHeap=1;
		} else {
			temp = H->elem[P];
			H->elem[P] = H->elem[C];
			H->elem[C] = temp;
			C = P;
		}
	}
	H->heapLastNdx++;
}

int deleteMin(Heap *H){
	int min,P,SC,last,isHeap,temp;
	min = H->elem[0];
	H->elem[0] = H->elem[H->heapLastNdx--];
	last=H->heapLastNdx;
	isHeap=0;
	for(P=0; P<=(last-1)/2 && isHeap==0; P=SC){
		if(P*2+2 > last){
			SC = P*2+1;
		} else {
			SC = (H->elem[P*2+1] < H->elem[P*2+2]) ? P*2+1 : P*2+2;
		}
		if(H->elem[P]<=H->elem[SC]){
			isHeap=1;
		} else {
			temp = H->elem[P];
			H->elem[P] = H->elem[SC];
			H->elem[SC] = temp;
		}
	}
	return min;	
}

int deleteMax(Heap *H){
	int max,P,SC,last,isHeap,temp;
	max = H->elem[0];
	H->elem[0] = H->elem[H->heapLastNdx--];
	last=H->heapLastNdx;
	isHeap=0;
	for(P=0; P<=(last-1)/2 && isHeap==0; P=SC){
		if(P*2+2 > last){
			SC = P*2+1;
		} else {
			SC = (H->elem[P*2+1] > H->elem[P*2+2]) ? P*2+1 : P*2+2;
		}
		if(H->elem[P]>=H->elem[SC]){
			isHeap=1;
		} else {
			temp = H->elem[P];
			H->elem[P] = H->elem[SC];
			H->elem[SC] = temp;
		}
	}
	return max;	
}

void makeMinHeapV1(Heap *H){ //insert to initially empty POT
	int P,SC,isHeap,temp,x,y;
	for(x=0;x<=H->lastNdx;x++){
		isHeap=0;
		for(SC=x; SC>0 && isHeap==0; SC=P){
			P=(SC-1)/2;
			if(H->elem[P]<H->elem[SC]){
				isHeap=1;
			} else {
				temp = H->elem[P];
				H->elem[P] = H->elem[SC];
				H->elem[SC] = temp;
			}
		}
		H->heapLastNdx++;
		display(*H);
		printf("%d",isMinHeap(*H));
	}
	
}

void makeMinHeapV2(Heap *H){ //heapify
	int ndx,last,P,SC,isHeap,temp;
	last = (H->lastNdx-1)/2;
	for(ndx=last; ndx>=0; ndx--){
		isHeap=0;
		for(P=ndx; P<=last && isHeap==0; P=SC){
			if(P*2+2 <= H->lastNdx){
				SC = P*2+1;
			} else {
				SC = (H->elem[P*2+1] < H->elem[P*2+2]) ? P*2+1 : P*2+2;
			}
			if(H->elem[P]<=H->elem[SC]){
				isHeap=1;
			} else {
				temp = H->elem[P];
				H->elem[P] = H->elem[SC];
				H->elem[SC] = temp;
			}			
		}
		
		display(*H);
	}
	H->heapLastNdx = H->lastNdx;
}

void makeMaxHeapV1(Heap *H){ //insert to initially empty POT
	int x, lastP, P, BC, temp, isHeap;
	for(x=0;x<=H->lastNdx;x++){
		isHeap = 0;
		for(BC=x; BC>0 && isHeap==0; BC=P){
			P = (BC-1)/2;
			if(H->elem[P] >= H->elem[BC]){
				isHeap=1;
			} else {
				temp = H->elem[P];
				H->elem[P] = H->elem[BC];
				H->elem[BC] = temp;
			}
		}
		H->heapLastNdx++;
		display(*H);
		printf("%d",isMaxHeap(*H));
	}
}

void makeMaxHeapV2(Heap *H){ //heapify
	int x, lastP, P, LC, RC, BC, temp, isHeap;
	lastP = (H->lastNdx-1)/2;
	for(x=lastP; x>=0; x--){
		isHeap=0;
		for(P=x; P<=lastP && isHeap==0; P=BC){
			LC = P * 2 + 1;
			RC = LC + 1;
			if(RC>H->lastNdx){
				BC = LC;
			} else {
				BC = (H->elem[LC] > H->elem[RC]) ? LC : RC;
			}
			if(H->elem[P]>=H->elem[BC]){
				isHeap=1;
			} else {
				temp=H->elem[P];
				H->elem[P] = H->elem[BC];
				H->elem[BC] = temp;
			}
		}
		display(*H);
	}
	H->heapLastNdx = H->lastNdx;
}

void minHeapSort(Heap *H){
	int x;
//	makeMinHeapV1(H);
	makeMinHeapV2(H);
	display(*H);
	for(x=H->lastNdx;x>0;x--){
		H->elem[x]=deleteMin(H);
		display(*H);
	}
}

void maxHeapSort(Heap *H){
	int x;
	makeMaxHeapV1(H);
//	makeMaxHeapV2(H);
	display(*H);
	for(x=H->lastNdx;x>0;x--){
		H->elem[x]=deleteMax(H);
		display(*H);
	}
}


int isMinHeap(Heap H){
	int P,SC,isHeap=1,x,last=(H.lastNdx-1)/2;
	for(x=0;x<=last && isHeap==1;x++){
		P=x;
		if(P*2+2 > H.lastNdx){
			SC = P*2+1;
		} else if (P*2+1 <= H.lastNdx){
			SC = (H.elem[P*2+1] < H.elem[P*2+2]) ? P*2+1 : P*2+2;
		} else {
			SC = P;
		}
		if(H.elem[P]>H.elem[SC]){
			isHeap=0;
		}
	}
	return isHeap;
}

int isMaxHeap(Heap H){
	int P,SC,isHeap=1,last=(H.lastNdx-1)/2;
	for(P=0;P<=last && isHeap==1;P++){
		isHeap=1;
		if(P*2+2 > H.lastNdx){
			SC = P*2+1;
		} else if (P*2+1 <= H.lastNdx){
			SC = (H.elem[P*2+1] < H.elem[P*2+2]) ? P*2+1 : P*2+2;
		} else {
			SC = P;
		}
		if(H.elem[P]<H.elem[SC]){
			isHeap=0;
		}
	}
	return isHeap;
}
