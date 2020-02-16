#include<stdio.h> 
#include<stdlib.h> 
#include<ctype.h> 
#include<string.h> 

#define MAX_N_PROD 10
#define MAX_N_VARS 10

int N_VARS=0, N_PROD;

int isTerminal (char sym) {

	if ( !isalpha(sym) )
		return 1;
	else if ( islower(sym) )
		return 1;
	else return 0;
}

int isVariable (char sym) {

	if ( isalpha(sym) && isupper(sym) )
		return 1;
	else return 0;
}

struct result {

	char var;
	char FIRST[20];
	char FOLLOW[20];

} RESULT[MAX_N_VARS];

struct production {

	char LHS;
	char RHS[50];

} PRODUCTIONS[MAX_N_PROD];


void print_result() {

	printf("\nRESULT TABLE ----------------------------------------------------------- ");
	printf("\nSYM\t|\tFIRST\t|\tFOLLOW");
	printf("\n---\t|\t-----\t|\t------");
	for (int i=0; i<N_VARS; i++) 
		printf("\n%c\t|\t%s\t|\t%s", RESULT[i].var, RESULT[i].FIRST, RESULT[i].FOLLOW);
	printf("\n");
}


int FIRSTcontainsEPSILON (char VAR) {

	int found_epsilon = 0;

	for (int i=0; i<N_VARS; i++)
		if (RESULT[i].var == VAR) {
			
			for (int j=0; RESULT[i].FIRST[j] != '\0'; j++)
				if (RESULT[i].FIRST[j] == '#') {
					
					found_epsilon = 1;
					break;
				}
			break;
		}

	return found_epsilon;
}


/* ----------------------------------------------------------------------/ FIRST -------------------------------------------------------------------------*/

void addToFIRST(char VAR, char terminal_sym) {

	for (int i=0; i<N_VARS; i++) {
		
		if (RESULT[i].var == VAR) {

			int j=0;
			for (; RESULT[i].FIRST[j] != '\0'; j++) {
				if (RESULT[i].FIRST[j] == terminal_sym)
					return;
			};
			RESULT[i].FIRST[j] = terminal_sym;
			RESULT[i].FIRST[j+1] = '\0';
			break;
		}
	}
}

void copyFIRSTtoFIRST(char curr_sym, char VAR) {

	// Finding source and destination indices to copy
	int src_index, dest_index;
	for (int i=0; i<N_VARS; i++) {
		
		if (RESULT[i].var == VAR)
			dest_index = i;
		else if (RESULT[i].var == curr_sym)
			src_index = i;
	}

	// Copying
	int j, found;

	for (int i=0; RESULT[src_index].FIRST[i] != '\0'; i++) {

		j=0;
		found = 0;
		for (; RESULT[dest_index].FIRST[j] != '\0'; j++) {

			// if FIRST(VAR) already has FIRST(curr_sym), then do nothing
			if (RESULT[src_index].FIRST[i] == RESULT[dest_index].FIRST[j]) {
				found = 1;
				break;
			}
		}

		if (! found) {
			if (RESULT[src_index].FIRST[i] == '#') continue;
			RESULT[dest_index].FIRST[j] = RESULT[src_index].FIRST[i];
			RESULT[dest_index].FIRST[j+1] = '\0';
		}

	}
}


void find_FIRST (char var) {

	char curr_sym;
	int found_epsilon, epsilon_count;

	// Loop over evey PRODUCTIONS
	for (int i=0; i < N_PROD; i++) {

		// Find the right productions
		if (PRODUCTIONS[i].LHS == var) {

			epsilon_count = 0;

			// X -> Yj
			for (int j=0; PRODUCTIONS[i].RHS[j] != '\0'; j++) {

				curr_sym = PRODUCTIONS[i].RHS[j];

				if ( isTerminal(curr_sym) ) {

					addToFIRST(PRODUCTIONS[i].LHS, curr_sym);
					break;

				} else if ( (PRODUCTIONS[i].RHS[j] == '#') ) {

					addToFIRST(PRODUCTIONS[i].LHS, curr_sym);
					break;

				} else if ( isVariable(curr_sym) ) {

					find_FIRST(curr_sym);
					copyFIRSTtoFIRST(curr_sym, PRODUCTIONS[i].LHS); // except epsilon

					if ( FIRSTcontainsEPSILON(curr_sym) ) 
						epsilon_count++;
					else return;
				} 
				else printf("\n[Error] Undefined symbol '%c' !", curr_sym);
			}

			// if every symbol in the RHS has '#' in its corresponding FIRSTs, then add '#' to the FIRST(LHS)
			if ( epsilon_count == strlen(PRODUCTIONS[i].RHS) )
				addToFIRST(PRODUCTIONS[i].LHS, '#');

		}
	}

}

