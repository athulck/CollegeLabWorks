#include<stdio.h>
#include<stdlib.h>


/* BINARY SEARCH 
	Time Complexity : O(log(n))
	Space Complexity: O(n)
*/
int BinarySearch(int array[], int n, int item) {

	int beg = 0, end = n-1, mid;

	while (beg < end) {

		mid = (beg + end)/2;
		if (array[mid] < item)
			beg = mid + 1;    
		else if (item < array[mid])
			end = mid - 1;
		else return mid;
	}
	return -1;
}


void bubble_sort(int array[], int n) {

	for (int i=0; i<n-1; i++)
		for (int j=0;j<n-i-1;j++) {

			if (array[j] > array[j+1]) {

				array[j] = array[j] + array[j+1];
				array[j+1] = array[j] - array[j+1];
				array[j] = array[j] - array[j+1];
			}
		}
}


void main() {

	int n;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	
	int *array = (int *)malloc(n*sizeof(int));
	for (int i=0; i<n; i++) {
		
		printf("\nEnter element #%d : ", i+1);
		scanf("%d", &array[i]);
	}

	bubble_sort(array, n);

	// Print sorted array
	printf("\n");
	for (int i=0; i<n; i++)
		printf("%d\t", array[i]);
	printf("\n");

	int item;
	printf("\nEnter the search element : ");
	scanf("%d", &item);

	if ( (n = BinarySearch(array, n, item)) < 0 )
		printf("\n%d was not found in the array !\n", item);
	else
		printf("\n%d was found at index %d\n", item, n);
	 
}
