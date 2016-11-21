#include<stdio.h>
#include<conio.h>

int main()
{
    int a,b,c;
    printf("Input Three Numbers: \n");
    scanf("%d%d%d", &a, &b, &c);
    if(a>b)
    {
         if(a>c)
         {
                printf("\n %d is the greatest number", a);
         }
         else
         {
                printf("\n %d is the greatest number", c);
         }
    }
    else if(b>a)
    {
         if(b>c)
         {
                printf("\n %d is the greatest number", b);
         }
         else
         {
                printf("\n %d is the greatest number", c);
         }
    }
    else if(c>a)
    {
         if(c>b)
         {      
                printf("\n %d is the greatest number", c);
         }
         else
         {
                printf("\n %d is the greatest number", b);
         }
    }
    getch();
    return 0;
}
