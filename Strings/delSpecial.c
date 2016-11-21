#include<stdio.h>
#include<conio.h>
#include<string.h>

void delSpecial(char str[]);
int main(){
    char str[10], ans='y'; 
    
    while(ans!='n'){
                     system("cls");
                     printf("Enter the String: ");
                     gets(str);
                     delSpecial(str);
                     printf("\n\nAlpha only:\n");
                     puts(str);
                     printf("Again?(enter 'n' to quit) : ");
                     scanf("%c",&ans);
    }
    getch();
    return 0;
}
void delSpecial(char str[]){
    int i, j, x;
    j=strlen(str); x=j+1;
    printf("Length of str = %d\nSize of str = %d\n\n",j,x);
        for(i=0;i<j;i++){
           if(isalpha(str[i])){}
           else{ printf("%s\n",strcpy(str+i,str+i+1)); i--; j--; }
           //printf("%d. ",i);puts(str);
        }
        
    printf("Press any key to Continue..");
    getch();
}
