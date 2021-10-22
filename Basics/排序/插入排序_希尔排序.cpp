#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *a, int n){
	int x, y, z, tmp, tmp_i;
	for(x=(n-1)/2; x>=1; x=x/2){
		for(y=x; y<n; y++){
			tmp = a[y];
			for(z=y-x; z>-1; z=z-x){
				if(a[z] > tmp){
					a[z+x] = a[z];
					a[z] = tmp;
				}
				else {
					a[z+x] = tmp;
					break;
				}
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
	
	InsertSort(a,10); 
	
	printf("\nÅÅÐòºó: ");
	for(i=0; i<10; i++){
		printf("%d ", a[i]);
	}
	
	return 0;
} 
