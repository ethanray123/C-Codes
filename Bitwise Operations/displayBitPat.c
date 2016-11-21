#include<stdio.h>
#include<stdlib.h>

void displaybitpat(char);
int main()
{
    char c;
    printf("Enter an Integer to Display in Bit Pattern: "); fflush(stdin);
    scanf("%d",&c);
    displaybitpat(c);
    getch();
    return 0;
}

void displaybitpat(char c)
{
    int i; 
    for(i=7;i >= 0;i--){
           printf("(%d >> %d) =%3d  ((%d>>%d & 1)) =",c,i,(c >> i),c,i);                  
           printf("%3u\n",((c >> i) & 1));
    }
    printf("\n");
    for(i=(sizeof(char)*8)-1;i >= 0;i--){            
           if(i==3){
               printf(" ");     
           }      
           printf("%d",((c >> i) & 1));
           //putchar('0' + ((c>>i)&1));
    }
    printf("\n%d",'0');
}
