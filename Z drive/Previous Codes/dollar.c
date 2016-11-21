#include<stdio.h>
#include<conio.h>

float totamt(int,int,int,int);

int main(){
    int a,b,c,d;
    float dollars = 0;
    dollars = getCoins(a,b,c,d);
    dollars = totamt(a,b,c,d);
    printf("You have %.2f dollars.",dollars);
    getch();
    return 0;
}

int getCoins(int q, int d, int n, int p){
    printf("Input Number of Quarters: ");
    scanf("%d", &q);
    printf("Input Number of Dimes: ");
    scanf("%d", &d);
    printf("Input Number of Nickels: ");
    scanf("%d", &n);  
    printf("Input Number of Pennies: ");
    scanf("%d", &p);
    return q,d,n,p;      
}
float totamt(int quarters,int dimes,int nickels,int pennies){
      float dollar = 0;
      return quarters*0.25 + dimes*0.10 + nickels*0.05 + pennies*0.01;
}
