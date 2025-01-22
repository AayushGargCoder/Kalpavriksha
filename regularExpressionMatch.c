// https://leetcode.com/problems/regular-expression-matching/description/?envType=problem-list-v2&envId=string
// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
// Input: s = "aa", p = "a"
// Output: false
// Input: s = "ab", p = ".*"
// Output: true
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

int isMatchRec(char *s, char *p, int i, int j)
{
    if (i < 0 && j < 0)
        return 1;
    if (i == -1 && p[j] == '*')
        return isMatchRec(s, p, i, j - 2);
    if (i < 0 || j < 0)
        return 0;
    if (s[i] == p[j] || p[j] == '.')
        return isMatchRec(s, p, i - 1, j - 1);
    else
    {
        if (p[j] == '*')
        {
            if (p[j - 1] == '.' || p[j - 1] == s[i])
                return isMatchRec(s, p, i, j - 2) || isMatchRec(s, p, i - 1, j);
            else
                return isMatchRec(s, p, i, j - 2);
        }
    }
    return 0;
}
int isMatch(char *s, char *p)
{
    return isMatchRec(s, p, strLen(s) - 1, strLen(p) - 1);
}

void deAllocate(char *num1, char *num2)
{
    free(num1);
    free(num2);
}
int main()
{
    char *s = takeInput(), *p = takeInput();
    printf("%s", isMatch(s, p) ? "True" : "False");
    deAllocate(s, p);
}