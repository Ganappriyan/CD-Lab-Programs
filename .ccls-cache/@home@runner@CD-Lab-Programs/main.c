#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isOperator(char a)
{
    return (a == '+' || a == '-' || a == '*' || a == '/' || a == '%' || a == '=' || a == ';') ? 1 : 0;
}
int isKeyword(char a[10])
{
    return (strcmp(a, "int") == 0 || strcmp(a, "float") == 0 || strcmp(a, "double") == 0) ? 1 : 0;
}

int main()
{
    char a[50], tmp[10];
    int ch = 0;
    printf("Enter the String: ");
    scanf("%[^\n]s", a);
    strcat(a, " ");

    printf("Lexeme\tToken\tAddress\n");
    for (int i = 0; i < strlen(a); i++)
    {
        if ((ch == 3 || ch == 1) && (isalpha(a[i]) || a[i] == '_'))
        {
            strncat(tmp, &a[i], 1);
            ch = 3;
        }
        else if (isdigit(a[i]) || (ch == 1 && a[i] == '.'))
        {
            strncat(tmp, &a[i], 1);
            if (ch != 2)
                ch = 1;
        }
        else if (isalpha(a[i]) || a[i] == '_')
        {
            strncat(tmp, &a[i], 1);
            ch = 2;
        }

        else
        {
            if (ch == 1)
                printf("%s\t\tnumber    \t%p\n", tmp, &a[i]);
            else if (ch == 2)
            {
                if (isKeyword(tmp))
                    printf("%s\t\tkeyword   \t%p\n", tmp, &a[i]);
                else if (!(isdigit(tmp[0])))
                {
                    int c = 0;
                    for (int j = 0; j < strlen(tmp); j++)
                    {
                        if (isalnum(tmp[j]) || tmp[j] == '_')
                            c++;
                    }
                    if (c == strlen(tmp))
                        printf("%s\t\tidentifier\t%p\n", tmp, &a[i]);
                }
            }

            ch = 0;
            tmp[0] = '\0';

            if (isOperator(a[i]))
                printf("%c\t\toperator  \t%p\n", a[i], &a[i]);
            else if (isspace(a[i]))
                continue;
            else
                printf("%c\t\tinvalid   \t%p\n", a[i], &a[i]);
        }
    }
}