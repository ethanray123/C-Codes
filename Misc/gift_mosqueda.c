#include<stdio.h>
#include<conio.h>

int main(void){
    int age, gift;
    for(gift=10, age=12; gift<=1000; age++){
                 gift = gift*2;
    }
    printf("The girl will be %d years old and received %d since she was 12", age, gift);
    getch();
    return 0;
}
