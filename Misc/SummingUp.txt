#include<stdio.h>
#include<conio.h>

void SumUp(int num);

int main(){
     int n;
     SumUp(n);
     getch();
     return 0;
}

void SumUp(int num){
     int d=0; int s=0;
     printf("Input a Number: ");
     scanf("%d", &num); 
     do{      
          d=num%10;
          s=s+d;
          num=num/10;  
     }while(num!=0);
     printf("The sum of the given number's digits is: %d",s);
}
