#include<stdio.h>
#include<conio.h>

float flight(char choice);
float discount(float costflight);

int main(){
    char c;
    float flightcost, updatedcost;
    flightcost = flight(c);
    updatedcost = discount(flightcost);
    printf("Please Pay %.2f for your fare.",updatedcost);
    getch();
    return 0;
}

float flight(char choice){
    float cost;  
    printf("Enter a Flight (A - Bohol, B - Bacolod, C - Dumaguete): ");
    scanf("%c",&choice);
    switch(choice){
                   case 'A':cost=800.00;break;
                   case 'B':cost=950.00;break;
                   case 'C':cost=1050.00;break;               
    }
    return cost;  
}

float discount(float costflight){
    int type;
    float updated;
    printf("Enter your Passenger Type (1 - Student, 2 - Senior Citizen, 3 - Regular): ");
    scanf("%d",&type);  
    switch(type){
                 case 1:updated=costflight-(costflight*0.15);break;
                 case 2:;updated=costflight-(costflight*0.20);break;
                 case 3:updated=costflight;break;
    }
    return updated;
}
