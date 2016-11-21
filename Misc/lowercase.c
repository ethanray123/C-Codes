#include<stdio.h>
#include<conio.h>

int main(void)
{
    char ch;
    int place = 0;
    printf("Enter a character: ");
    scanf("%c",&ch);
    if(ch >= 'a' && ch <= 'z'){
          place = ch - 'a' + 1;
          printf("%d", place);
    }else{
          place = ch - 'A' + 1;
          printf("%d", place);
    }
    
    getch();
    return 0;
}
