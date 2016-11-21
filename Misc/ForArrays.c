#include<stdio.h>
#include<conio.h>

int main(void){
  int i, a[5];
  for(i = 0; i < 5; i++ ){
     printf("Enter a number: ");
     scanf("%d", &a[i]);
  }
  
     printf("\n\nHere it is Backwards!\n\n");
  for(i = 4; i >=0; i--){
     printf("%d. %d\n\n", i+1, a[i]);
  }
  getch();
  return 0;
}
