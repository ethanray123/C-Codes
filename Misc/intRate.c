#include<stdio.h>
#include<conio.h>

int main(void)
{
    float time;
    printf("Enter the time(in years): ");
    scanf("%f", &time);
    if(time >= 5){
          printf("Your Interest Rate is: 0.045");
    }else if(time < 5 && time >= 4){
          printf("Your Interest Rate is: 0.04");
    }else if(time < 4 && time >= 3){
          printf("Your Interest Rate is: 0.035");
    }else if(time < 3 && time >= 2){
          printf("Your Interest Rate is: 0.03");
    }else if(time < 2 && time >= 1){
          printf("Your Interest Rate is: 0.025");
    }else{
          printf("Your Interest Rate is: 0.2");
    }
    getch();
    return 0;
}
