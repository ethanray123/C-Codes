#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
/*prototypes*/
int last_num(char *);
/*main*/
int main(){
    char youz[20]; int index;
    printf("Enter a String: ");
    gets(youz);
    index = last_num(youz);
    printf("The last item '%c' is in you[%d]",youz[index],index);
    getch();
    return 0;
}
//functions
int last_num(char you[]){
    int ind = strlen(you) - 1;
}
