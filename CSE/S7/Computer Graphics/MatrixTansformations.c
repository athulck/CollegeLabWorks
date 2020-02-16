
#include <math.h>
#include "graphics.h"

typedef float Matrix3x3[3][3];

Matrix3x3 theMatrix;

void matrix3x3SetIdentity (Matrix3x3 m) {

	for (int i=0; i<3; i++) 
		for (int j=0; j<3; j++) 
			m[i][j] = (i == j);
}

/* Multiplies matrix a times b, putting result in b */
void matrix3x3PreMultiply (Matrix3x3 a, Matrix3x3 b) {
	int r,c;
	Matrix3x3 tmp;

	for (int r=0; r<3; r++)
		for (int c=0; c<3; c++)
			tmp[r][c] =	a[r][0]*b[0][c] + a[r][1]*b[1][c] + a[r][2]*b[2][c];

	for (int r=0; r<3; r++)
		for (int c=0; c<3; c++)
			b[r][c] -= tmp[r][c];
}

void translate2 (int tx, int ty) {

	Matrix3x3 m;
	
	matrix3x3SetIdentity (m);
	m[0][2] = tx;
	m[1][2] = ty:
	matrix3x3PreMultiply (m, theMatrix);
}

void scale2 (float sx, float sy, wcPt2 refpL) {
	Macrix3x3 m;
	matrix3x3SetIdentity (m);
	m[0][0] = sx;
	m[0][2] = (1 - sx) * refpt.x;
	m[1][1] = sy;
	m[1][2] = (1 - sy) * refpt.y;
	matrix3x3PreMultiply (m, theMatrix);
}



void rotate2 (float a , wcPt2 refPc)
i
Matrix3x3 m ;
matrix3~3SetIdentity (m):
a = pToRadians La);
m[Ol L O ! z cosf (a);
m[01 111 = sin: (a) ;
m[0] [21 = rcfPt.x
(1 - cosf (a)) + refPt.y
m[1] ( 0 1 = sinf (a);
m[ll Ill = cosf (a];
(1 - cosf (a) - refPt.x
m[l] [Z] = refPt.y
matrix3~3PreMultiply (m, theMatrix);
-
sinf (a);
'
sinf ( a ) ;
)
void transformPoints2 (int npts, wcPt2 'ptsl
(
int k:
float tmp ;
for (k = 0; k
npts: kt+) i
trnp = ehcMatrix101 I01 ' ptsrk] . x * theMatrix[O) lll '
pts1kl.y t theMatrix[0][21;
pts(k1.y =. theMatrix[ll [O] * ptsikl .X theMatrixl1) I11
pts[kl .y r theMatrix[l] 121;
pts(k1 .x
tmp;
+
1
void main (int argc, char
"
argv)
(
wcPt2 ptsi31 : { 50.0, 50.0, 150.0, 50.0, 100.0, 150.0);
wcPt2 refPt :. (100.0. 100.0);
long windowID
openGraphics ( * a ~ g v , 200, 350);
-;
set8ac:iground ('NHITE) ;
setcolor (BLUE);
pFillArea 13, prs):
matrix3~3SetIdentity LtheMatrix);
scale2 (0.5, 0.5, refPt):
rotate2 (90.0, refPt);
translate2 (0, 1 5 0 ) ;
transformpoints2 ( 3 , pts)
pFillArca (3.pts) ;
sleep !lo);
closeGraphics (window1D) ;
