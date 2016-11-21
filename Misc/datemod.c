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
          
          default:printf("Not a Month");
         /*do{}while(day>=1 && day<=31);*/
          case 1:printf("January %d", day);  
          case 3:printf("March %d", day);
          case 5:printf("May %d", day);
          case 7:printf("July %d", day);
          case 8:printf("August %d", day);
          case 10:printf("October %d", day);
          case 12:printf("December %d", day);
          //}
    
         /*do{}while(day>=1 && day<=30); */
         
         //switch(month){     
          case 4:printf("April %d", day);
          case 6:printf("June %d", day);
          case 9:printf("September %d", day);
          case 11:printf("November %d", day);
          //}
    
         /*do{}while(day>=1 && day<=28);*/ 
    
         //switch(month){
          case 2:printf("February %d", day);
          //}
          
          
    }
    switch(month){
                  
    }
    getch();
    return 0;
}
