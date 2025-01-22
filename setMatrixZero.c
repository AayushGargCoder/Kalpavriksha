// https://leetcode.com/problems/set-matrix-zeroes/description/?envType=problem-list-v2&envId=matrix
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

#include <stdio.h>
#include <stdlib.h>
void takeDimension(int *m,int *n){
    printf("Enter matrix size:");
    scanf("%d %d", m, n);
}

int **takeInput(int *m, int *n)
{
     printf("Enter matrix:\n");
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
void setNow(int **matrix, int row, int col, int rsize, int csize)
{
    for (int i = 0; i < csize; i++)
    {
        if (matrix[row][i] != 0)
        {
            matrix[row][i] = -1;
        }
    }
    for (int i = 0; i < rsize; i++)
    {
        if (matrix[i][col] != 0)
        {
            matrix[i][col] = -1;
        }
    }
}
void setZeroes(int **matrix, int m, int n)
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                setNow(matrix, i, j, m, n);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void printMatrix(int **mat, int m, int n)
{
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
void deallocate(int **matrix, int m)
{
    for (int i = 0; i < m; i++)
        free(matrix[i]);
    free(matrix);
}
int main()
{
    int m, n;
    takeDimension(&m,&n);

    int **mat = takeInput(&m, &n);

    setZeroes(mat, m, n);
    printMatrix(mat, m, n);
    deallocate(mat, m);

    return 0;
}
