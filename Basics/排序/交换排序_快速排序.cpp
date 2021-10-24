#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *a, int high, int low){
	int tmp, n;
	n = high;
	tmp = a[low];
	if(high <= low) return;
	while(high > low){
		while(high > low && a[high] > tmp) high--;
		a[low] = a[high];
		while(high > low && a[low] < tmp) low++;
		a[high] = a[low];
	}
	a[high] = tmp;
	InsertSort(a, high, 0);
	InsertSort(a, n, high+1);
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
	
	InsertSort(a, 9, 0); 
	
	printf("\nÅÅÐòºó: ");
	for(i=0; i<10; i++){
		printf("%d ", a[i]);
	}
	
	return 0;
} 