/* ---------------------------------------------------------------------- FIRST /-------------------------------------------------------------------------*/








/* ----------------------------------------------------------------------/ FOLLOW -------------------------------------------------------------------------*/



void addToFOLLOW(char VAR, char terminal_sym) {

	for (int i=0; i<N_VARS; i++) {
		
		if (RESULT[i].var == VAR) {

			int j=0;
			for (; RESULT[i].FOLLOW[j] != '\0'; j++) {
				if (RESULT[i].FOLLOW[j] == terminal_sym)
					return;
			};
			RESULT[i].FOLLOW[j] = terminal_sym;
			RESULT[i].FOLLOW[j+1] = '\0';
		}
	}
}


void copyFIRSTtoFOLLOW(char curr_sym, char VAR) {

	// Finding source and destination indices to copy
	int src_index, dest_index;
	for (int i=0; i<N_VARS; i++) {
		
		if (RESULT[i].var == VAR)
			dest_index = i;
		else if (RESULT[i].var == curr_sym)
			src_index = i;
	}

	// Copying
	int j, found;

	for (int i=0; RESULT[src_index].FIRST[i] != '\0'; i++) {

		j=0;
		found = 0;
		for (; RESULT[dest_index].FOLLOW[j] != '\0'; j++) {

			// if FOLLOW(VAR) already has FIRST(curr_sym), then do nothing
			if (RESULT[src_index].FIRST[i] == RESULT[dest_index].FOLLOW[j]) {
				found = 1;
				break;
			}
		}

		if (! found) {
			if (RESULT[src_index].FIRST[i] == '#') continue;
			RESULT[dest_index].FOLLOW[j] = RESULT[src_index].FIRST[i];
			RESULT[dest_index].FOLLOW[j+1] = '\0';
		}

	}
}


void copyFOLLOWtoFOLLOW(char curr_sym, char VAR) {

	// Finding source and destination indices to copy
	int src_index, dest_index;
	for (int i=0; i<N_VARS; i++) {
		
		if (RESULT[i].var == VAR)
			dest_index = i;
		else if (RESULT[i].var == curr_sym)
			src_index = i;
	}

	// Copying
	int j, found;

	for (int i=0; RESULT[src_index].FOLLOW[i] != '\0'; i++) {

		j=0;
		found = 0;
		for (; RESULT[dest_index].FOLLOW[j] != '\0'; j++) {

			// if FOLLOW(VAR) already has FOLLOW(curr_sym), then do nothing
			if (RESULT[src_index].FOLLOW[i] == RESULT[dest_index].FOLLOW[j]) {
				found = 1;
				break;
			}
		}

		if (! found) {
			if (RESULT[src_index].FOLLOW[i] == '#') continue;
			RESULT[dest_index].FOLLOW[j] = RESULT[src_index].FOLLOW[i];
			RESULT[dest_index].FOLLOW[j+1] = '\0';
		}

	}
}


/* ---------------------------------------------------------------------- FOLLOW / -------------------------------------------------------------------------*/


/* ----------------------------------------------------------------------- MAIN -------------------------------------------------------------------------*/


