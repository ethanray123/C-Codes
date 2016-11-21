#include<stdio.h>
#include<conio.h>

int main(){
    float n1, n2, n3, n4, ave=0;
    printf("Enter a number: ");
    scanf("%f",&n1);
    printf("Enter a second number: ");
    scanf("%f",&n2);
    printf("Enter a third number: ");
    scanf("%f",&n3);
    printf("Enter a fourth number: ");
    scanf("%f",&n4);
    
    ave=(n1+n2+n3+n4)/4;
    printf("Your Average is : %.2f",ave);
    getch();
    return 0;
}
