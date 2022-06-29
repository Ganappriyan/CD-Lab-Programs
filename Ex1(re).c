#include <stdio.h>
#include <string.h>
#include <regex.h>

int match(char *text, char *pattern)
{
  regex_t re;
  regcomp(&re, pattern, REG_EXTENDED);
  return (regexec(&re, text, 0, NULL, 0)==0)?1:0;
}

int main()
{
    char a[50];
    printf("Enter the String: ");
    fgets(a, 50, stdin);
    printf("Lexeme\tToken\tAddress\n");

    char *token = strtok(a, " ");
    while (token != NULL)
    {
        if(match(token, "[0-9]+") == 1)
            printf("\nNumber\t%s\t%p", token, (void *)&token);
        else if(match(token, "[_a-zA-Z][_a-zA-Z0-9]*"))
            printf("\nIdentifier\t%s\t%p", token, (void *)&token);
        else if(strcmp(token, "=") == 1)
            printf("\nAssignment\t%s\t%p", token, (void *)&token);
        else if(match(token, "\\+-\\*/%") == 1)
            printf("\nOperator\t%s\t%p", token, (void *)&token);
        else
            printf("\nINVALID\t%s\t%p\n", token, (void *)&token);
        
        token = strtok(NULL, " ");
    }
}