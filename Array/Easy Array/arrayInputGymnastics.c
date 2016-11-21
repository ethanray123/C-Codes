#include<stdio.h>
#include<conio.h>
#define SIZE 7

void inputScores(float scores[],int size);
void displayAverage(float scores[],int size);
float displayHigh(float scores[],int size);
float displayLow(float scores[],int size);

int main(){
    
    float scores[SIZE];
    inputScores(scores, SIZE);
    displayAverage(scores, SIZE);
    
    getch();
    return 0;
}

void inputScores(float scores[], int size){
     int i;
     printf("Input the Scores: \n");
     for(i=0;i<SIZE;i++){
         scanf("%f",&scores[i]);
     }
}

void displayAverage(float scores[],int size){
     float highest,lowest;
     float sum=0, average=0;
     int i;
     
     highest = displayHigh(scores, SIZE);
     lowest = displayLow(scores, SIZE);
     
     for(i=0;i<SIZE;i++){
         if(scores[i]==highest){
              scores[i]=0;             
         }
         if(scores[i]==lowest){
              scores[i]=0; 
         }
         sum+=scores[i];                 
     }
     average = sum/5;
     printf("\nThe Average Score is: %.1f",average);
}

float displayHigh(float scores[],int size){
     int i;
     float high;
     high = scores[0];
     for(i=1;i<SIZE;i++){
         if(scores[i]>high){
             high = scores[i];
         } 
     }
     printf("\nThe Highest Score given: %.2f",high);
     return high;
}

float displayLow(float scores[],int size){
     int i;
     float low;
     low = scores[0];
     for(i=1;i<SIZE;i++){
         if(scores[i]<low){
             low = scores[i];
         } 
     }
     printf("\nThe Lowest Score given: %.2f",low);
     return low; 
}
