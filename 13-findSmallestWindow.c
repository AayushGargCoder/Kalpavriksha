#include <stdio.h>
#include<stdlib.h>
void takeStrings(char **str1Ptr,char **str2Ptr){
    printf("Enter string1:");
    *str1Ptr=(char*)malloc(200);
    scanf("%[^\n]",*str1Ptr);
    printf("Enter pattern:");
    getchar();
    *str2Ptr=(char*)malloc(100);
    scanf("%s",*str2Ptr);
}

size_t strLen(char *str){
    size_t len=0;
    while(str[len]!='\0') len++;
    return len;
}
void conCat(char *dest,char *src){
    size_t len=strLen(src);
    for(int i=0;i<len;i++){
        dest[i+len]=src[i];
    }
    dest[2*len]='\0';
}
void markPatFreq(char *freqPat,char *pat,int len){
    for(int i=0;i<len;i++) freqPat[pat[i]]++;
}
int isAllowShrink(char *freqPat,char *freqStr){
    for(int i=0;i<256;i++){
        if(freqPat[i] && freqStr[i]<freqPat[i]) return 0;
    }
    return 1;
}
char* findSmallestWindow(char *str,char *pat){
    int st=0,lenStr=strLen(str),lenPat=strLen(pat),len=lenStr,windSt=-1;
    char freqPat[256]={0},freqStr[256]={0};
    markPatFreq(freqPat,pat,lenPat);
    for(int i=0;i<lenStr;i++){
        freqStr[str[i]]++;
        while(isAllowShrink(freqPat,freqStr)){
            freqStr[str[st]]--;
            if(i-st+1<len){
                len=i-st+1;
                windSt=st;
            }
            st++;
        }
    }
    str[windSt+len]='\0';
    return windSt==-1?"None of window of string contains all characters of Pattern":str+windSt;
}
void deAllocate(char *str1,char *str2){
    free(str1);
    free(str2);
}
int main()
{
    char *str1,*str2;
    takeStrings(&str1,&str2);
    printf("%s",findSmallestWindow(str1,str2));
    deAllocate(str1,str2);
    return 0;
}