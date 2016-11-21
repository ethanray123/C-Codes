#include<stdio.h>
#include<conio.h>
#include<string.h>

int* findDiff(int*,int*);
int main()
{
    int arr1[]={1,3,4,6,9}, arr2[]={2,3,6,8,10}, *diffarr={0}, i;
    diffarr=findDiff(arr1,arr2);
    printf("A = { ");
    for(i=0;i<5;i++){
            printf("%d ",arr1[i]);         
    }
    printf("}");
    
    printf("\nB = { ");
    for(i=0;i<5;i++){
            printf("%d ",arr2[i]);         
    }
    printf("}");    
    
    printf("\nA-B = { ");
    for(i=0;diffarr[i]!='\0';i++){
            printf("%d ",diffarr[i]);
    }
    printf("}");
    getch();
    return 0;
}

int* findDiff(int *A,int *B){
     int i, j, x, checker=0, *C;
     C=(int*)malloc(sizeof(int)*5);
     for(i=0,j=0;i<5;i++){    
         checker=0;
         for(x=0;x<5;x++){             
              if(A[i]==B[x]){ checker=1; }
         }
         if(checker==0){
               C[j]=A[i]; j++;
         }
     }
     C[j]='\0';
     return C;
}
