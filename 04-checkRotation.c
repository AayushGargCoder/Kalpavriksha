#include <stdio.h>
#include<stdlib.h>
void takeStrings(char **str1Ptr,char **str2Ptr){
    printf("Enter string1:");
    *str1Ptr=(char*)malloc(200);
    scanf("%s",*str1Ptr);
    printf("Enter string2:");
    getchar();
    *str2Ptr=(char*)malloc(100);
    scanf("%s",*str2Ptr);
}

size_t strLen(char *str){
    size_t len=0;
    while(str[len]!='\0') len++;
    return len;
}
void conCat(char *dest,char *src){
    size_t len=strLen(src);
    for(int i=0;i<len;i++){
        dest[i+len]=src[i];
    }
    dest[2*len]='\0';
}
int* lpsArr(char *str,size_t len){
    int *lps=(int*)calloc(len,sizeof(int));
    int i=1,j=0;
    lps[j]=0;
    while(str[i]!='\0'){
        if(str[i]==str[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if(j==0) i++;
            else j=lps[j-1];
        }
    }
    return lps;
}
int checkRotation(char *str1,char *str2){
    size_t len=strLen(str2);
    int *lps=lpsArr(str2,len);
    conCat(str1,str1);
    int i=0,j=0,isRotation=0;
    while(str1[i]!='\0' && str2[j]!='\0'){
        if(str1[i]==str2[j]){
            i++,j++;
            if(j==len){
                isRotation=1;
                break;
            }
        }
        else{
            if(j==0) i++;
            else j=lps[j-1];
        }
    }
    free(lps);
    return isRotation;
}
void deAllocate(char *str1,char *str2){
    free(str1);
    free(str2);
}
int main()
{
    char *str1,*str2;
    takeStrings(&str1,&str2);
    printf("%s",checkRotation(str1,str2)?"true":"false");
    deAllocate(str1,str2);
    return 0;
}