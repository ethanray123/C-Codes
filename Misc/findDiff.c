#include<stdio.h>
#include<conio.h>

int* findDiff(int setA[], int setB[], int *n);

int main()
{
    int set1[5]={1,3,6,7,9}; int i=0,N=5;
    int set2[5]={1,3,6,8,10};
    int *setAminB;
    
    printf("\nSet A = { ");
    while(i<N){
          printf("%d ",set1[i++]);
    } printf("}\n"); i=0;
    
    printf("Set B = { ");
    while(i<N){
          printf("%d ",set2[i++]);
    } printf("}\n"); i=0;
    
    
    setAminB = findDiff(set1,set2,&N);
    if(setAminB==NULL){
         printf("Set A-B = { }");              
    }else{
         printf("Set A-B = { ");
         while(i<N){
              printf("%d ",setAminB[i++]);
         } printf("}"); i=0;
    }
    getch();
    return 0;
}

int* findDiff(int setA[], int setB[], int *n)
{
     int x,y,ctr=0, setC[5]={0}, *newSet;
     for(x=0;x<*n;x++){
           for(y=0;y<*n;y++){
                if(setA[x]==setB[y]){ 
                    y=*n; 
                }else if(setA[x]!=setB[y] && y==*n-1){
                    setC[ctr]=setA[x];
                    ctr++;
                }
           }
     }
     if(ctr==0){
            newSet=NULL;
     }else{
         newSet=(int*)malloc(sizeof(int)*ctr);
         memcpy(newSet,setC,sizeof(int)*ctr);
         *n=ctr;
     }
     return newSet;
}
