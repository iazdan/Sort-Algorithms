#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void heapify(int *a, int n, int size);
void swap(int *x, int *y);
void build_maxheap(int *a, int size);
void heap_sort(int *a, int size);
typedef struct node{
	int data;
	struct node * next;
};

int main(int argc, char **argv)
{
	node *head = (node *)malloc(sizeof(node));
	
	
	srand(time(0));
	int i, a[10];
	for(i=0;i<10;i++){
		a[i] = rand()%100;
		printf("%d\t", a[i]);
	}
	printf("\n");
	heap_sort(a, 10);

	return 0;
}

void heapify(int *a, int parent, int size){
	int max;
	int left  = 2 * parent + 1;
	int right = 2 * parent + 2;
	if(left < size && a[left] > a[parent])
		max = left;
	else 
		max= parent;
	if(right < size && a[right] > a[max])
		max = right;
	if (max != parent){
		swap(&a[max], &a[parent]);
		heapify(a, max, size);
	}	
	
}
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}	
void build_maxheap(int *a, int size){
	int i;
	for(i=(size/2);i>=0;i--)
		heapify(a, i, size);
}
void heap_sort(int *a, int size){
	int i;
	build_maxheap(a, size);
	for(i=size-1;i>=0;i--){
		swap(&a[0], &a[i]);
		printf("%d\t", a[i]);
		heapify(a, 0, i);
	}
}

	
			
	
	
