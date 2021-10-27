#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *a, int n){
	int tmp, i, j;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(a[j] < a[i]){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
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
