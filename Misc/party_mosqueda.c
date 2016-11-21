#include<stdio.h>
#include<conio.h>

int main(void)
{
    int year;
    char ans;
    float grade;
    
    printf("Enter your Year Level: ");
    scanf("%d",&year);
    printf("Are you going to the Aquaintance Party?(Y or N): ");
    fflush(stdin);
    scanf("%c",&ans);
    
    switch(ans){
        case 'y':
        case 'Y':switch(year){
                      case 1:printf("Enter your Current Grade: ");
                             scanf("%f",&grade);
                             grade=grade-0.1;
                             printf("Your Grade is now %.1f\n", grade);
                             printf("Your block needs to present an intermission number during the aquaintance party.\nHave fun :D!!");break;
                      case 2:
                      case 3:
                      case 4:printf("Great! Enjoy the Party! :)");break;
                      default:printf("This is not a Year Level.. -_-#");
                 
                 };break;
        case 'n':
        case 'N':printf("Awwee.. That's too bad. Well, Enjoy your day! :D");break;
    }
    
    getch();
    return 0;
}
