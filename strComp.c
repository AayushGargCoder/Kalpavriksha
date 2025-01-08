#include <stdio.h>
int strLen(char *arr){
    int i=0;
    while(arr[i]!='\0') i++;
    return i;
}

int main()
{
    char arr[100];
    scanf("%s",arr);
    int freq[26]={0};
    int n=strLen(arr);
    for(int i=0;i<n;i++) freq[arr[i]-97]++;
    
    char comp[200];
    int ind=0;
    for(int i=0;i<26;i++){
        if(freq[i]==0) continue;

        printf("%c",i+97);
        int times=freq[i];
        printf("%d",times);
    

    }
    printf("%s",comp);

    return 0;
}