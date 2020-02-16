/**/

#include <stdio.h>
#include <stdlib.h>

void main() {


	int N_OP;
	printf("\nEnter the number of operators : ");
	scanf("%d", &N_OP);


	char *OP_LIST = (char *)malloc(N_OP*sizeof(char));

	for (int i=0; i<N_OP; i++) {
		getchar();

		printf("\nEnter operator #%d : ", i+1);
		scanf("%c", &OP_LIST[i]);
	}


	char OPP_table[N_OP][N_OP];
	printf("\nEnter the contents of the Parsing Table : ");

	for (int i=0; i<N_OP; i++) {

		for (int j=0; j<N_OP; j++) {
			getchar();

			if (i == j) {
				OPP_table[i][j] = '-';
				continue;
			}
			printf("\nEnter the precedence of %c to %c : ", OP_LIST[i], OP_LIST[j]);
			scanf("%c", &OPP_table[i][j]);
		}
	}


	char string[100];
	printf("\nEnter the string : ");
	scanf("%s", string);


	printf("\nThe String : %s", string);


}
