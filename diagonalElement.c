#include <stdio.h>
#include <stdlib.h>
int **takeMatrix(int *nptr)
{
    printf("Enter the size(n) of square matrix:");
    scanf("%d", nptr);
    int **matrix = (int **)malloc(*(nptr) * sizeof(int *));
    if (matrix == NULL)
        return NULL;

    for (int r = 0; r < *(nptr); r++)
    {
        *(matrix + r) = (int *)malloc(*(nptr) * sizeof(int));
        for (int c = 0; c < *(nptr); c++)
        {
            scanf("%d", *(matrix + r) + c);
        }
    }
    return matrix;
}
void leftDiagonal(int **matrix, int n)
{
    printf("Left Diagonal:");
    for (int d = 0; d < n; d++)
        printf("%d, ", *(*(matrix + d) + d));
    printf("\n");
}
void rightDiagonal(int **matrix, int n)
{
    printf("Right Diagonal:");
    for (int d = 0; d < n; d++)
        printf("%d, ", *(*(matrix + d) + (n - 1 - d)));
}
void deallocate(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(*(matrix + i));
    free(matrix);
}
int main()
{
    int n;
    int **matrix = takeMatrix(&n);
    if (matrix == NULL)
        printf("Allocation of memory Fail,does not create the matrix\n");
    else
    {
        leftDiagonal(matrix, n);
        rightDiagonal(matrix, n);
        deallocate(matrix, n);
    }
}