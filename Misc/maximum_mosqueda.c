#include<stdio.h>
#include<conio.h>

int main(void)
{
    int n1, n2, n3;
    printf("Input Three Numbers: \n");
    scanf("%d%d%d", &n1,&n2,&n3);
    if(n1>n2){
       if(n1>n3){
           printf("%d is the Biggest Number", n1);      
       }else{
           printf("%d is the Biggest Number", n3);
       }
    }else if(n2<n3){
       printf("%d is the Biggest Number", n3);
    }else{
       printf("%d is the Biggest Number", n2);   
    }
    
    getch();
    return 0;
}
