// Pass 1 of a two pass assembler

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void main () {

	// INPUT : File with the Source Code
	FILE *SC;
	SC = fopen("SC", "r");

	// INPUT : OPTAB
	FILE *OPTAB;
	OPTAB = fopen("OPTAB", "r");

	// OUTPUT : File with the Object Program
	FILE *INTER;
	INTER = fopen("INTER_FILE", "w+");

	// Initialising the SYMTAB
	FILE *SYMTAB;
	SYMTAB = fopen("SYMTAB", "w+");

	// Initialising the registers
	fprintf(SYMTAB, "A 0",);
	fprintf(SYMTAB, "X 1",);
	fprintf(SYMTAB, "L 2",);
	fprintf(SYMTAB, "B 3",);
	fprintf(SYMTAB, "S 4",);
	fprintf(SYMTAB, "T 5",);
	fprintf(SYMTAB, "F 6",);
	fprintf(SYMTAB, "PC 8",);
	fprintf(SYMTAB, "SW 9",);
	fclose(SYMTAB);

	char PROG_NAME[10];
	char OPCODE[10];
	char LABEL[10];
	char OPERAND[10];

	unsigned int LOCCTR = 0;
	unsigned int START_ADDR = 0;

	fscanf(SC, "%s %s %x", LABEL, OPCODE, START_ADDR);
	if (! strcmp(OPCODE, "START")) {
		strcpy(PROG_NAME, LABEL);
		LOCCTR = START_ADDR;
	}

	while(!feof(SC)) {

		fscanf(SC, "%s %s %s", LABEL, OPCODE, OPERAND);

		if (LABEL[0] == '.') {
			// Comment line
			continue;
		}

		sym_addr = in_SYMTAB(LABEL);
		if (sym_addr != -1) {
			printf("\n[Error] Symbol '%s' defined more than once !", LABEL);
			break;
		} else {
			insert_symbol(LABEL, LOCCTR);
		}

		if (isalpha(OPCODE[0])) {
			// PC or BASE realtive

		} else if (OPCODE[0] == '@') {
			// Indirect

		} else if (OPCODE[0] == '#') {
			// Immediate
			
		} else if (OPCODE[0] == '+') {
			// Extended
			
		} else {
			printf("\n[Error]");
			break;
		}

		if (OPERAND[0] == '=') {
			// Literal Soptted !
		}


		opcode = in_OPTAB(OPCODE);
		if (opcode != -1) {

		} else if (! strcmp(OPCODE, "WORD")) {

		} else if (! strcmp(OPCODE, "BYTE")) {
			
		} else if (! strcmp(OPCODE, "RESW")) {
			
		} else if (! strcmp(OPCODE, "RESB")) {
			
		} else if (! strcmp(OPCODE, "EQU")) {

			sym_addr = in_SYMTAB(LABEL);
			if (sym_addr != -1) {
				printf("\n[Error] Symbol '%s' defined more than once !", LABEL);
				break;
			} else {
				insert_symbol(LABEL, atoi(OPERAND));
			}
				
		} else if (! strcmp(OPCODE, "ORG")) {
			
		} else if (! strcmp(OPCODE, "USE")) {
			
		} else if (! strcmp(OPCODE, "CSECT")) {
			
		} else if (! strcmp(OPCODE, "EXTDEF")) {
			
		} else if (! strcmp(OPCODE, "EXTREF")) {
			
		} else if (! strcmp(OPCODE, "BASE")) {
			
		} else if (! strcmp(OPCODE, "NOBASE")) {
			
		} else if (! strcmp(OPCODE, "MACRO")) {
			
		} else if (! strcmp(OPCODE, "MEND")) {
			
		} else if (! strcmp(OPCODE, "SET")) {
			
		} else if (! strcmp(OPCODE, "LTORG")) {
			
		} else if (! strcmp(OPCODE, "END")) {
			
		} else {
			printf("\n[Error] Unknown OPCODE : '%s' ", OPCODE);
			break;
		}

	}

	fclose(INTER);
	fclose(OPTAB);
	fclose(SC);

}