void main () {

	printf("\nEnter the number of productions : ");
	scanf("%d", &N_PROD); // 9

	// The Input grammar
    PRODUCTIONS[0].LHS = 'S';
    strcpy(PRODUCTIONS[0].RHS, "ACB");
	
    PRODUCTIONS[1].LHS = 'S';
    strcpy(PRODUCTIONS[1].RHS, "CbB");

	PRODUCTIONS[2].LHS = 'S';
    strcpy(PRODUCTIONS[2].RHS, "Ba");

	PRODUCTIONS[3].LHS = 'A';
    strcpy(PRODUCTIONS[3].RHS, "da");

    PRODUCTIONS[4].LHS = 'A';
    strcpy(PRODUCTIONS[4].RHS, "BC");

    PRODUCTIONS[5].LHS = 'B';
    strcpy(PRODUCTIONS[5].RHS, "g");

    PRODUCTIONS[6].LHS = 'B';
    strcpy(PRODUCTIONS[6].RHS, "#");

    PRODUCTIONS[7].LHS = 'C';
    strcpy(PRODUCTIONS[7].RHS, "h");

    PRODUCTIONS[8].LHS = 'C';
    strcpy(PRODUCTIONS[8].RHS, "#");



    // Displaying the input grammar
    printf("\nINPUT GRAMMAR");
    for (int i=0; i < N_PROD; i++) {
    	
    	printf("\n%c -> ", PRODUCTIONS[i].LHS);

    	for (int j=0; PRODUCTIONS[i].RHS[j] != '\0' ; j++) {
    		
    		printf("%c", PRODUCTIONS[i].RHS[j]);
    	}
	}

	// Initializations
	int j=0, found = 0;
	for (int i=0; i<N_PROD; i++) {

		// Scan the destination list for the variable
		found = 0;
		for (int k=0; k<=N_VARS; k++) {

			if (PRODUCTIONS[i].LHS == RESULT[k].var) {
				found = 1;
				break;
			}
		}

		// if the variable is not found, then add the variable to the list
		if (!found) {

			RESULT[N_VARS].var = PRODUCTIONS[i].LHS;
			strcpy(RESULT[N_VARS].FIRST, "");
			strcpy(RESULT[N_VARS].FOLLOW, "");
			N_VARS++;
		} 
	}
	printf("\nNumber of variables = %d", N_VARS);

	
	/* FINDING FIRSTs */
	// Loop over evey PRODUCTIONS
	for (int i=0; i < N_PROD; i++) {

		// Find FIRST
		find_FIRST (PRODUCTIONS[i].LHS);
	}


	/* FINDING FOLLOWs */
	
	// Add '$' to starting symbol
	addToFOLLOW(PRODUCTIONS[0].LHS, '$');


	for (int i=0; i<N_PROD; i++) {

		for (int k, j=0; PRODUCTIONS[i].RHS[j] != '\0' ; j++) {

			k=j+1;

			// A -> aBb ; if (b is a terminal) 
			if ( isVariable(PRODUCTIONS[i].RHS[j]) && isTerminal(PRODUCTIONS[i].RHS[j+1]) ) {

				addToFOLLOW(PRODUCTIONS[i].RHS[j], PRODUCTIONS[i].RHS[j+1]);


			// A -> aBb ; else if (b is a variable) 
			} else if ( isVariable(PRODUCTIONS[i].RHS[j]) && isVariable(PRODUCTIONS[i].RHS[j+1]) ) {

				for (; PRODUCTIONS[i].RHS[k] != '\0'; k++) {

					copyFIRSTtoFOLLOW (PRODUCTIONS[i].RHS[k], PRODUCTIONS[i].RHS[j]); // Except epsilon

					if (! FIRSTcontainsEPSILON(PRODUCTIONS[i].RHS[k]) )
						break;
				}
			}
		}
	}

	for (int i=0; i<N_PROD; i++) {

		for (int j = strlen(PRODUCTIONS[i].RHS)-1;  j>=0 ; j--) {

			if ( isVariable(PRODUCTIONS[i].RHS[j]) ) {

				copyFOLLOWtoFOLLOW(PRODUCTIONS[i].LHS, PRODUCTIONS[i].RHS[j]); // Except epsilon

				if (! FIRSTcontainsEPSILON(PRODUCTIONS[i].RHS[j]) )
					break;
			}
		}
	}

	print_result();
}