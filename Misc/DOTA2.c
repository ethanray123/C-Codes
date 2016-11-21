#include<stdio.h>
#include<conio.h>

void inputNum(int *);
void displayKills(int);
void repeat();

int main(){
    int kills, *killptr;
    printf("=====DOTA 2 Killstreaks=====\n\n");
    inputNum(&kills);
    displayKills(kills);
    getch();
    return 0;
}

void inputNum(int *killptr){
     printf("Enter your number of Kills Warrior: ");
     scanf("%d",&*killptr);
}

void displayKills(int kills){
     char answer;
     printf("Your number of Kills is %d, correct? (Y or N)  ",kills);
     scanf(" %c",&answer);
     if(answer == 'Y'){      
          switch(kills){
              case 0: case 1: case 2: printf("Sorry... Please keep on trying, I know you can do it..");break;
              case 3:printf("You are on a Killing Spree!!");break;
              case 4:printf("You are Dominating your Enemies");break;
              case 5:printf("That is a Mega Killstreak!");break;
              case 6:printf("You are now somewhat Unstopabble!!");break;
              case 7:printf("You are Wickedly Sick! Well in a Sense..");break;
              case 8:printf("You have reached Killing Spree!!");break;
              case 9:printf("Monster Killings... You must be very Hungry huh?");break;
              case 10:printf("Zeus had better packed his bags because there is a new ruler..");break;
              default: printf("Truly You are a Legend");
          }
     printf("\n\nDo you wish to let another Hero to participate in this Glory?  ");
     scanf(" %c",&answer);
             if(answer == 'Y'){
                   repeat();   
             }else{
                   system("cls");
                   printf("\nFarewell Mighty Warrior... Until are paths meet again");
             }
             
     }else if(answer == 'N'){
          repeat();
     }else{
          printf("Do you not understand what Yes and No is for? Leave at Once!!");
     }
}

void repeat(){
     system("cls");
     main();
}
