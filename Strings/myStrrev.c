#include<stdio.h>
#include<conio.h>
#include<string.h>

void MyStrrev(char str[]);
int main()
{
    char str[100];
    printf("Enter a String: ");
    gets(str);
    MyStrrev(str);
    //strrev(str);
    printf("Reverse String: %s",str);
    getch();
    return 0;
}

void MyStrrev(char str[])
{
     int i,j; char c;
     for(i=0,j=strlen(str)-1;i<j;i++,j--){
               c=str[j]; printf("c = %c\n",str[j]);
               str[j]=str[i]; printf("str[j=%d] = %c\n",j,str[i]);
               str[i]=c; printf("str[i=%d] = %c\n",i,c);
     } 
}
