#include<stdio.h>
#include<conio.h>

void yrCalc(int total, int *yearAddr, int *monthAddr, int *dayAddr);

int main (){
    int totalNumDays,year=1900,month=1,day=1;
    printf("Enter a Number of days: ");
    scanf("%d",&totalNumDays);
    printf("\n   Today is %d days from January 1, 1900\n",totalNumDays);
    printf("    Previous date is %d/%d/%d\n",month,day,year);
    yrCalc(totalNumDays,&year,&month,&day);
    printf("    The date is %d/%d/%d",month,day,year);
    getch();
    return 0;
}

void yrCalc(int total, int *yearAddr, int *monthAddr, int *dayAddr){
     int temp;
     if(total>=365){
         *yearAddr+=(total/365);
         total=total%365;
     }
     if(total>=30){
         *monthAddr+=(total/30);         
         total=total%30;
     }
     if(total<30){
           *dayAddr+=total;
     }
}
