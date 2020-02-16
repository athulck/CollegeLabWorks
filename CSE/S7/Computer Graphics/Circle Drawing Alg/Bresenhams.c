/**/

#include <stdio.h>
#include <stdlib.h>


#define MAX 50
char image[MAX][MAX];

void display_image() {

	printf("\n");
	for(int i=0; i<MAX+2; i++)
		printf("%c", '+');
	printf("\n");

	for(int i=MAX-1; i>=0; i--) {
		printf("%c", '+');
		for(int j=0; j<MAX; j++)
			printf("%c", image[i][j]);
		printf("+\n");
	}

	for(int i=0; i<MAX+2; i++)
		printf("%c", '+');
	printf("\n");
}

void setpixel(int x, int y) {

	image[x][y] = '-';
}




void main() {

	// Init image
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
			image[i][j] = ' ';



	/* --------------------------------------------------------------------------- */

	int radius;
	printf("\nEnter the radius : ");
	scanf("%d", &radius);

	int x=0, y=radius;

	int delta = 2*(1-radius), small_delta;

	while (y >= 0) {

		setpixel(x, y);

		if (delta < 0) {

			small_delta = 2*delta + 2*y - 1;
			
			if (small_delta <= 0) {

				// Move Horizontally
				x++;
				delta = delta + 2*x + 1;
			} else {

				// Move Diagonally
				x++;
				y--;
				delta = delta + 2*x - 2*y + 2;
			}
		
		} else if (delta > 0) {
		
			small_delta = 2*delta - 2*x - 1;
			
			if (small_delta <= 0){

				// Move Diagonally
				x++;
				y--;
				delta = delta + 2*x - 2*y + 2;
			}
			else{

				// Move Vertically
				y--;
				delta = delta - 2*y + 1;
			}
		
		} else if (delta == 0) {

			// Move Diagonally
			x++;
			y--;
			delta = delta + 2*x - 2*y + 2;
		}
	}
	
	/* --------------------------------------------------------------------------- */

	display_image();
}

