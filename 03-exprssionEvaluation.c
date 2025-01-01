#include <stdio.h>
int a, b, c;
void binaryExpo()
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * 1LL * a % c;
        a = a * 1LL * a % c;
        b = b / 2;
    }
    printf("%d", res);
}
int main()
{
    scanf("%d %d %d", &a, &b, &c);
    binaryExpo();
}