#include<stdio.h>
#include<conio.h>

int main()
{
    int num1;
    printf("Enter a Value: ");
    scanf("%d",&num1);
    if(num1==10)
    {
          printf("%d", num1*num1);        
    }//if 1
    else if(num1==9)
    {
          printf("Enter another Value: ");
          scanf("%d", &num1);
          if(num1==10)
          {
               printf("%d", num1*num1);       
          }//if 2
          else if(num1==2||num1==3)
          {
               printf("%d", num1*99);
          }//else if of if 2
    }//else if 1
    else if(num1==2||num1==3)
    {
          printf("%d", num1*99);
    }//else if 2
    getch();
    return 0;
}//main
