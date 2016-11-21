#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10

int main(){
    int array1[SIZE]={0}, ctr, small=0, distance=0, indexa=0;
    printf("Enter 10 Values to compare their differences between the number itself \n  and the number on it's right:\n\n");
    for(ctr=0;ctr<SIZE;ctr++){
         scanf("%d",&array1[ctr]);
    }
    
    small=array1[0]-array1[1];
    if(small<0){
         small*=-1;       
    }
    
    for(ctr=1;ctr<SIZE;ctr++){
         distance=array1[ctr]-array1[ctr+1];
         if(distance<0){
               distance*=-1;         
         }
         if(distance<small){
               indexa=ctr;
               break;           
         }                     
    }
    printf("\nThe value within array1[%d] has the smallest difference \nwith the number on it's right",indexa);
    getch();
    return 0;
}
