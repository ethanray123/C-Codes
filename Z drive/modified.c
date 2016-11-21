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
    int i, weight, sum=0;
    
    for(i=SIZE-1, weight=1; i>=0; i--, weight++){ 
         weightedVal[i]=ISBN%10*weight;
         sum+=weightedVal[i];
         ISBN=ISBN/10;        
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
