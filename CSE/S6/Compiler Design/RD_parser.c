#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int i=0;
char str[50];

void E();

void F() {

	if (isalpha(str[i]))
		i++;
	else if (str[i] == '(') {
		i++;
		E();
		if (str[i] == ')')
			i++;
		else {
			printf("\n[Error] Unexpected character '%c' at position %d : %s", str[i], i+1, str);
			exit(0);
		}
	} else {
		printf("\n[Error] Unexpected character '%c' at position %d : %s", str[i], i+1, str);
		exit(0);
	}
}

void T_prime() {

	if (str[i] == '*') {

		i++;
		F();
		T_prime();
	}
}

void T() {

	F();
	T_prime();
}

void E_prime() {

	if (str[i] == '+') {

		i++;
		T();
		E_prime();
	}
}


void E() {

	T();
	E_prime();
}



void main() {

	printf("\nEnter the string : ");
	scanf("%s", str);

	E();

	if (strlen(str) == i) {
		printf("\n'%s' is accepted !", str);
	} else 
		printf("\n'%s' is rejected !", str);

}
