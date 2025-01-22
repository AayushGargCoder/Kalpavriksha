// https://leetcode.com/problems/reorganize-string/description/?envType=problem-list-v2&envId=string
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.
// Input: s = "aab"
// Output: "aba"
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
void reorganizeString(char *s)
{
    int maxFreq = 0, n = strLen(s);
    char maxChar = '\0';
    int freq[26] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 97]++;
        if (freq[s[i] - 97] > maxFreq)
        {
            maxFreq = freq[s[i] - 97];
            maxChar = s[i];
        }
    }

    if ((n + 1) / 2 < maxFreq)
    {
        printf("Not Possible");
        return;
    }
    int ind = 0;
    while (maxFreq--)
    {
        s[ind] = maxChar;
        ind += 2;
    }
    freq[maxChar - 97] = 0;
    ind -= 2;
    for (int i = 0; i < 26; i++)
    {
        while (freq[i]--)
        {
            ind = ind + 2 < n ? ind + 2 : 1;
            s[ind] = i + 97;
        }
    }
    printf("%s", s);
}

int main()
{
    char *s = takeInput();
    reorganizeString(s);
    free(s);
}