
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int *, int);
void print(int *, int);

int main(int argc, char **argv)
{
	int i, array[10];
	srand(time(0));
	int size = sizeof(array)/sizeof(array[0]);
	for(i=0;i<size;i++)
		array[i] = rand()%1000;
		
	print(array,size);
	bucket_sort(array, size);
	print(array, size);
	
	return 0;
}
void print(int *a, int size){
	int i;
	for(i=0;i<size;i++)
		printf("%d\t", a[i]);
	printf("\n");
}
void bucket_sort(int *a, int size){
	int i, j, max = a[0];
	for(i=0;i<size;i++)
		max= (max<a[i])?a[i]:max;
			
	int *buckets = (int*) calloc(max+1, sizeof(int));
	
	
	for(i=0;i<size;i++)
		buckets[a[i]]++;
	
	
	for(i=j=0;i<=max;i++)
		while(buckets[i]>0){
			buckets[i]--;
			a[j++] = i;
		}
}
