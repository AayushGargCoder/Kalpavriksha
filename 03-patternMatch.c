#include <stdio.h>
#include<stdlib.h>
void takeStrings(char **textPtr,char **patternPtr){
    printf("Enter string1:");
    *textPtr=(char*)malloc(100);
    scanf("%[^\n]",*textPtr);
    printf("Enter string2:");
    getchar();
    *patternPtr=(char*)malloc(100);
    scanf("%s",*patternPtr);
 
}

size_t strLen(char *str){
    size_t len=0;
    while(str[len]!='\0') len++;
    return len;
}
int* lpsArr(char *str,size_t len){
    int *lps=(int*)calloc(len,sizeof(int));
    int i=1,j=0;
    lps[j]=0;
    while(str[i]!='\0'){
        if(str[i]==str[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if(j==0) i++;
            else j=lps[j-1];
        }
    }
    return lps;
}
int patternIndex(char *text,char *pattern){
    size_t len=strLen(pattern);
    int *lps=lpsArr(pattern,len);
    int i=0,j=0,patternInd=-1;
    while(text[i]!='\0' && pattern[j]!='\0'){
        if(text[i]==pattern[j]){
            i++,j++;
            if(j==len){
                patternInd=i-len;
                break;
            }
        }
        else{
            if(j==0) i++;
            else j=lps[j-1];
        }
    }
    free(lps);
    return patternInd;
}
void deAllocate(char *str1,char *str2){
    free(str1);
    free(str2);
}
int main()
{
    char *text,*pattern;
    takeStrings(&text,&pattern);
    printf("%d",patternIndex(text,pattern));
    deAllocate(text,pattern);
    return 0;
}