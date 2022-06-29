#include<stdio.h>
#include<string.h>

struct op
{
  char l[20];
  char r[20];
};

int main()
{
  int n, i, j, k;
  printf("Enter Number of Values: ");
  scanf("%d", &n);
  struct op a[n];
  
  for (i = 0; i < n; i++)
  {
    printf("%d, Left: ", i+1);
    scanf(" %s", a[i].l);
    printf("%d, Right: ", i+1);
    scanf(" %s", a[i].r);
  }
  
  printf("Intermediate Code:\n");
  for (i = 0; i < n; i++)
    printf("%s = %s\n", a[i].l, a[i].r);
  
  //Dead Code Elimination
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (strcmp(a[i].l, a[j].r) == 0)
        break;
    }

    if (j == n)
    {
      for (k = j; k < n-1; k++)
        a[k] = a[k+1];
      n--;
    }
  }

  printf("After Dead Code Elimination:\n");
  for (i = 0; i < n; i++)
    printf("%s = %s\n", a[i].l, a[i].r);

  //Common Subexpression Elimination
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (strcmp(a[i].l, a[j].r) == 0)
      {
        for (int k = 0; k < n; k++)
        {
          if(strcmp(a[j].l, a[k].r) == 0)
            strcpy(a[k].r, a[i].l);
        }

        for (k = j; k < n-1; k++)
          a[k] = a[k+1];
        n--;
      }
    }
  }

  printf("After Common Subexpression Elimination:\n");
  for (i = 0; i < n; i++)
    printf("%s = %s\n", a[i].l, a[i].r);
}