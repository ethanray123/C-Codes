#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
/*prototypes*/
char* rev(char *);
/*main*/
int main(){
    char youz[]="ethan ray";char *name; int i=0;
    puts(youz);
    //Upper CaSING 
    while(i<strlen(youz)){
          youz[i]=toupper(youz[i]);
          i++;
    }
    //reversing the string
    name = rev(youz);
    
    printf("The Name in Reverse and in Uppercase is: ");
    puts(name);
    getch();
    return 0;
}
//functions
char* rev(char you[]){
     int i,j;
     char *temp;
     
     j=strlen(you)-1; 
     temp=(char*)malloc(sizeof(int)*strlen(you));
     memcpy(temp,you,sizeof(int)*strlen(you));
     for(i=0; j>=0;i++,j--){
           temp[i] = you[j];                     
     }
     return temp;
}
