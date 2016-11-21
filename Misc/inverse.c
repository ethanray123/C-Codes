#include<stdio.h>
#include<conio.h>

int main()
{
    int num, digit=0;
    printf("Enter a number to inverse: ");
    scanf("%d", &num);
    do{
          digit=num%10;
          num=num/10;
          printf("%d", digit);
    }while(num!=0);
    getch();
    return 0;
}
