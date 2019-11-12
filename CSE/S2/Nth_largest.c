/*
Progrm to find the N-th largest number in a given set of numbers.

Time Complexity  : O(n^2) - Selection Sort
Space Complexity : O(n)
*/

#include <stdio.h>
#include <stdlib.h>

void main() {

	// Step 1: Reading 'n' elements from the user

	int n;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);

	int *list = (int *)malloc(n*sizeof(int));
	for (int i=0; i<n; i++) {

		printf("\nEnter element #%d : ", i+1);
		scanf("%d", &list[i]);
	}

	// Step 2: Reading the value of 'N' from the user

	int N;
	printf("\nEnter the value of 'N' (for finding the N-th largest number) : ");
	scanf("%d",&N);

	// Step 3: Check the edge condition
	
	if ( (N <= 0) || (N > n) ) {
		printf("\n[Error] Condition (1 <= N <= %d) should be satisfied !", n);
		exit(0);
	}
	
	// Step 4: Sort the list (Selection Sort)

	int small_i;
	for (int i=0; i<n; i++) {

		small_i = i;

		for (int j=i+1; j<n; j++) {
			if (list[j] < list[small_i])
				small_i = j;
		}

		if (small_i != i) {
			// Swap
			list[small_i] = list[small_i] + list[i];
			list[i] = list[small_i] - list[i];
			list[small_i] = list[small_i] - list[i];
		}
	}
	
	// Step 5: Displaay the N-th largest element on the list

	printf("\n>The '%d'-th/nd/rd largest number is : %d \n", N, list[n-N]);
}