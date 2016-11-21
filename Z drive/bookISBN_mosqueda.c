#include<stdio.h>
#include<conio.h>
#define SIZE 10

int sumOfWeightedVal(int weightedVal[], int ISBN);
void isValidISBN(int weightSum);

int main(){
   int i, ISBN, weightSum, weightedVal[SIZE];
   printf("Hello and Welcome! :)\n\n");
   printf("Enter an ISBN: ");
   scanf("%d",&ISBN);
   weightSum = sumOfWeightedVal(weightedVal,ISBN);
   isValidISBN(weightSum);
   getch();
   return 0; 
}

int sumOfWeightedVal(int weightedVal[], int ISBN){
    int i, x, weight, digit=0,num=0;
    int sum=0;
    
    for(i=0,x=9;i<SIZE;i++){                 
         digit=ISBN%10;
         weightedVal[x]=digit;
         ISBN=ISBN/10;
         x--;                    
    }
    
    for(i=0,weight=10;i<SIZE;i++){
         num=weightedVal[i]*weight; 
         sum=sum+num;
         weight--;          
    }
    
    return sum;
}

void isValidISBN(int weightSum){
     if(weightSum % 11 == 0){
           printf("VALID ISBN");                
     }else{
           printf("INVALID ISBN");
     }         
}
