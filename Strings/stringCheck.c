#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
    char *str1="HI",*str=" "; 
    printf("char pointer str1 = '%s'\n\n",str1);
    char str2[10]="HI";
    printf("string str2 = '%s'\n",str2);
    printf("\nThey are the same..");
    getch(); system("cls");
    
    printf("scanf() and gets() difference:\n\n"); fflush(stdin);
    printf("(normal scanf)Enter an Elem: ");
    scanf("%s",str2); printf("scanf(); = %s\n\n",str2); fflush(stdin);
    printf("(gets)Enter an Elem: "); 
    gets(str2); printf("gets() = %s\n\n",str2); getch(); fflush(stdin);/*
    printf("(mod scanf):Enter an Elem ");
    scanf("%s^[ ]",str2); printf("scanf('s'^[]) = %s",str2); getch(); */
    
    //puts(strcat(str,"karma")); && puts(strcat("white","karma")); makes an error
    
    return 0;
}
