#include<stdio.h>
#include<conio.h>

int main(void)
{
    int year, weight;
    printf("Input year: ");
    scanf("%d",&year);
    printf("Input your car's weight: ");
    scanf("%d",&weight);
    
    if(year<=1970){
          if(weight<2700){
               printf("weight class = 1\n Your fee = 16.50 php");
          }else if(weight==2700 || weight<=3800){
               printf("weight class = 2\n Your fee = 25.50 php");
          }else if(weight>3800){
               printf("weight class = 3\n Your fee = 46.50 php"); 
          }         
    }else if(year>=1971 && year<=1979){
          if(weight<2700){
               printf("weight class = 4\n Your fee = 27.00 php");           
          }else if(weight==2700 || weight<=3800){
               printf("weight class = 5\n Your fee = 30.50 php");
          }else if(weight>3800){
               printf("weight class = 6\n Your fee = 52.50 php"); 
          }                 
    }else if(year>=1980){
          if(weight<3800){
               printf("weight class = 7\n Your fee = 35.50 php");            
          }else if(weight>=3800){
               printf("weight class = 8\n Your fee = 65.50 php"); 
          }
    }
    
    
    getch();
    return 0;
}
