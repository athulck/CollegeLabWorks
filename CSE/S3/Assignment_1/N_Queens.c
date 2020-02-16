#include <stdio.h>
#include <stdlib.h>

void display(int n, int SQUARE[n][n])
{
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("\n");
		for(int j=0;j<n;j++) printf("%d ",SQUARE[i][j]);
	}
}

void  main()
{
	int n,n_queens=0;
	printf("\nEnter the value of N : ");
	scanf("%d",&n);
	if(n%2 == 0)
	{
		printf("\nThis value of N is not applicable for N Queens !");
		exit(0);
	}
	int SQUARE[n][n];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) SQUARE[i][j] = 0;

	for(int i=0,j=0;i<n;i++,j+=2)
	{
		if(SQUARE[i][j] == 0)
		{
			if(j>=n) j=1;
			SQUARE[i][j] = 1;
			n_queens++;
		}
	}		

	
	if(n_queens == n) display(n,SQUARE);
	else printf("\nThis value of N is not applicable for N Queens !");
}

/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(SQUARE[i][j] == 0)
			{
				//Insert Queen in (i,j)
				printf("\n(%d,%d)",i,j);
				SQUARE[i][j] = 1; 
				n_queens++;

				//Vertical
				for(int p=0;p<n;p++)
				{
					if(p == i) continue;
					else SQUARE[p][j] = 5;
				}
				//Horizondal
				for(int p=0;p<n;p++)
				{
					if(p == j) continue;
					else SQUARE[i][p] = 5;
				}

				//Principal Diagonal
				for(int p=i,q=j;(p!=0) && (q!=0);p--,q--)
				{
					if(SQUARE[p][q] == 1) continue;
					SQUARE[p][q] = 5;
				}
				for(int p=i,q=j;(p!=n) && (q!=n);p++,q++)
				{
					if(SQUARE[p][q] == 1) continue;
					SQUARE[p][q] = 5;
				}

				//Non-principal Diagonal
				for(int p=i,q=j;(p!=0) && (q!=n);p--,q++)
				{
					if(SQUARE[p][q] == 1) continue;
					SQUARE[p][q] = 5;
				}
				for(int p=i,q=j;(p!=n) && (q!=0);p++,q--)
				{
					if(SQUARE[p][q] == 1) continue;
					SQUARE[p][q] = 5;
				}
			}
		}
		//display(n,SQUARE);
	}
*/