#include<stdio.h>
#include<conio.h>
#include<string.h>
#define m 4
#define b 4

void multTable(int A[][],int row,int col);
void normMatrix(int A[][],int row,int col);
void idenMatrix(int A[][],int row,int col);
void displaymdArr(int A[][],int row,int col);

int main(){
    
    int mTable[m][b];int i,j;
    int nMatrix[m][b];
    int iMatrix[m][b];
    
    multTable(mTable,m,b);
    printf("multTable\n\n");
    displaymdArr(mTable,m,b);
    
    normMatrix(nMatrix,m,b);
    printf("Matrix\n\n");
    displaymdArr(nMatrix,m,b);
    
    idenMatrix(iMatrix,m,b);
    printf("Identity Matrix\n\n");
    displaymdArr(iMatrix,m,b);
    
    getch();
    return 0;
}

void multTable(int A[][b],int row, int col){
    int i,j;
    
    for(i=0;i<row;i++){           
          for(j=0;j<col;j++){
                A[i][j]=(i+1)*(j+1);
          }
    }
}

void displaymdArr(int A[][b],int row,int col){
     int i,j;
     
     for(i=0;i<row;i++){
          for(j=0;j<col;j++){
                printf("%d\t",A[i][j]);
          }
                printf("\n\n");
    }
}

void normMatrix(int A[][b],int row,int col){
     int i,j;
     
     for(i=0;i<row;i++){
           for(j=0;j<row;j++){
                 A[i][j]=1;
           }
     }
}

void idenMatrix(int A[][b],int row,int col){
     int i,j;
     
     for(i=0;i<row;i++){
          for(j=0;j<col;j++){
                if(i==j){
                     A[i][j]=1;
                }else{
                     A[i][j]=0;
                }
          }
     }
}
