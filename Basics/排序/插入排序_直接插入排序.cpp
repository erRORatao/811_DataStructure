#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *a, int n){
	int x, y, tmp;
	for(x=1; x<n; x++){
		tmp = a[x];
		for(y=x-1; y>-1; y--){
			if(a[y] > tmp) 
				a[y+1] = a[y];
			else {
				a[y+1] = tmp;
				break;
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
