#include <stdio.h>
#include<stdlib.h>
char* takeString(){
    printf("Enter string:");
    char *str=(char*)malloc(100);
    scanf("%s",str);
    return str;
}

void removeDub(char *str){
    int freq[26]={0};
    int ind=0;
    for(int i=0;str[i]!='\0';i++){
        if(!freq[str[i]-97]){
            str[ind++]=str[i];
        }
        freq[str[i]-97]++;
    }
    str[ind++]='\0';
}
int main()
{
    char *str=takeString();
    removeDub(str);
    printf("%s",str);
    free(str);
    return 0;
}