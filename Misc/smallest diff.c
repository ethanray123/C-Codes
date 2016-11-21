#include<stdio.h>
#include<conio.h>
#define SIZE 10

int main(){
    int array1[SIZE]={0}, ctr, absol=0, small=0, indexa=0;
    printf("Enter 10 Values to compare their differences between the number itself \n  and the number on it's right:\n\n");
    
    for(ctr=0;ctr<SIZE;ctr++){
         scanf("%d",&array1[ctr]);
         if(ctr!=0 && ctr!=9){
              if(ctr==1){
                    small=array1[ctr-1]-array1[ctr];
                    if(small<0){small*=-1;}    
              }else{
              absol=array1[ctr-1]-array1[ctr];
                    if(absol<0){absol*=-1;}
                    if(absol<small){
                                small=absol;     
                                indexa=ctr-1;
                    }
              }
         }
    }
    
    printf("\nThe value within array1[%d] has the smallest difference \nwith the number on it's right",indexa);
    getch();
    return 0;
}
