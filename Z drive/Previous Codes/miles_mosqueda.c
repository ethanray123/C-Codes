#include<stdio.h>
#include<conio.h>

/*Prototypes Here*/
float amountToMiles(float);
void rewards(float);

int main(){
    float input, miles=0, total=0;
    do{
           printf("Enter your credit card purchases: ");
           scanf("%f", &input);
           total = total + input;
           miles = amountToMiles(total);
           rewards(miles);
    }while(input!=0);
    printf("Have a Nice Day! :)"); 
    getch();
    return 0;
}
/*Sub-Functions Here*/
float amountToMiles(float totalCCPurchases){
    float numMiles=0;
    numMiles = totalCCPurchases/35; 
    return numMiles; 
}
void rewards(float numMiles){
    if(numMiles > 500 && numMiles <= 1000){
         printf("You can redeem a free round trip Domestic flight.\n");       
    }else if(numMiles > 1000 && numMiles <= 3500){
         printf("You can redeem a free round trip anywhere in Asia.\n"); 
    }else if(numMiles > 3500 && numMiles <= 6000){
         printf("You can redeem a free round trip to the Middle East.\n"); 
    }else if(numMiles > 6000){
         printf("You can redeem a free round trip to America.\n"); 
    }
}
