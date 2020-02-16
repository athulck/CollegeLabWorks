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


/* --------------------------------------------------------------------------- */

void circlePlotPoints (int xCenter, int yCenter, int x, int y) {

	setpixel(xCenter + x, yCenter + y);
	setpixel(xCenter - x, yCenter + y);
	setpixel(xCenter + x, yCenter - y);
	setpixel(xCenter - x, yCenter - y);
	setpixel(xCenter + y, yCenter + x);
	setpixel(xCenter - y, yCenter + x);
	setpixel(xCenter + y, yCenter - x);
	setpixel(xCenter - y, yCenter - x);

}

void circleMidpoint (int xCenter, int yCenter, int radius) {
	
	int x = 0, y = radius;
	int p = 1-radius;

	/* Plot first set of points */
	circlePlotPoints (xCenter, yCenter, x, y);

	while (x < y) {
		x++;
		if (p < 0)
			p += 2*x + 1;
		else {
			y--;
			p += 2*(x-y) + 1;
		}
		circlePlotPoints (xCenter, yCenter, x, y);
	}
}

/* --------------------------------------------------------------------------- */


void main() {

	// Init image
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
			image[i][j] = ' ';

	int xCenter, yCenter, radius;

	printf("\nEnter the X coordinate of the center point : ");
	scanf("%d", &xCenter);
	printf("\nEnter the Y coordinate of the center point : ");
	scanf("%d", &yCenter);

	printf("\nEnter the radius : ");
	scanf("%d", &radius);

	circleMidpoint(xCenter, yCenter, radius);
	display_image();

}
