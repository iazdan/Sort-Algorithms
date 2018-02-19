
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int low, int hi){
	int i = low;
	int j = hi;
	int pivot = a[low];
	while(i <j){
		while(i < hi && a[i] <= pivot)
			i++;
		while(a[j] > pivot)
			j--;
		if(i < j)
			swap(&a[i], &a[j]);
			
	}

	swap(&a[low], &a[j]);
	return j;
}

void quick_sort(int a[], int low, int hi){
	if(low < hi){
		int pivot = partition(a, low, hi);
		quick_sort(a, low, pivot-1);
		quick_sort(a, pivot+1, hi);
	}
}
		

int main(int argc, char **argv)
{
	int a[100];
	int i = 0;
	srand(time(0));
	int size = sizeof(a)/sizeof(a[0]);
	for(i=0;i<size;i++){
		a[i] = rand()%1000;
		printf("%d\t", a[i]);}
	printf("\n\n\n");
	
	quick_sort(a, 0, size-1);
	
	for(i=0;i<size;i++)
		printf("%d\t", a[i]);
	printf("\n");
	
	return 0;
}

