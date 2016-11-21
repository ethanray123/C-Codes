#include<stdio.h> 
#include<conio.h>
int main(void) 
{ 
	float amt, source, dest; 
	printf(“\nEnter the Source Fund amt: “); scanf(“%f”,&source); 
	printf(“Enter the Destination Fund amt: “); scanf(“%f”,&dest); 
	printf(“Enter amount to transfer : “); scanf(“%f”,&amt); 
    switch(transferFunds(amt,&source,&dest)) 
    { 
      case 1: printf(“Money is transferred successfully.”); break; 
      case 2: printf(“Error: Source fund is insufficient.”); break; 
      case 3: printf(“Error: Negative transfer amount or amount is zero.”); break; 
    } 
    getch();
    return 0;
}
