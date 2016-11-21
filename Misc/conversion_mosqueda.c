#include<stdio.h>
#include<conio.h>

int main(void){
    
    int num, ctr;
    float fahrenheit, celsius;
    printf("How many Conversions?: ");
    scanf("%d", &num);
    printf("Enter a Value for Fahrenheit: \n");
          scanf("%f",&fahrenheit);
          
    for(ctr=1; ctr<=num; ctr++){
          fahrenheit=fahrenheit+5;
          celsius = (5.0/9.0)*(fahrenheit-32.0);
          printf("\n%.2f in Celsius is: %.2f\n\n", fahrenheit, celsius);
    }
    getch();
    return 0;   
}
