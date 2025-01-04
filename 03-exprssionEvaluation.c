#include <stdio.h>
void binaryExpo(int *ptrBase, int *ptrExpo, int *ptrM)
{
    int res = 1;
    while (*ptrExpo)
    {
        if (*ptrExpo & 1)
            res = res * 1LL * (*ptrBase) % (*ptrM);
        *ptrBase = (*ptrBase) * 1LL * (*ptrBase) % (*ptrM);
        *ptrExpo = (*ptrExpo) / 2;
    }
    printf("\n\nOutput:\n");
    printf("Result: %d", res);
}
void takeInput(int *ptrBase, int *ptrExpo, int *ptrM)
{
    printf("Input:\n");
    printf("Base (B): ");
    scanf("%d", ptrBase);
    // Prompt and input for exponent
    printf("Exponent (N): ");
    scanf("%d", ptrExpo);

    // Prompt and input for modulus
    printf("Modulus (M): ");
    scanf("%d", ptrM);
}
int main()
{
    int base, expo, m;
    takeInput(&base, &expo, &m);
    if (expo >= 0 && m > 1 && base > 0)
        binaryExpo(&base, &expo, &m);
    else
    {
        printf("Please enter a valid input");
    }
}