#include<stdio.h>
#include<conio.h>

int managePrisoners(char option, int number, int prisonCnt);

int main(){
    int numprisoners;
    char o; int n; int pc=970;
    
         printf("Do You want to add Prisoners? or Release them? (A or R) ");
         scanf("%c",&o);
         numprisoners = managePrisoners(o,n,pc);
         //numprisoners = pc;
         printf("\nCurrent no. of Prisoners: %d\n\n",numprisoners);
    
    getch();
    return 0;
}
int managePrisoners(char option, int number, int prisonCnt){
    if(option=='A'){
          printf("Enter a Number of Prisoners to Add: ");
          scanf("%d",&number);
          if(prisonCnt<1000){
              prisonCnt = prisonCnt + number;
              if(prisonCnt>1000){
                    printf("Prison can no longer accomodate that much.");
                    prisonCnt-=number;
              }else{
                    printf("%d New Prisoners Added",number);
              }                
          }else{
              printf("Prison already at Full Capacity!");    
          }          
    }else if(option=='R'){
          printf("Enter a Number of Prisoners to Release: ");
          scanf("%d",&number);
          if(prisonCnt>=number){
              if(prisonCnt<=1000){
              prisonCnt = prisonCnt - number;
              printf("%d Prisoners Released",number);
              }                  
          }else{
              printf("Error:Requested Number is Greater than the no. of Prisoners!");  
          }
    return prisonCnt;
}
