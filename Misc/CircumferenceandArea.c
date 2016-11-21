#include<stdio.h>

int main()
{
    int grade;
    
    printf("Please Input your Grade: ");
    scanf("%d", &grade);
    if(grade >= 70)
        printf("A passing grade");
    else
        printf("A failing grade");

    getch();
    return 0;
}
