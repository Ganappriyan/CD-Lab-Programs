#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isNumber(char *c)
{
    for(int i=0; i<strlen(c); i++)
        if(!isdigit(c[i]))
            return 0;
    return 1;
}

int isOperator(char *c)
{
    if(strcmp(c, "+") == 0 || strcmp(c, "-") == 0 || strcmp(c, "*") == 0 || strcmp(c, "/") == 0 || strcmp(c, "%") == 0)
        return 1;
    return 0;
}

int main()
{
    char a[50];
    printf("Enter the String: ");
    fgets(a, 50, stdin);
    char *token = strtok(a, " ");
    printf("Lexeme\tToken\tAddress\n");
    char *operators = "+-*/%=<>";
    while (token != NULL)
    {
        if(isNumber(token)==1)
            printf("\nNumber\t%s\t%p", token, (void *)&token);
        else if(strcmp(token, "="))
            printf("\nAssignment\t%s\t%p", token, (void *)&token);
        else if(isOperator(token)==1)
            printf("\nOperator\t%s\t%p", token, (void *)&token);
        else
            printf("\nINVALID\t%s\t%p\n", token, (void *)&token);
        
        token = strtok(NULL, " ");
    }
}