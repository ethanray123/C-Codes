#include<stdio.h>
#include<conio.h>

int main()
{
    int i;
    float total=1.0;
    for(i = 1;i <= 5;i++){
          total = total/2.0;
          printf("%f\n", total);
    }

    getch();
    return 0;
}
