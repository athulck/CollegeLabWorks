
#include <stdio.h>
#include <stdlib.h>


/* LINEAR SEARCH 
	Time Complexity: O(n)
	Space Complexity: O(n)
*/
int LinearSearch(int array[], int n, int item) {

	for (int i=0; i<n; i++)
		if (array[i] == item)
			return i;

	return -1;
}

void main() {
	
	int n, item;
	printf("\nEnter the number of elements : ");
	scanf("%d", &n);
	
	int *array = (int *)malloc(n*sizeof(int)); 

	for (int i=0; i<n; i++) {
		printf("\nEnter element #%d : ", i+1);
		scanf("%d", &array[i]);
	}

	printf("\nEnter the element to be searched : ");
	scanf("%d", &item);

	if ( (n = LinearSearch(array, n, item)) < 0 )
		printf("\n%d was not found in the array !\n", item);
	else
		printf("\n%d was found at index %d\n", item, n);

}
