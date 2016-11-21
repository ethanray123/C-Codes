#include<stdio.h>
#include<conio.h>
#define SIZE 5

int subSet(int arrA[], int arrB[], int aCount, int bCount);
int main(void){
    int aCnt=3, bCnt=5, subOrNot; char ans;
    int arr1[3]={1,4,2}, arr2[5]={1,2,4,6,5};
    printf("Start?  ");
    scanf("%c",&ans);
    if(ans=='y'){
               subOrNot=subSet(arr1,arr2,aCnt,bCnt);
               if(subOrNot==1){
                               printf("Set A is a Subset of Set B. yey!!!");
               }else{
                     printf("Set A is not a Subset of Set B. awwee...");
               }
    }else{
          printf("ending simulation..");
    }
    getch();
    return 0;
}

int subSet(int arrA[],int arrB[], int aCount, int bCount){
    int i=0, ctr=0;
    while(i<aCount && ctr<bCount-1){
          if(arrA[i]==arrB[ctr]){
                i++; ctr=0;        
          }else{
                ctr++;
          }  
    }
    if(i==aCount){
         return 1;   
    }else{
          return 0;  
    }
}
