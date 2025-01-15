#include <stdio.h>
#include<stdlib.h>
char* takeString(){
    printf("Enter String:");
    char *str=(char*)malloc(500);
    scanf("%[^\n]",str);
    return str;
}

char* longestWord(char *str){
    int stInd=-1,len=-1;
    for(int i=0;str[i]!='\0';i++){
        int j=i;
        while(str[j]!='\0' && str[j]!=' ') j++;
        if(j-i>=len){
            len=j-i;
            stInd=i;
        }
        i=j;
    }
    str[stInd+len]='\0';
    return str+stInd;
    
}
int main()
{
    char *str=takeString();
    printf("%s",longestWord(str));
    free(str);
    return 0;
}