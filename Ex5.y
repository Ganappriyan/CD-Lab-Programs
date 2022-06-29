%{
  #include <stdio.h>
  #include <stdlib.h>
  int yylex();
  int yyerror(char *s);
%}

%start VAR
%token DIGIT LETTER

%%
VAR  : LETTER REST
     | '_' REST
     | LETTER
     | '_'
REST : LETTER REST
     | DIGIT REST
     | '_' REST
     | LETTER
     | DIGIT
     | '_'
    ;
%%

int main()
{
  yyparse();
  printf("Valid Variable\n");
}

int yyerror(char *s)
{
  printf("Invalid Variable\n");
  exit(0);
}