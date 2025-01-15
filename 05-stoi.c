#include <stdio.h>
#include<stdlib.h>
void takeString(char *str){
    printf("Enter string:");
    scanf("%s",str);
}
size_t strLen(char *str){
    size_t len=0;
    while(str[len]!='\0') len++;
    return len;
}
int isDigit(char ch){
    return ch>='0' && ch<='9';
}
int stoi(char *str,int len){
    int value=0,neg=0;
    for(int i=0;i<len;i++){
        if(i==0 && str[i]=='-') neg=1;
        else if(isDigit(str[i])){
            value=value*10+(str[i]-'0');
        }
        else break;
    }
    if(neg) value*=-1;
    return value;
    
}
int main()
{
    char str[100];
    takeString(str);
    int val=stoi(str,strLen(str));
    printf("Output:%d",val);
    return 0;
}