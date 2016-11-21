#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){
    int a,b,c;
    float x=0;
    printf("Input Three Integers for Calculation: \n");
    scanf("%d%d%d",&a,&b,&c);
    x = (b + sqrt(pow(b,2)-4*a*c)) / (2*a);
    printf("The value of x is: %.2f",x);  
    getch();
    return 0;
}
