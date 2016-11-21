#include<stdio.h>
#include<conio.h>

int main(void){
  int x, i, ac[10]={0}; 
  char a[10], letter;
  
  for(i = 0; i < 10; i++ ){
     printf("Enter a Letter: ");
     scanf("%c", &a[i]);
  }
     /*for(x=0; x < 26; x++){
        if(ac[x]==a[i]){
            ac[x]++;            
        }
     }*/
  //}
  
  /*printf("Input a Letter: ");
  scanf("%c",&letter);
  printf("There are %d %cs among the outputs.",num[i],a[i]);*/
  getch();
  return 0;
}
