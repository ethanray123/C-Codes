#include<stdio.h>
#include<conio.h>
int main(void)
{
    int month, day, year, dayofweek;
    printf("Enter the Numerical Equivalent of Your Birthdate\n");
    printf("Month: ");
    scanf("%d", &month);
    printf("Day: ");
    scanf("%d", &day);
    printf("Year: ");
    scanf("%d", &year);
    dayofweek = ((2014-1)*365+((2014-1)/4)-((2014-1)/100)+((2014-1)/400))%7;
                                 
         switch(month){
               case 12: day+30;break;
               case 11: day+31;break;
               case 10: day+30;break;
               case  9: day+31;break;
               case  8: day+31;break;
               case  7: day+30;break;
               case  6: day+31;break;
               case  5: day+30;break;
               case  4: day+31;break;
               case  3: day+28+1;break;
               case  2: day+31;break;
         }
        
    switch(dayofweek){
               case 0: printf("Sunday");break; 
               case 1: printf("Monday");break;
               case 2: printf("Tuesday");break; 
               case 3: printf("Wednesday");break; 
               case 4: printf("Thursday");break; 
               case 5: printf("Friday");break; 
               case 6: printf("Saturday");break;
    }
                
    getch();
    return 0;
}

/*
  add the no. of days
  if(!(year%4)&&(year%100)||(year%400){}
*/
