#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *a, int n){
	int x, y, tmp;
	for(x=0; x<n-1; x++){
		for(y=n-1; y>x; y--){
			if(a[y] < a[y-1]){
			 	tmp = a[y];
				a[y] = a[y-1];
				a[y-1] = tmp;
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
