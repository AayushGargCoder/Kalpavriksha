#include <stdio.h>
#include<stdlib.h>
char* takeString(){
    printf("Enter string:");
   char *str=(char*)malloc(100);
   scanf("%s",str);
   return str;
}
size_t strLen(char *str){
    size_t len=0;
    while(str[len]!='\0') len++;
    return len;
}

char* longestPalindromeSubstring(char *str,size_t size){
    int st=-1,len=0;
    for(int i=0;i<size;i++){
        int j=i,k=i;
        while(j>=0 && k<size && str[j]==str[k]) j--,k++;
        
        if(k-j-1>len){
            len=k-j-1;
            st=j+1;
        }
        
        j=i,k=i+1;
        while(j>=0 && k<size && str[j]==str[k]) j--,k++;
        if(k-j-1>len){
            len=k-j-1;
            st=j+1;
        }
    }
    str[st+len]='\0';
    return str+st;
}
int main()
{
    char *str=takeString();
    char *palindrome=longestPalindromeSubstring(str,strLen(str));
    printf("Output:%s",palindrome);
    free(str);
    return 0;
}