%{
  #include<stdio.h>
%}
identifier [a-zA-Z_][a-zA-Z0-9_]*
%%
#.* {printf("%s \t\t Preprocessor Directive\n",yytext);}
void |
int |
float |
char |
if |
else |
break |
continue |
printf |
scanf |
for |
while |
return {printf("%s \t\t Keyword\n",yytext);}
{identifier}\( {printf("%s \t\t Function\n",yytext);}
\{ {printf("%s \t\t Block Begins\n",yytext);}
\} {printf("%s \t\t Block Ends\n",yytext);}
{identifier}(\[[0-9]*\])* {printf("%s \t\t Identifier\n",yytext);}
\".*\" {printf("%s \t\t String\n",yytext);}
[0-9]+ {printf("%s \t\t Number\n",yytext);}
\<= |
\>= |
\< |
\> |
\== |
\!= |
\= |
\+ |
\- |
\/ |
\! |
% {printf("%s \t\t Operator\n",yytext);}
\/\*.*\*\/ {printf("%s \t\t Comment Line\n",yytext);}
%%
int main(int argc,char **argv)
{
  FILE *file;
  file=fopen("input.txt","r");
  if(!file)
  {
    printf("Could not open the file!!!\n");
    exit(0);
  }
  yyin=file;
  printf("Lexemes\t\t\tTokens\n\n");
  yylex();
  return(0);
}
int yywrap()
{
  return 1;
}
