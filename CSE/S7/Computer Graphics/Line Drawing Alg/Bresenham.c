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

void lineBres (int xA , int yA , int xB , int yB) {

	int dx = abs(xA-xB), dy = abs(yA-yB);
	int p = 2*dy - dx;                        // p0
	int twoDy = 2*dy, twoDyDx = 2*(dy-dx);
	int x, y, xEnd;


	/* Determine which point to use as start, which as end */
	if (xA > xB ) {

		x = xB;
		y = yB;
		xEnd = xA;
	}
	else {
		x = xA;
		y = yA;
		xEnd = xB;
	}
	setpixel (x, y);

	while (x < xEnd) {
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyDx;
		}
		setpixel (x , y);
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

	lineBres(xA, yA, xB, yB);
	display_image();
}


