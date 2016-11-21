#include<stdio.h>
#include<conio.h>

void liquid(int total, int *gallons, int *quarts, int *pints, int *cups);

int main(){
    int total=0, gallons=0, quarts=0, pints=0, cups=0;
    printf("Enter a Number of Cups: ",total);
    scanf("%d",&total);
    liquid(total,&gallons,&quarts,&pints,&cups);
    printf("\nThere are %d Gallon/s, %d Quart/s, %d Pint/s, and %d Cup/s\n", gallons,quarts,pints,cups);
    getch();
    return 0;
}

void liquid(int total, int *gallons, int *quarts, int *pints, int *cups){
     if(total>=16){
         *gallons=total/16;
         total=total%16;
         printf("Cups left from Gallons: %d\n", total);
     }
     if(total>=4){
         *quarts=total/4;
         total=total%4;
         printf("Cups left from Quarts: %d\n", total);
     }
     if(total>=2){
         *pints=total/2;
         total=total%2;
         printf("Cups left from Pints: %d\n", total);
     }
     *cups=total;
}
