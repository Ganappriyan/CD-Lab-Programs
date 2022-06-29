%{
  #include <stdio.h>
  #include <stdlib.h>
  int yylex();
  int yyerror(char *s);
%}

%union
{
  int i;
  double f;
}
%start L
%token <i> INT
%token <f> FLOAT
%type <i> E1
%type <f> E2
%left '+' '-' '*' '/' '%' '(' ')'

%%
L  : E
E  : E1 { printf("Result = %d\n", $1); }
   | E2 { printf("Result = %lf\n", $1); }
E1 : INT '+' INT { $$ = $1 + $3; }
   | INT '-' INT { $$ = $1 - $3; }
   | INT '*' INT { $$ = $1 * $3; }
   | INT '/' INT { $$ = $1 / $3; }
   | INT '%' INT { $$ = $1 % $3; }
   | '(' E1 ')' { $$ = $2; }
   | INT { $$ = $1; }
E2 : FLOAT '+' FLOAT { $$ = $1 + $3; }
   | FLOAT '-' FLOAT { $$ = $1 - $3; }
   | FLOAT '*' FLOAT { $$ = $1 * $3; }
   | FLOAT '/' FLOAT { $$ = $1 / $3; }
   | '(' E2 ')' { $$ = $2; }
   | FLOAT { $$ = $1; }
%%

int main()
{
  yyparse();
  printf("Valid Expression\n");
}

int yyerror(char *s)
{
  printf("%s\n", s);
  printf("Invalid Expression\n");
  exit(0);
}