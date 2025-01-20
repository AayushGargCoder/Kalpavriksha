// https://leetcode.com/problems/cyclically-rotating-a-grid/description/
// You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.
// A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction
// Return the matrix after applying k cyclic rotations to it.
// Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
// Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]

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
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotateGrid(int **grid, int m, int n, int k)
{
    int rs = 0, cs = 0, re = m - 1, ce = n - 1, tempK;
    while (rs <= re && cs <= ce)
    {
        int totalPos = 2 * (ce - cs + 1) + 2 * (re - rs + 1) - 4;
        tempK = k % totalPos;
        int save;
        for (int i = 0; i < tempK; i++)
        {
            save = grid[rs][ce];
            for (int j = ce - 1; j >= cs; j--)
            {
                swap(&grid[rs][j], &save);
            }
            for (int j = rs + 1; j <= re; j++)
            {
                swap(&grid[j][cs], &save);
            }
            for (int j = cs + 1; j <= ce; j++)
            {
                swap(&grid[re][j], &save);
            }
            for (int j = re - 1; j >= rs; j--)
            {
                swap(&grid[j][ce], &save);
            }
        }
        rs++, cs++, re--, ce--;
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
    int m, n, k;
    printf("Enter First matrix size and k:");
    scanf("%d %d %d", &m, &n, &k);

    printf("Enter first matrix:\n");
    int **mat = takeInput(&m, &n);

    rotateGrid(mat, m, n, k);
    printMatrix(mat, m, n);
    deallocate(mat, m);

    return 0;
}