#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
/*prototypes*/
int lowercase_cnt(char *);
/*main*/
int main(){
    char you[20]; int ctr;
    printf("Enter a String: ");
    gets(you);
    ctr = lowercase_cnt(you);
    printf("The number of lowercase letters in string (you) is %d",ctr);
    getch();
    return 0;
}
//functions
int lowercase_cnt(char you[]){
    int i, count=0;
    for(i=0;i<strlen(you);i++){
         if(islower(you[i]) && you[i]!=' '){
              count++;               
         }                   
    }
    return count;
}
