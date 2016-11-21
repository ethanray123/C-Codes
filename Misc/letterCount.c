#include<stdio.h>
#include<conio.h>
#include<string.h>

void introduction();
char* enterALetter();
void letterCount(char lttr[],char c);

int main()
{
    char *a,letter;
    introduction();
    a = enterALetter();
    letterCount(a,letter);
}

void introduction()
{
     printf("Hello and welcome to the Letter Counter!\n\n");
}

char* enterALetter()
{
      char l[10],*nl; int i;
      printf("Enter some letters(10): \n"); 
      for(i=0;i<10;i++){
             fflush(stdin);
             scanf(" %c",&l[i]);
      }
      nl = (char*)malloc(sizeof(char)*i);
      memcpy(nl,l,sizeof(char)*i);
      return nl;
}

void letterCount(char lttr[],char c)
{
     int i,ctr=0;
     printf("Input a letter to count: ");
     scanf(" %c",&c);
     for(i=0;i<10;i++){
             if(c==lttr[i]){
                  ctr++;
             }
     }
     printf("number of %c: %d",c,ctr);
     getch();
}
