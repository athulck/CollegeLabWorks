/**/

#include <stdio.h>
#include <stdlib.h>

void main() {

	int temp;

	// RC-4 can have variable length key of key length 1 to 256
	int K[] = {1,2,3,4,5,6,7,8};
	int keylen = 8;

	if ((keylen < 1) && (256 < keylen)) {
		printf("\n[Error] Key size too big !");
		exit(0);
	}



	/*  INITIALIZATION OF S & T */

	int *S = (int *)malloc(256*sizeof(int));
	int *T = (int *)malloc(256*sizeof(int));
	
	for(int i=0; i<256; i++) {

		// Initializing S
		S[i] = i;

		// Initializing T : Copy key K to T repeatedly until T is full
		T[i] = K[i % keylen];

	}


	printf("\nINITIALIZING S & T");
	printf("\n\nS[] = [");
	for (int i=0; i<256; i++) {
		printf("%d, ", S[i]);
	}
	printf("]");
	printf("\n\nT[] = [");
	for (int i=0; i<256; i++) {
		printf("%d, ", T[i]);
	}
	printf("]");



	/* INITIAL PERMUTATION OF S*/
	for( int i=0, j=0; i<256; i++) {

		// Compute j
		j = (j + S[i] + T[i]) % 256;

		// Swap (S[i], S[j])
		temp = S[i];
		S[i] = S[j];
		S[j] = temp;
	}

	printf("\nINITIAL PERMUTATION OF S");
	printf("\n\nS[] = [");
	for (int i=0; i<256; i++) {
		printf("%d, ", S[i]);
	}
	printf("]");
	

	/* STREAM GENERATION */
	int i=0 ,j = 0, t, k;
	while(1) {

		i = (i + 1)    % 256;
		j = (j + S[i]) % 256;

		// Swap (S[i], S[j])
		temp = S[i];
		S[i] = S[j];
		S[j] = temp;

		t = (S[i] + S[j]) % 256;

		k = S[t];
		printf("\nKey : %d", k);
		getchar();
	}

}
