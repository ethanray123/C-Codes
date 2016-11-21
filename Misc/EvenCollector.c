#include<stdio.h>
#include<conio.h>
#define SIZE 10

int copyAllEventoArr(int nums[]);
int main(void){
    int *new, origArray[SIZE]={0}, ctr;
    for(ctr=0;ctr<SIZE;ctr++){
       printf("Enter a number (%d): ", ctr+1);
       scanf("%d",&origArray[ctr]);
    }
    new=copyAllEventoArr(origArray);
    printf("\nHere is the new array with the contents transferred from the previous array");
    for(ctr=0;ctr<SIZE;ctr++){
           printf("\n%d\n",*(new+ctr));
    }
    getch();
    return 0;
}
int copyAllEventoArr(int nums[]){
    static int evenNums[SIZE];
    int ctr;
    for(ctr=0;ctr<SIZE;ctr++){
          evenNums[ctr]=nums[ctr];              
    }
    return evenNums;
}

