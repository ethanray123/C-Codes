#include<stdio.h>
#include<conio.h>

int main()
{
    int ctr2=3;
    printf("Divisible by 3(from 1 to 50):\n");
    while(ctr2<=50){
         if(ctr2 % 3 == 0){
             printf("%d\n", ctr2);
         }
         ctr2++;
    }
    getch();
    return 0;
}
