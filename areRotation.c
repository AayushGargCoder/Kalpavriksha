// You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.
// input1->s1 = "abcd", s2 = "cdab"
// output-> True
// explanation->After 2 right rotations, s1 will become equal to s2.

// input2->s1 = "abcd", s2 = "acbd"
// output-> False

#include <stdio.h>
#include <stdlib.h>
int *lpsArray(char *text, int len)
{
    int i = 1, j = 0;
    int *lps = (int *)malloc(len * sizeof(int));
    lps[j] = 0;
    while (i < len)
    {
        if (*(text + i) == *(text + j))
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
                j = lps[j - 1];
        }
    }
    return lps;
}

void strCat(char *dest, char *s)
{
    while (*dest != '\0')
        dest++;
    while (*s != '\0')
    {
        *dest = *s;
        dest++, s++;
    }
    *dest = '\0';
}
void strCpy(char *dest, char *s)
{
    while (*s != '\0')
    {
        *dest = *s;
        dest++, s++;
    }
    *dest = '\0';
}
void areRotations(char *s1, char *s2, int s1Len, int s2Len)
{
    int n = 2 * s1Len + 1;
    char *text = (char *)malloc(n);
    strCpy(text, s1);
    strCat(text, s1);
    int *lps = lpsArray(s2, s2Len);

    int i = 0, j = 0;
    while (i < n && j < s2Len)
    {
        if (*(text + i) == *(s2 + j))
            i++, j++;
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
        if (j == s2Len)
        {
            printf("String 2 is rotation of string 1\n");
            free(lps);
            free(text);
            return;
        }
    }

    printf("String2 is not rotation of string1\n");
    free(lps);
    free(text);
}
void takeStrings(char **s1, char **s2, int *s1Len, int *s2Len)
{
    printf("Enter the size of string1 and string2:");
    scanf("%d %d", s1Len, s2Len);
    if (*s1Len != *s2Len)
        return;
    getchar();
    *s1 = (char *)malloc(*s1Len), *s2 = (char *)malloc(*s2Len);
    if (*s1 == NULL || *s2 == NULL)
        return;
    printf("Enter the first string:");
    scanf("%s", *s1);
    getchar();
    printf("Enter the second string:");
    scanf("%s", *s2);
}

void deAllocate(char *s1, char *s2)
{
    free(s1);
    free(s2);
}
int main()
{
    char *s1, *s2;
    int s1Len, s2Len;
    takeStrings(&s1, &s2, &s1Len, &s2Len);
    if (s1Len != s2Len)
        printf("Size of string1 and string2 should be equal\n");
    if (s1 == NULL || s2 == NULL)
        printf("Memory allocation failed\n");
    else
    {
        areRotations(s1, s2, s1Len, s2Len);
        deAllocate(s1, s2);
    }
}