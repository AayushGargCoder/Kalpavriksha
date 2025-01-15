#include <stdio.h>
#include<stdlib.h>
char* takeString(){
    printf("Enter string:");
    char *str=(char*)malloc(100);
    scanf("%s",str);
    return str;
}
int strLen(char *str){
    int len=0;
    while(str[len]!='\0') len++;
    return len;
}
void swap(char *a,char *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void printPermutation(char *str,int i,int n){
    if(i==n){
        printf("%s\n",str);
        return;
    }
    for(int j=i;j<n;j++){
        swap(str+i,str+j);
        printPermutation(str,i+1,n);
        swap(str+i,str+j);
    }
}
int main()
{
    char *str=takeString();
    printPermutation(str,0,strLen(str));
    free(str);
    return 0;
}