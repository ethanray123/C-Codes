#include<stdio.h>
#include<conio.h>

int main(void){
  int i, a[10], big=0;
  for(i = 0; i < 10; i++ ){
     printf("Enter a number: ");
     scanf("%d", &a[i]);
     if(a[i]>big){
          big=a[i];
     }
  }
  printf("The greatest number is %d", big);
  getch();
  return 0;
}
