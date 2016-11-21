#include<stdio.h>
#include<conio.h>

int main(void)
{
    int a1, a2, a3;
    printf("Input 3 angles of a Triangle: \n");
    scanf("%d%d%d",&a1,&a2,&a3);
    if((a1+a2+a3)==180){
        if(a1==a2 && a2==a3){
             printf("The Triangle is Equilateral");
        }else if(a1==a2 || a2==a3 || a1==a3){
             printf("The Triangle is isosceles");
        }else if(a1!=a2 && a2!=a3){
             printf("The Triangle is Scalene");
        } 
    }else{
         printf("Not a Triangle"); 
    }
    
    getch();
    return 0;
}
