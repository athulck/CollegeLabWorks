// C Script


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>








void main () {

	FILE *file;
	char line[100];

	file = fopen("INPUT", "r");



	/* SEPERATING LABEL, OPCODE & OPEARND */

	int state = -1;
	int s_LABEL = 1000;
	int s_OPCODE = 1001;
	int s_OPERAND = 1002;
	int s_ERROR = 9999;

	char LABEL[6], OPCODE[6], OPERAND[70];

	// read one line
	while (fgets(line, 90, file))
	{
		strcpy(LABEL, "     ");
		strcpy(OPCODE, "     ");
		strcpy(OPERAND, "                                                                     ");
		for (int i = 0; line[i] != '\0'; ++i)
		{
			if ( 0 <= i && i < 6 && isalpha(line[i]) )
				state = s_LABEL;
			else if ( 10 <= i && i < 16 && isalpha(line[i]) )
				state = s_OPCODE;
			else if ( 20 <= i )
				state = s_OPERAND;
			else
				state = s_ERROR;

			if (state == s_LABEL)
				LABEL[i] = line[i];
			else if (state == s_OPCODE)
				OPCODE[i-10] = line[i];
			else if (state == s_OPERAND)
				OPERAND[i-20] = line[i];
		}

		printf("\n");
		printf("LABEL : %s\t", LABEL);
		printf("OPCODE : %s\t", OPCODE);
		printf("OPEARND : %s\t", OPERAND);
	}

}