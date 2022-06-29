#include <stdio.h>
#include <string.h>
#include <regex.h>

char keywords[13][10] = {"void", "int", "float", "double", "char",
"return", "if", "else", "for", "while", "do", "printf", "scanf"};

int match(char *ip, char *pattern)
{
  regex_t re;
  regcomp(&re, pattern, REG_EXTENDED);
  return (regexec(&re, ip, 0, NULL, 0)==0)?1:0;
}

int iskeyword(char *ip)
{
  for(int i=0; i<strlen(keywords); i++)
    if(strcmp(keywords[i], ip) == 0)
      return 1;
  return 0;
}

int main()
{
  char ch, ip[1000];
  FILE *fp = fopen("input.txt", "r");

  int i=0;
  while((ch = fgetc(fp)) != EOF)
    ip[i++] = ch;
  ip[i]='\0';

  i=0;
  char *token = strtok(ip, "\""), *tokens[50];
  while(token != NULL) {
    tokens[i++] = token;
    token = strtok(NULL, "\"");
  }

  printf("Lexemes \t\t Tokens\n");

  for(int j=0; j<i; j++)
  {
    if(j%2==0)
    {
      token = strtok(tokens[j], " ,;\\){}\n");
      while(token != NULL)
      {
        if(match(token, "#.*") == 1) printf("%s \t\t Preprocessor\n", token);
        else if(iskeyword(token) == 1) printf("%s \t\t Keyword\n", token);
        else if(match(token, "[_a-zA-Z][_a-zA-Z0-9]*\\(") == 1) printf("%s \t\t Function\n", token);
        else if(match(token, "[_a-zA-Z][_a-zA-Z0-9]*") == 1) printf("%s \t\t Identifier\n", token);
        else if(match(token, "\'.\'.") == 1) printf("%s \t\t Character\n", token);
        else if(match(token, "[0-9]+") == 1) printf("%s \t\t Number\n", token);
        else if(match(token, "[\\+-\\*/%=<>!\\?&\\|]+") == 1) printf("%s \t\t Operator\n", token);
        else printf("%s\n", token);

        token = strtok(NULL, " ,;\\){}\n");
      }
    }
    else
      printf("\"%s\" \t\t String\n", tokens[j]);
  }
}