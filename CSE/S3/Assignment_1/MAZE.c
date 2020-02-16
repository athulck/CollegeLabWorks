
#include<stdio.h>
#include<stdlib.h>


void display(int m, int n, int MAZE[m][n])
{
	for(int i=0;i<m;i++)
	{	
		printf("\n");
		for(int j=0;j<n;j++) printf("%d ",MAZE[i][j]);
	}
}

void solve (int r, int c, int m, int n, int MAZE[m][n])
{
	if(r<m && c<n)
	{
		if(MAZE[r][c] >= 10) return;
		printf("\n (%d , %d)",r,c);
		MAZE[r][c] = 10;
		solve(r+1,c,m,n,MAZE);
		solve(r,c+1,m,n,MAZE);
	}
}


void main()
{
	int n,m,in_n,in_m,start_m,start_n,end_m,end_n;
	char ch;
	printf("\nEnter the number of rows and columns : ");
	scanf("%d%d",&m,&n);
	int MAZE[m][n];

	for(int i=0;i<m;i++) for(int j=0;j<n;j++) MAZE[i][j] = 0;

	do
	{
		printf("\nEnter the coordinates of Invalid Blocks : ");
		scanf("%d%d",&in_m,&in_n);
		MAZE[in_m-1][in_n-1] = 9999;
		printf("\nWant to enter more ? (y/n) : ");
		getchar();
		scanf("%c",&ch);

	}while(ch == 'y');
	/*
	printf("\nEnter the starting coordinates : ");
	scanf("%d%d",&start_m,&start_n);
	printf("\nEnter the finishing coordinates : ");
	scanf("%d%d",&end_m,&end_n);
	int *start = &MAZE[start_m-1][start_n-1];
	int *finish = &MAZE[end_m-1][end_n-1];
	*/
	display(m,n,MAZE);
	solve(0,0,m,n,MAZE);
	display(m,n,MAZE);
	/*
	for(int i=0,j=0; finish != &MAZE[i][j] ;)
	{
		if(i<m && j<n)
		{

		}
	}
	*/

}