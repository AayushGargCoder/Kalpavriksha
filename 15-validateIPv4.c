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
int isDigit(char ch){
    return ch>='0' && ch<='9';
}

int numLen(int num){
    if(num==0) return 1;
    int len=0;
    while(num){
        len++;
        num=num/10;
    }
    return len;
}

int validateIPv4(char *str){
    size_t len=strLen(str);
    int nForm=-1,lastDotInd=-1,dotCnt=0;
    for(int i=0;i<len;i++){
        if(!isDigit(str[i]) && str[i]!='.') return 0;
        if(str[i]=='.'){
            dotCnt++;
            if(dotCnt>3 || nForm==-1 || (i-lastDotInd-1)>numLen(nForm)) return 0;
            nForm=-1;
            lastDotInd=i;
            continue;
        }
        if(nForm==-1) nForm=0;
        nForm=nForm*10+(str[i]-'0');
        if(nForm>255) return 0;
    }
    if(dotCnt<3 || nForm==-1 || nForm>255 || (len-lastDotInd-1)>numLen(nForm)) return 0;
    return 1;
}
int main()
{
    char *str=takeString();
    printf("%s",validateIPv4(str)?"valid":"inValid");
    free(str);
    return 0;
}