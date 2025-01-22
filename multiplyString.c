// https://leetcode.com/problems/multiply-strings/description/
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
// Input: num1 = "123", num2 = "456"
// Output: "56088"
#include <stdio.h>
#include <stdlib.h>
char *takeInput()
{
    printf("Enter String:");
    char *input = (char *)malloc(1000 * sizeof(char));
    scanf("%s", input);
    return input;
}
int strLen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
char *multiply(char *num1, char *num2)
{
    int len1 = strLen(num1), len2 = strLen(num2);
    if (len2 > len1)
        return multiply(num2, num1);

    int *arr = (int *)calloc(1000, sizeof(int));
    int ind = 0, pce = 0, carry1 = 0, carry2 = 0;
    for (int i = len2 - 1; i >= 0; i--)
    {
        for (int j = len1 - 1; j >= 0; j--)
        {
            int value = (num1[j] - '0') * (num2[i] - '0') + carry1;
            arr[pce] += value % 10 + carry2;

            carry1 = value / 10;
            carry2 = arr[pce] / 10;
            arr[pce] = arr[pce] % 10;
            pce++;
        }
        while (carry1 || carry2)
        {
            arr[pce++] = carry1 % 10 + carry2 % 10;
            carry1 /= 10;
            carry2 /= 10;
        }
        ind++;
        if (i != 0)
            pce = ind;
    }
    char *ans = (char *)calloc(pce + 1, 1);
    for (int i = 0; i < pce; i++)
    {
        ans[i] = arr[pce - i - 1] + 48;
    }
    if (ans[0] == '0')
        ans = ans + (pce - 1);
    return ans;
}
void deAllocate(char *num1, char *num2, char *ans)
{
    free(num1);
    free(num2);
    free(ans);
}
int main()
{
    char *num1 = takeInput(), *num2 = takeInput();
    char *ans = multiply(num1, num2);
    printf("%s", ans);
    deAllocate(num1, num2, ans);
}