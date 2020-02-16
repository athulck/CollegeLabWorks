%{
int lines=0;	
%}

identifiers [a-zA-Z][a-zA-Z0-9]*
operators [+*/-]

%%

#.* {printf("\n%s is a preprocessor directive", yytext);}


void {printf("\n%s is a keyword", yytext);}
int {printf("\n%s is a keyword", yytext);}
float {printf("\n%s is a keyword", yytext);}
double {printf("\n%s is a keyword", yytext);}
char {printf("\n%s is a keyword", yytext);}
if {printf("\n%s is a keyword", yytext);}
else {printf("\n%s is a keyword", yytext);}
break {printf("\n%s is a keyword", yytext);}
continue {printf("\n%s is a keyword", yytext);}
do {printf("\n%s is a keyword", yytext);}
for {printf("\n%s is a keyword", yytext);}
while {printf("\n%s is a keyword", yytext);}
switch {printf("\n%s is a keyword", yytext);}
case {printf("\n%s is a keyword", yytext);}
return {printf("\n%s is a keyword", yytext);}
typedef {printf("\n%s is a keyword", yytext);}
struct {printf("\n%s is a keyword", yytext);}


{identifiers} {printf("\n%s is an identifier", yytext);}
{operators}   {printf("\n%s is an operator", yytext);}

\< |\> |\<= |\>= |==  {printf("\n%s is a comparison operator", yytext);}





%%


int yywrap() {
	return 1;
}

void main() {
	
	yyin = fopen("CProgram.c", "r");
	yylex();
}


