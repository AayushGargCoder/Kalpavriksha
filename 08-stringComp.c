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
void swap(char *c1,char *c2){
    char ch=*c1;
    *c1=*c2;
    *c2=ch;
}
void reverseDig(char *temp,int st,int e){
    while(st<e) swap(temp+(st++),temp+(e--));
}
void compressString(char **str,size_t len){
    char *temp=(char*)malloc(100);
    int ind=0;
    for(int i=0;i<len;){
        int j=i;
        while(j<len && (*str)[i]==(*str)[j]) j++;
        int cnt=j-i,numDig=0;
        temp[ind++]=(*str)[i];
        while(cnt){
            temp[ind++]=(cnt%10+48);
            cnt/=10;
            numDig++;
        }
        reverseDig(temp,ind-numDig,ind-1);
        i=j;
    }
    if(strLen(temp)<=len){
        free(*str);
        *str=temp;
    }
    else{
        free(temp);
    }
}
int main()
{
    char *str=takeString();
    compressString(&str,strLen(str));
    printf("Output:%s",str);
    free(str);
    return 0;
}