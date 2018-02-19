
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid, int hi){
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = hi - mid;
	int L[n1], R[n2];
	
	for(i=0; i<n1;i++)
		L[i] = a[low+i];
	for(i=0;i<n2;i++)
		R[i] = a[mid+1+i];
	
		
	i=0, j=0, k=low;
	
	while(i<n1 && j<n2)
		if (L[i]<R[j])
			a[k++] = L[i++];
		else
			a[k++] = R[j++];
	while(i < n1)
		a[k++] = L[i++];
	while(j < n2)
		a[k++] = R[j++];
}
		
		
void merge_sort(int a[], int low, int hi){
	if(low < hi){
		int mid = low + (hi - low)/2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, hi);
		merge(a, low, mid, hi);
	}
}
	
int main(int argc, char **argv)
{
	srand(time(0));
	int a[1000000];//={100, 200, 40,100000,3,-1,3,5,6,0};
	int i=0;
	int a_size = sizeof(a)/sizeof(a[0]);
	for(i=0;i<a_size;i++)
		a[i] = rand()%1000000;
	
	for(i=0; i<a_size;i++)
		printf("%d\t",a[i]);
	printf("\n");
	
	merge_sort(a, 0, a_size-1);
	
	for(i=0; i<a_size;i++)
		printf("%d\t",a[i]);
	printf("\n");
	
	return 0;
}

