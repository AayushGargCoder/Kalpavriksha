#include <stdio.h>
#include<stdlib.h>
void takeStrings(char **str1Ptr,char **str2Ptr){
    printf("Enter string1:");
    *str1Ptr=(char*)malloc(100);
    scanf("%s",*str1Ptr);
    printf("Enter string2:");
    getchar();
    *str2Ptr=(char*)malloc(100);
    scanf("%s",*str2Ptr);
}

size_t strLen(char *str){
    size_t len=0;
    while(str[len]!='\0') len++;
    return len;
}

int checkAnagram(char *str1,char *str2){
    size_t n=strLen(str1),m=strLen(str2);
    if(n!=m) return 0;
    int freq[26]={0};
    while(*str1!='\0'){
        freq[(*str1++)-97]++;
        freq[(*str2++)-97]--;
    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0) return 0;
    }
    return 1;
}
void deAllocate(char *str1,char *str2){
    free(str1);
    free(str2);
}
int main()
{
    char *str1,*str2;
    takeStrings(&str1,&str2);
    printf("%s",checkAnagram(str1,str2)?"true":"false");
    deAllocate(str1,str2);
    return 0;
}