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
    size_t len1=strLen(src),len2=strLen(dest);
    for(int i=0;i<len1;i++){
        dest[i+len2]=src[i];
    }
    dest[len1+len2]='\0';
}
int* zArr(char *str,size_t len){
    int *z=(int*)calloc(len,sizeof(int));
    int l=0,r=0;
    for(int i=1;i<len;i++){
        if(i<=r) {
            if(r-i+1>=z[i-l]) z[i]=z[i-l];
            else z[i]=r-i+1;
            
        }
        while(i+z[i]<len && str[z[i]]==str[z[i]+i]) z[i]++;
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
        
    }
    return z;
    
}
int checkRotation(char *str1,char *str2){
    size_t orgLen=strLen(str2);
    conCat(str1,str1);
    conCat(str2,str1);
    size_t len=strLen(str2);
    int *z=zArr(str2,len);
    int isRotation=0;
    for(int i=0;i<len;i++){
        if(z[i]==orgLen){
            isRotation=1;
            break;
        }
    }
    free(z);
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