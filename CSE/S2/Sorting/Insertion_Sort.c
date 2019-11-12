#include <stdio.h>
#include <stdlib.h>



/* INSERTION SORT
	Time Complexity : O(n^2)
	Space Complexity: O(n)
*/
void insertion_sort(int array[], int n) {

	for (int i=1; i<n-1; i++)
		for (int j=i-1; j>=0; j--)
			if (array[j] > array[j+1]) {
				
				// Swapping
				array[j]   = array[j] + array[j+1];
				array[j+1] = array[j] - array[j+1];
				array[j]   = array[j] - array[j+1];
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

    insertion_sort(array, n);
    
    printf("Sorted list :\n");
    for(int i=0;i<n;i++)
		printf("%d\t", array[i]);
}
