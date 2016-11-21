#include<stdio.h>
#include<conio.h>

int getNum();
char isEvenOrOdd(int x);

int main(void){
    int x; char c;
    x = getNum();
    c = isEvenOrOdd(x);
        if(c=='E'){
             printf("%d is Even",x);      
        }else{
             printf("%d is Odd",x); 
        }
    getch();
    return 0;
}
int getNum(){
    int num;
    printf("Enter a Number: ");
    scanf("%d",&num);
    return num;
}
char isEvenOrOdd(int a){
    char letter;
    if(a % 2 == 0){
        letter='E'; 
    }else{
        letter='O';  
    }
    return letter; 
}
