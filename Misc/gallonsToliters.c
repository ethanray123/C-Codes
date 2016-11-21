#include<stdio.h>
#include<conio.h>

int main(){
    float gallons, liters;
    int ctr;
    float celsius,fahrenheit;
    printf("Enter Ten Values for Gallon: \n");
    for(ctr=1;ctr<=10;ctr++){
        scanf("%f", &gallons);
        liters = gallons*3.785;
        printf("is equal to %f liters", liters);
    }
    
    getch();
    return 0;
}
