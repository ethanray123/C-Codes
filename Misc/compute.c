#include<stdio.h>
#include<conio.h>
#include<math.h>

void compute(int a, int b, int c);

int main(){
    int num1,num2,num3;
    printf("Input Three Integers for Calculation: \n");
    scanf("%d%d%d",&num1,&num2,&num3);
    compute(num1,num2,num3);
    getch();
    return 0;
}
void compute(int a, int b, int c){
    float x=0;
    x = (b + sqrt(pow(b,2)-4*a*c)) / (2*a);
    printf("The value of x is: %f",x);  
}
