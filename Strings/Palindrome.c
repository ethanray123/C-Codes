#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
    char str[10], *ptr, str2[10];
    printf("Enter a Palindrome: ");
    gets(str);
    printf("String(before strrev) : %s\t",str);
    strcpy(str2,str);
    ptr=(char*)malloc(sizeof(int)*10);
    ptr=strrev(str);
    printf("  String(after strrev) : %s\n\n",ptr);
    
    if(strcmp(ptr,str2)==0){
           printf("It is a Palindrome");      
    }else{ printf("It is not a Palindrome"); }
    getch();
    return 0;
}
