#include<stdio.h>
#include<conio.h>

int main()
{
    float j;
    int num;
     for(j = 20.0, num=1; j >= 10.0; j-=0.5, num++){
		printf("%d\n", num);
     }

    getch();
    return 0;
}
