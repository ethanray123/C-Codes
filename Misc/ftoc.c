#include<stdio.h>
#include<conio.h>

int main(){
    int ctr;
    float celsius,fahrenheit = 20;
    for(ctr=1;ctr<=20;ctr++){
          celsius = (5.0/9.0)*(fahrenheit-32.0);
          printf("%.1f degrees fahrenheit is equal to %.1f degrees celsius\n", fahrenheit, celsius);
          fahrenheit+=4;
    }
    getch();
    return 0;
}
