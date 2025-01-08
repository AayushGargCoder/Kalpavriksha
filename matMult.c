
#include <stdio.h>
#include<stdlib.h>
int **takeInput(int *m,int *n){
    int **matrix=(int **)malloc(sizeof(int*)*(*m));
    for(int i=0;i<(*m);i++){
        matrix[i]=(int *)malloc(sizeof(int)*(*n));
        for(int j=0;j<(*n);j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    return matrix;
}
void deallocate(int **matrix,int m){
    for(int i=0;i<m;i++) free(matrix[i]);
    free(matrix);
}
void matrixMul(int **mat1,int **mat2,int m1,int n,int n2){
    //res=>m1*n2
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            int value=0;
            for(int k=0;k<n;k++) value+=(mat1[i][k]*mat2[k][j]);
            printf("%d ",value);
        }
        printf("\n");
    }
}

int main()
{
    int m1,n1;
    printf("Enter First matrix size:");
    scanf("%d %d",&m1,&n1);
    int m2,n2;
    printf("\nEnter second matrix size:");
    scanf("%d %d",&m2,&n2);
    if(n1!=m2) printf("First matrix column should be equal to second matrix row size");
    else{
        printf("Enter first matrix\n");
        int **mat1=takeInput(&m1,&n1);
        printf("Enter second matrix\n");
        int **mat2=takeInput(&m2,&n2);
        matrixMul(mat1,mat2,m1,n1,n2);
        deallocate(mat1,m1);
        deallocate(mat2,m2);
        
    }
    

    return 0;
}