
// # include <stdio.h>

int	main() {
	int a = 10;
	printf("\nHello World");
}


<KW, int> <ID, main> <SS,(> <SS,)> <SS,{>
<KW, int> <ID, a> <OP,=> <CN, 10>
<ID, printf> <SS,'('> <LT, "\nHello World"> <SS, ')'> <SS, ';'>
<SS, }>



KW = { auto, break, case, char, const, continue, default, do, double, else, enum, extern, float, for, goto, if, int, long,
       register, return, short, signed, sizeof, static, struct, switch, typedef, union, unsigned, void, volatile, while     }

CN = { 5356, -4356, 400u, 300l, 400.05f, 35456E-4 19.325, 0123, 0x2134 }

LT = { '2', 'c', '\n', "s\n\t%cdaf" }

ID = { ('_'+alpha).('_' + alpha + digit)*  }


SS = { '#', '(', ')', '{', '}', ';', ',', '<', '>', '.', '\\', }

OP = { '!', '%', '^', '&', '*', '-', '+', '=', '|', '?' }
