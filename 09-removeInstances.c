#include <stdio.h>
#include<stdlib.h>
char* takeString(char *ch){
    printf("Enter string:");
    char *str=(char*)malloc(100);
    scanf("%[^\n]",str);
    getchar();
    printf("Enter character whose occ to be removed:");
    scanf("%c",ch);
    return str;
}

void removeOcc(char *str,char chInstanceRem){
    int ind=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=chInstanceRem){
            str[ind++]=str[i];
        }
    }
    str[ind++]='\0';
}
int main()
{
    char chInstanceRem;
    char *str=takeString(&chInstanceRem);
    removeOcc(str,chInstanceRem);
    printf("%s",str);
    free(str);
    return 0;
}