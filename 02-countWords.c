#include <stdio.h>
#include<stdlib.h>
char* takeString(){
    printf("Enter String:");
    char *str=(char*)malloc(500);
    scanf("%[^\n]",str);
    return str;
}

int countWords(char *str){
    int countOfWords=0;
    char *ptr=str;
    while(*ptr!='\0' && *ptr==' ') ptr++;
    while(*ptr!='\0'){
        while(*ptr!='\0' && *ptr!=' ') ptr++;
        countOfWords++;
        while(*ptr!='\0' && *ptr==' ') ptr++;
    }
    return countOfWords;
}
int main()
{
    char *str=takeString();
    printf("%d",countWords(str));
    free(str);
    return 0;
}