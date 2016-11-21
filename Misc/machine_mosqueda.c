#include<stdio.h>
#include<conio.h>

int main(void){
    int year, dep=4000, endyear=28000, accdep=0, price=28000;
    printf("\t\t\tDEPRECIATION SCHEDULE\t\n");
    printf("\t\t\t---------------------\t\n");
    printf("YEAR\t");
    printf("DEPRECIATION\t");
    printf("END OF YEAR VALUE\t");
    printf("ACCUMULATED DEPRECIATION\n");
    printf("----\t");
    printf("------------\t");
    printf("-----------------\t");
    printf("------------------------\t");
    for(year=1; year<=7; year++){
                printf(" %d  %10d %20d  %25d\n", year,dep,endyear=endyear-dep,accdep=accdep+4000);
    }
    getch();
    return 0;
}
