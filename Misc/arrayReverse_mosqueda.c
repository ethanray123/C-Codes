#include<stdio.h>
#include<conio.h>
#define SIZE 4

void reverseArray(int A[], int size);

int main(){
    int i=0;
    int A[SIZE]={1,2,3,4};
    for(i=0;i<SIZE;i++){
          printf("A[%d] = %d\n", i, A[i]);
    }
    printf("Reversed:\n");
    reverseArray(A, SIZE);
    getch();
    return 0;
}

void reverseArray(int A[], int size){
    int i=0, x=SIZE;
    do{
        A[i]=x;
        x--;
        i++;
    }while(i<SIZE);
    
    for(i=0;i<SIZE;i++){
          printf("A[%d] = %d\n", i, A[i]);
    } 
}
