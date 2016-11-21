#include<stdio.h>
#include<conio.h>
#include<string.h>

char* isSpace(char str[]);
int main(){
    char str[10], *ptr; 
    printf("Enter a String: ");
    gets(str);
    
    ptr=isSpace(str);
    puts(ptr);
    getch();
    return 0;
}

char* isSpace(char str[]){
     int i,j,*newc;
     for(j=0;j<10;j++){
            for(i=0;i<10;i++){
                  if(isspace(str[i])){
                      strcpy(str+i,str+i+1); 
                  }
            }
    }
    newc=(int*)malloc(sizeof(int)*10);
    memcpy(newc,str,sizeof(int)*10);
    return newc;
}
