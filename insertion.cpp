#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define size 100000
int iarray[size];

void initialize(int iarray[]) {
	
	srand(time(NULL));// set starting a random number
	for (int i = 0; i < size; i++) {
		iarray[i] = rand() % 100000 + 1; // choose random number
	}
}
// qucik function

void quick_sort(int start, int end) {
	if (start >= end)
	return;
	int key = start, i = start + 1, j = end;
	
	while (i <= j) {
		while (i <= end && iarray[i] <= iarray[key]){
		 i++;
		 
		 }
		while (j > start && iarray[j] >= iarray[key]){
		j--;
		
		}
		if (i > j) {
	
		swap(&iarray[key], &iarray[j]);
		}else{
			
		 swap(&iarray[i], &iarray[j]);
		}
	}
	quick_sort(start, j - 1);
	
	quick_sort(j + 1, end);

}

// insertion_sort function  
void insertion_sort(int arr[], int n)
{
	int in, out;
	for (out = 1; out < n; out++){
		double temp=arr[out];
		in=out;
		while(in>0&&arr[in-1]>=temp){
			arr[in]=arr[in-1];
			--in;
			
		}
		arr[in]=temp;
	}
	printf("The array is sorted using insertion_sort in %u seconds\n", clock());
}

void swap(int* one, int* two) {
	int temp = *one;
	*one = *two;
	*two = temp;
}




int main() {
	int array[size];
	
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100000 + 1;
	}
	
	printf("Array of 100000 random numbers is initialized\n");
	
	insertion_sort(array, size);
	
	initialize(iarray);
	
	quick_sort(0, size - 1);
	
	printf("The array is sorted using quick sort in %u seconds", clock());
	
	return 0;
}
