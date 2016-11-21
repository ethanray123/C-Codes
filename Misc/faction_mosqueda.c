#include<stdio.h>
#include<conio.h>
int main(void)
{
    int age; char faction;
    float aptitudeTestScore;
    printf("Enter age: ");
    scanf("%d",&age);
    if(age>=16){
         printf("Enter your Aptitude Test Score: ");
         scanf("%f",&aptitudeTestScore);
         if(aptitudeTestScore>=50){
            printf("You have Passed!\nChoose Your Faction Wisely: ");
            fflush(stdin);
            scanf("%c",&faction);
            switch(faction){
                  case 'A': printf("\nYou have Chosen Abnegation");break;
                  case 'B': printf("\nYou have Chosen Amity");break;         
                  case 'C': printf("\nYou have Chosen Candor");break;
                  case 'D': printf("\nYou have Chosen Dauntless");break;
                  case 'E': printf("\nYou have Chosen Erudite");break;
                  default: printf("\nThis is not a Faction");break;
            }
         }else{
            printf("You are now factionless...");   
         }
    }else{
         printf("You aren't old enough to participate in the choosing of your faction..."); 
    }
    
    getch();
    return 0;
}
