#include<stdio.h>
#include<conio.h>
#define SIZE 10

int isEqual(int A[], int B[], int size);

int main(){
    int A[SIZE]={1,2,3,4,5,6,7,8,9,10};
    int B[SIZE]={1,2,3,4,5,6,7,8,9,10};
    int val;
    
    val = isEqual(A,B,SIZE);
    if(val==1){
         printf("All the elements are equal.");
    }else{
         printf("At least one element is not equal."); 
    }
    getch();
    return 0;
}

int isEqual(int A[], int B[], int size){
    int i=0;
    do{
        if(A[i]!=B[i]){
            return 0;   
        } 
        i++;
    }while(i<SIZE);
    return 1;
}
