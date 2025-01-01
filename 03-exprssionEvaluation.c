#include <stdio.h>
int base, expo, m;
void binaryExpo()
{
    int res = 1;
    while (expo)
    {
        if (expo & 1)
            res = res * 1LL * base % m;
        base = base * 1LL * base % m;
        expo = expo / 2;
    }
    printf("\n\nOutput:\n");
    printf("Result: %d", res);
}
int main()
{
    printf("Input:\n");
    printf("Base (B): ");
    scanf("%d", &base);
    getchar();
    // Prompt and input for exponent
    printf("Exponent (N): ");
    scanf("%d", &expo);
    getchar();

    // Prompt and input for modulus
    printf("Modulus (M): ");
    scanf("%d", &m);
    if (expo >= 0 && m > 1)
        binaryExpo();
    else
    {
        printf("Please enter a valid input");
    }
}