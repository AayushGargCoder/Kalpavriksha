// https://leetcode.com/problems/search-a-2d-matrix-ii/description/?envType=problem-list-v2&envId=matrix
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false

#include <stdio.h>
#include <stdlib.h>
int **takeInput(int *m, int *n)
{
    int **matrix = (int **)malloc(sizeof(int *) * (*m));
    for (int i = 0; i < (*m); i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * (*n));
        for (int j = 0; j < (*n); j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

int searchMatrix(int **matrix, int m, int n, int target)
{

    int i = 0, j = n - 1;
    while (i < m && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return 1;
        }
        else if (matrix[i][j] < target)
        {
            i += 1;
        }
        else
        {
            j -= 1;
        }
    }
    return 0;
}

void deallocate(int **matrix, int m)
{
    for (int i = 0; i < m; i++)
        free(matrix[i]);
    free(matrix);
}
int main()
{
    int m, n, k;
    printf("Enter First matrix size and k:");
    scanf("%d %d %d", &m, &n, &k);

    printf("Enter first matrix:\n");
    int **mat = takeInput(&m, &n);

    printf("\n%s", searchMatrix(mat, m, n, k) ? "True" : "False");

    deallocate(mat, m);

    return 0;
}