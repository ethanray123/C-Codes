#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
    char str[10], *ptr, str2[10]; int i,j;
    printf("Enter the String: ");
    gets(str);
    for(j=0;j<10;j++){
        for(i=0;i<10;i++){
           if(isalpha(str[i])){}
           else{ strcpy(str+i,str+i+1); }
        }
    }
    puts(str);
    getch();
    return 0;
}
