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

void removeAdjDub(char *str,size_t len){
    int k=0;
    for(int i=0;i<len;i++){
        while(i<len-1 && str[i]==str[i+1]) i+=2;
        str[k++]=str[i];
    }
    str[k]='\0';
    if(k!=len) removeAdjDub(str,k);
}
int main()
{
    char *str=takeString();
    removeAdjDub(str,strLen(str));
    printf("Output:%s",str);
    free(str);
    return 0;
}