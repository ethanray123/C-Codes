#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
//prototyping
void cardflip(int*, int*);
//main
int main(){
    int ctr=0, match, c1, c2, cards[10]={2,1,1,3,2,4,3,5,4,5}, flip[10]={0}, checked[10]={0};
    printf("Welcome to Memory Cards!");
    printf("\n\nNow, kindly choose 2 cards to flip up and see if they are a pair of a kind.\nIf not, then I'm afraid you're going to try again :).\nGet all the cards to flip right side up to win the game!\nGoodluck to you :D\n\n");
    do{
        cardflip(cards,flip);//First Show
        printf("\n\nEnter First Card: "); scanf("%d",&c1); fflush(stdin);
        printf("Enter Second Card: "); scanf("%d",&c2);
        if(c1<11 && c2<11 && c1!=0 && c2!=0 && c1!=c2){
                 if(cards[c1-1]==cards[c2-1] && checked[c1-1]==0 && checked[c2-1]==0){
                                              flip[c1-1]=1; checked[c1-1]=1;
                                              flip[c2-1]=1; checked[c2-1]=1;
                                              ctr++;
                                              match=1;
                 }else if(checked[c1-1]==1 || checked[c2-1]==1){
                       match=2;
                       printf("Invalid Card.");
                       getch();
                 }else{
                       flip[c1-1]=1;
                       flip[c2-1]=1;
                       match=0;
                 }
                 system("cls");
                 cardflip(cards,flip);//Second Show (with flipped cards)
                 
                 if(match==1){
                              printf("\n\nCool! Continue\n");
                              getch();
                              system("cls");
                 }else if(match==0){
                       printf("\n\nI'm sorry try again...\n");
                       flip[c1-1]=0; flip[c2-1]=0;
                       getch();
                       system("cls");
                 }else{ 
                       system("cls");
                 }
        }else{
             printf("Invalid Card.");
             getch();
             system("cls");
        }
    }while(ctr<5);//end of loop
    printf("You have reached your goal! Congratulations!! XD\n EXITING GAME... (press any key to continue)");
    getch();
}//end of main

//Other Funcs
void cardflip(int c[],int face[]){
     int i;
     printf("\n");
     for(i=0;i<10;i++){
            if(face[i]==1){
                 printf("%d ",c[i]);
            }
            else{
                 printf("* "); 
            }
     }
}
