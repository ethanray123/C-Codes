#include<stdio.h>
#include<conio.h>

void swap(int *x,int *y);

int main()
{
    int x = 10, y = 5;
    printf("Before: x - %d y - %d", x,y);
    swap(&x,&y);
    printf("\n\nAfter: x - %d y - %d", x,y);
    getch();
    return 0;
    getch();
    return 0;
}

void swap(int *x, int *y)
{
     int temp;
     temp = *x;
     *x = *y;
     *y = temp;
     
}
