
#include <stdio.h>
#include <stdlib.h>


void sort(int n, int array[n])
{
	int smallest, pos, temp;
	for (int i=0; i<n; i++)
	{
		printf("\n");
		for (int k=0; k<n; k++) printf("%d ", array[k]);

		smallest = array[i];
		pos = i;

		for (int j=i+1; j<n; j++)
		{
			if(array[j] < smallest)
			{	
				pos = j;
				smallest = array[j];
			}
		}

		if (pos != i)
		{
			temp = array[i];
			array[i] = array[pos];
			array[pos] = temp;
		}
	}
}



int find_next (int item, int n, int queue[n], int n_cyl, int greater)
{
	int next_item, diff = 9999999;
	if (greater)
	{
		for(int i=0; i<n; i++)
			if(item < queue[i])
				if (abs(item-queue[i]) < diff)
				{
					next_item = queue[i];
					diff = abs(item-next_item);
				}
	}
	else
	{
		for(int i=0; i<n; i++)
			if(item > queue[i])
				if (abs(item-queue[i]) < diff)
				{
					next_item = queue[i];
					diff = abs(item-next_item);
				}	
	}
}


void main ()
{
	int queue[] = {98, 183, 37, 122, 14, 124, 65, 67, 53, 199, 0};
	int n = sizeof(queue)/sizeof(int);

	sort(n, queue);
}