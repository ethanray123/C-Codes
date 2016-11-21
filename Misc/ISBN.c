#include<stdio.h>
#include<conio.h>
#define Size 10

char validateISBN(unsigned long);
int calcWeightSum(int *, int);

int main(){
    unsigned long ISBN;
    printf("Enter the book's ISBN: ");
    scanf("%lu",&ISBN);
    switch(validateISBN(ISBN)){
             case 'V': printf("Valid ISBN.");break;
             case 'I': printf("Invalid ISBN. ");break;
    }
    getch();
    return 0;
}

char validateISBN(unsigned long ISBN){
     int weightVal[Size]={0}, ctr, digit=0, i=10, sum;
     for(ctr=0;ctr<Size;ctr++){
           digit=ISBN%10;
           ISBN=ISBN/10;                    
           weightVal[ctr]=digit*i;
           i--;
     }
     int x=10;
     sum=calcWeightSum(weightVal,x);
}

int calcWeightSum(int weightValues[], int size){
    int ws=0, ctr;
    for(ctr=0;ctr<Size;ctr++){
          ws+=weightValues[ctr];
    }
    if(ws%11==0){
          return 'V';
    }else{ 
          return 'I'; 
    }
}
