#include<stdio.h>
#include<conio.h>

int main(void)
{
    int year;
    float grade, plusp;
    char yeahno;
    printf("Input your Year Level: ");
    scanf("%d", &year);
    printf("Are you going to join the Aquaintance Party? y or n?: ");
    fflush(stdin);
    scanf("%c", &yeahno);
    
    switch(yeahno){
               
            case 'y' :  
            switch(year){
                         case 1: printf("What is your current grade? : ");
                                 scanf("%f", &grade);
                                 plusp = grade - 0.1;
                                 printf("Your block needs to have an intermission number for the aquaintance party :)!");
                                 printf("\nYour grade is now %.2f", plusp);break;
                         case 2:
                         case 3:
                         case 4:printf("Enjoy the Party!");break;
                         default:printf("Not a Year Level");break;
                        }
            case 'n' : printf("Have a Nice Day!");
            }
    
    getch();
    return 0;
}
