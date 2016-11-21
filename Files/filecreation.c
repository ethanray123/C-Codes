#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char string[10];
    fp = fopen("meep.txt","w");
    fprintf(fp,"asjdfnowaf");
    fclose(fp);
    getch();
    return 0;
}

/*if((fp = fopen("meep.txt","w")) == NULL){
       printf("File not opened");
       getch();     
       exit(1);
    }*/
