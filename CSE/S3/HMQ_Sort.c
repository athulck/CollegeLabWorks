//Program to perform Heap, Merge and Quick sort
#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

int *LEFT;
int *RIGHT;

//                          4         5         7
void merge (int *buff, int left, int mid, int right)
{
	int i,j;
	//Spliting the array
	for(i=left,j=0 ;i<=mid  ;i++)	LEFT[j++]  = buff[i];   //  [1,10,999]
	LEFT[j]  = INFINITY;
	for(i=mid+1,j=0;i<=right;i++)	RIGHT[j++] = buff[i];	//  [5,2,999]
	RIGHT[j] = INFINITY;
	for(int k=left,i=j=0; k<=right; k++)
	{
		if (LEFT[i]<RIGHT[j])  buff[k] = LEFT[i++];
		else buff[k] = RIGHT[j++];
	}
}

void merge_sort (int *buff, int l, int r)
{
	if (l<r)
	{
		int mid = (l+r)/2;
		merge_sort(buff, l, mid);
		merge_sort(buff, mid+1, r);
		merge(buff, l, mid, r);
	}
}

int partition(int *buff,int p,int r)
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

void quick_sort(int *buff, int p, int r)
{
	if(p<r)
	{
		int pi = partition(buff,p,r);
		quick_sort(buff,p,pi-1);
		quick_sort(buff,pi+1,r);
	}
}

void heapify(int *arr, int n, int i)    // start heapify from ith position 
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

void heap_sort(int *buff, int n)
{
    // Build heap (rearrange array)
    for (int i = n/2; i >= 0; i--)	heapify(buff, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        int temp = buff[0];
        buff[0] = buff[i];
        buff[i] = temp;
 
        // call max heapify on the reduced heap
        heapify(buff, i, 0);
    }
}

void main()
{
	int i,n;

    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    int *buff = (int *)malloc(n*sizeof(int));

    printf("\nEnter the array elements : ");
    for(i=0;i<n;i++) scanf("%d",&buff[i]);
    printf("\nGiven array is : \n");
    for(i=0;i<n;i++) printf("%d ",buff[i]);

    LEFT = (int *)malloc(  ((n/2)+1) *sizeof(int));
	RIGHT = (int *)malloc( ((n/2)+1) *sizeof(int));
 
    merge_sort(buff,0,n-1);
    //quick_sort(buff,0,n-1);
    //heap_sort(buff, n);

    printf("\nSorted array is : \n");
    for(i=0;i<n;i++) printf("%d ",buff[i]);   
}