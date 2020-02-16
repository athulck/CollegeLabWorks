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

#define ROUND(a) ((int)(a+0.5))                      // Ceil Round

void lineDDA (int xA, int yA, int xB, int yB) {

	int dx = xB-xA, dy = yB-yA, steps, k;
	float xIncrement, yIncrement, x = xA, y = yA;

	// No.of steps
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;

	setpixel(ROUND(x), ROUND(y));

	for (int k=0; k<steps; k++) {
		x += xIncrement;
		y += yIncrement;
		setpixel(ROUND(x), ROUND(y));
	}
}

/* --------------------------------------------------------------------------- */


void main() {

	// Init image
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
			image[i][j] = ' ';

	int xA, xB, yA, yB;

	printf("\nPOINT 1");
	printf("\nEnter the X coordinate : ");
	scanf("%d", &xA);
	printf("\nEnter the Y coordinate : ");
	scanf("%d", &yA);

	printf("\nPOINT 2");
	printf("\nEnter the X coordinate : ");
	scanf("%d", &xB);
	printf("\nEnter the Y coordinate : ");
	scanf("%d", &yB);

	lineDDA(xA, yA, xB, yB);
	display_image();
}


