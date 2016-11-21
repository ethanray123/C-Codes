#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
//prototyping
void cardflip(int, int);
//main
int main(){
    int ctr=0, nocards, c1, c2, *cards;
    printf("Welcome to Memory Cards!\n\nEnter an equal number of cards(ex. 4): ");
    scanf("%d",&nocards);
    cards=(int*)malloc(sizeof(int)*nocards);
    srand((unsigned)time(NULL));
    do{
        printf("* ");
        cards[ctr]=rand(9);
        ctr++;          
    }while(ctr<nocards);
    printf("\n\nNow, kindly choose 2 cards to flip up and see if they are a pair of a kind.\nIf not, then I'm afraid you're going to try again :).\nGet all the cards to flip right side up to win the game!\nGoodluck to you :D\n\n");
    printf("Enter First Card: "); scanf("%d",&c1); fflush(stdin);
    printf("Enter Second Card: "); scanf("%d",&c2);
    cardflip(c1,c2);
    cardcheck();
    getch();
}
//Other Funcs
void cardflip(int first, int second){
     //Some sort of loop
            if(cards[i]==){
                 printf("");
            }
}

void cardcheck(){
     for()
     if(cards)
}
