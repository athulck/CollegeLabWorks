//Program to perform array operations 

#include <stdio.h>
#include <stdlib.h>

int array[50],n,i,option,pos,element;
int choice = 1;


void main()
{
	printf("\nEnter the number of elements in your array : ");
	scanf("%d", &n);

	for(int i=0; i<n; i++) {

		printf("\nEnter element #%d : ", i+1);
		scanf("%d", &array[i]);
	}
  
	do {

		printf("\n\nOPERATIONS MENU\n 1.Insertion\n 2.Deletion\n 3.Display\nEnter your choice : ");
		scanf("%d", &option);

		switch (option) {

			case 1 :  
						//Insertion
						printf("\nEnter the element to be inserted : ");
						scanf("%d", &element);

						printf("\nEnter the position : ");
						scanf("%d", &pos);

						for (i=n-1; i>=pos-1; i--)
						{
						  //We are pushing the nth element to the n+1 th position.
						  //The loop starts from the last element and works it's way down to the element at the postition pos.
						  array[i+1] = array[i];
						}
						i++;
						array[i] = element;
						n=n+1;
						break;
					 
			case 2 :  
							//Deletion
							printf("\nEnter the position : ");
						scanf("%d",&pos);
						//We are going to delete the element at the given position
						for (i=pos;i<n;i++)
						{
						   array[i-1]=array[i];
						} 
						n=n-1;
						break;
			         
			case 3:  
			       	    //Display
			       	    printf("\nYour array : \n");
			       	    for (i=0;i<n;i++)
			       	        printf("%d\t",array[i]);
			            break;
			         
			         
			default:  printf("\nInvalid Choice !");


		} 
		printf("\nDo you want to continue (1=y/0=n) ? ");
		scanf("%d",&choice);
	 
	}while (choice == 1);

}
