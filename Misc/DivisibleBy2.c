#include<stdio.h>
#include<conio.h>

int main()
{
    int ctr=10;
    printf("Divisible by 2(from 10 to 20):\n");
    while(ctr<=20){
         if(ctr % 2 == 0){
             printf("%d\n", ctr);
         }
         ctr++;
    }
    getch();
    return 0;
}
