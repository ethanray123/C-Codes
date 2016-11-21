#include<stdio.h>
#include<conio.h>
#define size 10
int main(){
    int a[size];
    int i, large;
    printf("Enter 10 Numbers: \n");
    scanf("%d",&a[0]);
    large = a[0];
    for(i=1;i<size;i++){
        scanf("%d",&a[i]);
        if(a[i]>large){
           large = a[i];
        }           
    }
    printf("\n %d is the largest number.",large);
    getch();
    return 0;
}
