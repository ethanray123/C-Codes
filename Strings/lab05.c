#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
/*prototypes*/
char* rev(char *);
/*main*/
int main(){
    char youz[]="ethan ray";char name[20]={0}; int i=0;
    puts(youz);
    while(i<strlen(youz)){
          youz[i]=toupper(youz[i]);
          i++;
    }
    name = rev(youz);
    
    int j;
    j=strlen(youz)-1;
    for(i=0; j>=0; i++,j--){
           name[i] = youz[j];                     
    }
    
    printf("The Name in Reverse and in Uppercase is: ");
    puts(name);
    getch();
    return 0;
}
//functions
char* rev(char you[]){
     int i,j=strlen(you); char *temp;
     temp=(char*)malloc(sizeof(char)*j);
     for(i=0; j>=0;i++,j--){
           temp[i] = you[j];                     
     }
     return temp;
}
