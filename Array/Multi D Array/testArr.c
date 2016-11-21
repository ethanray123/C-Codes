#include<stdio.h>
#include<conio.h>
#include<string.h>

#define m 4
#define b 4

void display(int[][]);
void load_identity(int [][]);

int main(){
    int row,col;
    int matrixA[m][b]={0};
    int matrixB[m][b]={0};
    load_identity(matrixA);
    display(matrixA);
      
    getch();
    return 0;
}

void display(int arr[m][b]){
     int i,j;
     for(i=0;i<m;i++){
         for(j=0;j<b;j++){
              printf("%d\t",arr[i][j]);
         }
         printf("\n\n");
    }     
}

void load_identity(int arr[m][b]){
    int i,j;
    
    for(i=0;i<m;i++){
         for(j=0;j<b;j++){
              if(i==j){    
                    arr[i][j]=1;
              }else{
                    arr[i][j]=0;
              }
         }
    }  
}
