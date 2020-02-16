//Program to depict different ways of sorting

#include<stdio.h>
#include<stdlib.h>

// ------------- O(n) Sorts -----------------------//
void bubble_sort(int arr[],int n)
{
	for (int i=0; i<n-1; i++)           //Condition could be written better
	{
		for (int j=0; j<n-i-1; j++)
		{
			if( arr[j] > arr[j+1] )
			{
				arr[j] = arr[j] + arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			}
		}
	}
}



void insertion_sort(int arr[], int n)
{
	int key = 0;
	for (int i=1; i<n; i++)
	{
		key = arr[i];                          //Item to be put in the sorted part
		int j = i-1;
		for (; (j>=0) && (arr[j] > key); j--)
			arr[j+1] = arr[j];
		arr[j+1] = key;	
	}
}


/*
void insertion_sort(int arr[], int n)
{
	int item = 0;
	for (int i=1; i<n; i++)
	{
		item = arr[i];                           //Item to be put in the sorted part
		for (int j=i-1; (j>=0) && (arr[j] > item) ; j--)
		{
			arr[j] = arr[j] + arr[j+1];
			arr[j+1] = arr[j] - arr[j+1];
			arr[j] = arr[j] - arr[j+1];
		}
	}
}



Step 1: Assume that ith position is having the smallest element
Step 2: With that assumption, find the position of the smallest element in the array wrt the assumed element
Step 3: If our assumption was wrong, swap the elements in the assumed and actual positions 
*/
void selection_sort(int arr[], int n)
{
	int min_pos;
	for (int i=0; i<n-1; i++)
	{
		min_pos = i;

		// Find the position of the smallest element
		for (int j=i+1; j<n; j++)
			if (arr[min_pos] > arr[j])
				min_pos=j;
		
		if(min_pos != i)
		{
			arr[min_pos] = arr[min_pos] + arr[i];
			arr[i] = arr[min_pos] - arr[i];
			arr[min_pos] = arr[min_pos] - arr[i];
		}
	}
}

// ------------- O(nlog(n)) Sorts -----------------------//

// Quick Sort
int partition(int buff[], int p, int r)
{
	int pivot = buff[r];
	int i = p, temp;
	for(int j=p; j<=r-1; j++)
	{
		if(buff[j] < pivot)
		{
			// Arranging all elements smaller than pivot to the beginning of the buffer
			if (i != j) {
				// Swap
				temp = buff[i];
				buff[i]=buff[j];
				buff[j]=temp;
			}
			i++;
		}
	}
	//Placing pivot in the correct position
	temp = buff[i];
	buff[i]=buff[r];
	buff[r]=temp;
	return i; //Returns the correct position of the pivot
}

void quick_sort(int buff[], int p, int r)
{
	if(p<r)
	{
		int pi = partition(buff,p,r);
		quick_sort(buff,p,pi-1);
		quick_sort(buff,pi+1,r);
	}
}

// Merge Sort
int *LEFT;
int *RIGHT;
void merge (int buff[], int left, int right)
{
	int mid = (left + right)/2;
	int i,j;
	//Spliting the array
	for(i=left, j=0; i<=mid; i++, j++)	LEFT[j]  = buff[i];
	LEFT[j] = 999;
	for(i=mid+1,j=0;i<=right;i++, j++)	RIGHT[j] = buff[i];	
	RIGHT[j] = 999;
	for(int k=left,i=j=0; k<=right; k++)
	{
		if(LEFT[i]<RIGHT[j]) 
			buff[k] = LEFT[i++];
		else 
			buff[k] = RIGHT[j++];
	}
}

void merge_sort (int buff[], int p, int r)
{
	if (p<r)
	{
		int q = (p+r)/2;
		merge_sort(buff, p, q);
		merge_sort(buff, q+1, r);
		merge(buff, p, r);
	}
}

// Heap Sort
void heapify(int arr[], int n, int i)    // start heapify from ith position 
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest SO FAR
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] =  arr[largest];
        arr[largest] = temp;
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heap_sort(int buff[], int n)
{
    // Build heap (rearrange array)
    for (int i=n/2; i >= 0; i--)	heapify(buff, n, i);
 	int temp;
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        temp = buff[0];
        buff[0] = buff[i];
        buff[i] = temp;
 
        // call max heapify on the reduced heap
        heapify(buff, i, 0);
    }
}


void main()
{
	int n;

	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	
	int *array = malloc(n*sizeof(int));
	int *buff = malloc(n*sizeof(int));

	printf("\nEnter %d elements : ", n);
	for(int i=0;i<n;i++) scanf("%d", &array[i]);

	int ch;
	do
	{
		for (int i=0; i<n; i++) buff[i] = array[i];
		printf("\n\nMENU");
		printf("\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Quick Sort\n5. Merge Sort\n6. Heap Sort\n7. Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d", &ch);
		
		switch (ch)
		{
			case 1: bubble_sort(buff, n);
					printf("\n");
					for(int i=0;i<n;i++) printf("%d \t", buff[i]);
					break;

			case 2: insertion_sort(buff, n);
					printf("\n");
					for(int i=0;i<n;i++) printf("%d \t", buff[i]);
					break;

			case 3: selection_sort(buff, n);
					printf("\n");
					for(int i=0;i<n;i++) printf("%d \t", buff[i]);
					break;

			case 4: quick_sort(buff, 0, n-1);
					printf("\n");
					for(int i=0;i<n;i++) printf("%d \t", buff[i]);
					break;

			case 5: LEFT  = (int *)malloc( ((n/2)+1)*sizeof(int) );
					RIGHT = (int *)malloc( ((n/2)+1)*sizeof(int) );
					merge_sort(buff, 0, n-1);
					printf("\n");
					for(int i=0;i<n;i++) printf("%d \t", buff[i]);
					break;

			case 6: heap_sort(buff, n);
					printf("\n");
					for(int i=0;i<n;i++) printf("%d \t", buff[i]);
					break;

			case 7: printf("\nThank you!");
					exit(0);

		   default: printf("\nInvalid Choice !");
					break;
		}
	} while(1);

}
