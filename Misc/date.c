#include<stdio.h>
#include<conio.h>

int main ()
{
    int month=0, day=0;
    printf("Enter a Month: ");
    scanf("%d", &month);
    printf("Enter a Day: ");
    scanf("%d", &day);
     switch(month){

      do{
          case 1:;
          case 3:;
          case 5:;
          case 7:;
          case 8:;
          case 10:;
          case 12:;
      }while(day>=1 && day<=31);
      
      do{
          case 4:;
          case 6:;
          case 9:;
          case 11:;
      }while(day>=1 && day<=30);    
      
      do{
          case 2:;
      }while(day>=1 && day<=28);
      
          default:printf("Enter a Month: ");
          scanf("%d", &month);
          printf("Enter a Day: ");
          scanf("%d", &day);  
    }
    getch();
    return 0;
}
