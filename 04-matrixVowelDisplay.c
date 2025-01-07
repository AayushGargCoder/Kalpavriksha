#include <stdio.h>
#include <stdlib.h>
char ***takeInput(int *r, int *c)
{
    printf("Enter number of rows:");
    scanf("%d", r);
    printf("Enter number of columns:");
    scanf("%d", c);
    if (*r > 10 || *c > 101)
    {
        return NULL;
    }
    char ***matrix = (char ***)malloc((*r) * sizeof(char **));
    for (int i = 0; i < *r; i++)
    {
        matrix[i] = (char **)malloc((*c) * sizeof(char *));

        for (int j = 0; j < *c; j++)
        {
            matrix[i][j] = (char *)malloc(50);
            getchar();
            printf("Name at (%d,%d):", i, j);
            scanf("%s", matrix[i][j]);
        }
    }
    return matrix;
}
int isVowel(char inp)
{
    if (inp < 97)
        inp += 32;
    return inp == 'a' || inp == 'e' || inp == 'i' || inp == 'o' || inp == 'u';
}
int strLen(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}
void prMatVowelLarName(char ***matrix, int r, int c)
{
    printf("The 2D array of names is:\n");
    int vCnt = 0;
    char *longestN = "";
    int longestLen = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (isVowel(matrix[i][j][0]))
                vCnt++;
            int currLen = strLen(matrix[i][j]);
            if (currLen > longestLen)
            {
                longestN = matrix[i][j];
                longestLen = currLen;
            }
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\nNumber of names starting with a vowel: %d", vCnt);
    printf("\nThe longest name: %s", longestN);
    longestN = NULL;
}
void deAllocate(char ***matrix, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}
int main()
{
    int r, c;
    char ***matrix = takeInput(&r, &c);
    if (matrix == NULL)
        printf("Invalid Input of rows and columsn.Plz ensure rows<11 and col<102.");
    else
    {
        prMatVowelLarName(matrix, r, c);
        deAllocate(matrix, r, c);
    }
}