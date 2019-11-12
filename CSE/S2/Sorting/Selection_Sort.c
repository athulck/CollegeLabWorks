
#include <stdio.h>
#include <stdlib.h>


/* SELECTION SORT
	Time Complexity : O(n^2)
	Space Complexity: O(n)
*/
void selection_sort(int array[], int n) {

	int smallest_pos;

	for (int i=0; i<n-1; i++) {

		smallest_pos = i;
		
		for (int j=i+1; j<n; j++)
			if (array[j] < array[smallest_pos])
				smallest_pos = j;

		if (smallest_pos != i) {
			
			// Swap
			array[i]            = array[i] + array[smallest_pos];
			array[smallest_pos] = array[i] - array[smallest_pos];
			array[i]            = array[i] - array[smallest_pos];
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

    selection_sort(array, n);
    
    printf("Sorted list :\n");
    for(int i=0;i<n;i++)
		printf("%d\t", array[i]);
}
