#include<stdio.h>
#include<conio.h>

int main(void)
{
    int month;
    printf("Input a Month's Numerical Equivalent: \n");
    scanf("%d",&month);
    switch(month){
        case 1:
        case 3:
        case 5:
        case 7: 
        case 8:     
        case 10:     
        case 12:printf("There are 31 days in this Month.");break;
        case 4:
        case 6:
        case 9:
        case 11:printf("There are 30 days in this Month.");break;
        case 2:printf("There are 28 or 29 days in this Month.");break;
        default:printf("Not a Month");     
    }
    
    getch();
    return 0;
}
