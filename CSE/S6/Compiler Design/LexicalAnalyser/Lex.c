/* A simple lexical analyzer in C */

/*
Pre-requisites:

C is a context-sensitive language.

	i) C is not a regular language because the below statement is a valid C statement, and it contains many levels of nested paranthesized expressions 
	   which needs a stack for evaluation.
		{ if(1) { printf("Hello"); } }
	   So is C context-free ? If it is, then is it deterministic CFL or a non-deterministic CFL ?
	   ( Remember: power of ND-CFL > power of D-CFL )
	
	ii) Let us do some recap.
		"aaabbbbbbaaa"  is a ND-CFL whereas
		"aaabbbcbbbaaa" is a D-CFL.
		Since there is a 'c' right in the middle, we can clearly spot the middle of the string and change the stack operation from push to pop.

		Now, coming back to C, the code below is a valid C program.
		
		void main() {{{{{{{}}}}}}}

		If we add an openning ({) or closing (}) curly braces to the code, the C compiler will throw a syntax error.
		Thus, we can clearly see that C is a ND-CFL.

	I coudn't find a proof for why C is not a ND-CFL. But what I can say is that we cannot program a non-deterministic PDA. So it is better to go
	with deterministic LBA.
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


FILE *src_fp = NULL;

char getNextChar() {

	if (! feof(src_fp)) {

		char ch = (char)fgetc(src_fp);
		return ch;

	} else
		return '\0';

}

# include "FA.h"


void main(int argc, char const *argv[])
{

	// 1. Open the source file
	
	if (argc < 2) {
		printf("\n[Error] Not enough argument(s): File name not given !");
		exit(0);
	}

	src_fp = fopen(argv[1], "r");
	
	init_FA();


	fclose(src_fp);
}


