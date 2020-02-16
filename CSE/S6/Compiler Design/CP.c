/**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct row {
	char name[20];
	float val;
} SYM_TBL[50];

int TBL_i = 0;



void add_symbol(char *sym, float value) {

	strcpy(SYM_TBL[TBL_i].name, sym);
	SYM_TBL[TBL_i].val = value;
	TBL_i++;
}



int isKeyword (char *string) {

	char Keywords[][10] = {"int", "float", "double", "char"};

	for (int i=0; i<4; i++){
		if (! strcmp(string, Keywords[i]))
			return 1;
	}
	return 0;
}




void main() {



	char sym[40];
	float val;

	FILE *fp;
	fp = fopen("input", "r");
	int found=0;

	while(!feof(fp)) {

		found = 0;
		fscanf(fp, "%s", sym);
		
		printf("%s ", sym);

		for (int i=0; i<=TBL_i; i++) {

			if (! strcmp(sym, SYM_TBL[i].name)) {
				found = 1;
				printf("%f", SYM_TBL[i].val);
			}

		}
		
	
		if (isKeyword(sym)) {

			fscanf(fp, "%s = %f;", sym, &val);
			printf("\nSymbol : %s, value : %f", sym, val);
		}


	}



}
