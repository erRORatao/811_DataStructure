#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *a, int n){
	int high, low, mid, tmp;
	int x, y;
	for(x=1; x<n; x++){
		tmp = a[x];
		low = 0;
		high = x-1;
		while(high >= low){
			mid = (high + low)/2;
			if(a[mid] >= tmp)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for(y=x-1; y>=high+1; y--)
			a[y+1] = a[y];
		a[high+1] = tmp;
		
	} 
}

int main(){
	int a[10];
	int i;
	for(i=0; i<10; i++){
		a[i] = rand();
	}
	printf("ÅÅÐòÇ°: ");
	for(i=0; i<10; i++){
		printf("%d ", a[i]);
	}
	
	InsertSort(a, 10); 
	
	printf("\nÅÅÐòºó: ");
	for(i=0; i<10; i++){
		printf("%d ", a[i]);
	}
	
	return 0;
} 
