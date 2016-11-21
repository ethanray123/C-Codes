#include<stdio.h>
#include<conio.h>
#include<math.h>

int hypotenuse(int a,int b);

int main(){
    int hyp, s1, s2;
    hyp = hypotenuse(s1,s2);
    printf("Hypotenuse is : %d",hyp);
    getch();
    return 0;
}
int hypotenuse(int a,int b){
    int c;
    printf("Two sides of a triangle: \n");
    scanf("%d%d",&a,&b);
    c=sqrt((a*a)+(b*b));
    return c;
}
