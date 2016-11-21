#include<stdio.h>
#include<conio.h>

int main(void)
{
    int month, day, year, date;
    printf("Enter the Numerical Equivalent of Your Birthdate\n");
    printf("Month: ");
    scanf("%d", &month);
    printf("Day: ");
    scanf("%d", &day);
    printf("Year: ");
    scanf("%d", &year);
    
    date=((year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400)%7;
    switch(month){
        case 12: date+=30;
        case 11: date+=31;
        case 10: date+=30;
        case 9: date+=31;
        case 8: date+=31;
        case 7: date+=30;
        case 6: date+=31;
        case 5: date+=30;
        case 4: date+=31;
        case 3: date+=28;
        case 2: date+=31;
    }
         
    date=date+day;
    date=date%7;
         
         if((!(year % 4) && (year % 100)) || !(year % 400)){
              if(month>=3){
                   date+=1;        
              }      
         }
        
         switch(date){
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
