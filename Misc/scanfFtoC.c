#include<stdio.h>
#include<conio.h>

int main(){
    int ctr;
    float celsius,fahrenheit;
    printf("Enter Six Fahrenheit Temperatures: \n");
    for(ctr=1;ctr<=6;ctr++){
        scanf("%f", &fahrenheit);
        celsius = (5.0/9.0)*(fahrenheit-32.0);
        printf("in degrees celsius: %f", celsius);
    }
    getch();
    return 0;
}
