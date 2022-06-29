%{
  #include <stdio.h>
  int yylex();
  int yyerror(char *s);
%}

%union
{
  int i;
};
%start S
%token NUMBER
%type <i> E
%type <i> S
%left '+' '-' '*' '/' '%' '(' ')'

%%
S : E {printf("Result = %d\n", $$);}
E : E '+' E   {$$ = $1 + $3;}
  | E '-' E   {$$ = $1 - $3;}
  | E '*' E   {$$ = $1 * $3;}
  | E '/' E   {$$ = $1 / $3;}
  | E '%' E   {$$ = $1 % $3;}
  | '(' E ')' {$$ = $2;}
  | '-' E     {$$ = -$2;}
  | NUMBER    {$$ = $1;}
  ;
%%

int main()
{
  printf("Enter the Expresstion: ");
  yyparse();
  printf("\nValid Expression\n");
}

int yyerror(char *s)
{
  printf("\nInvalid Expression\n");
}