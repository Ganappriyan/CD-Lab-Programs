%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "y.tab.h"
%}

%%
[0-9]+ { yylval.i = atoi(yytext); return INT; }
[0-9]+(\\.[0-9]+)? { yylval.f = atof(yytext); return FLOAT; }
[ \t] ;
\n { return 0; }
. { return yytext[0]; }
%%