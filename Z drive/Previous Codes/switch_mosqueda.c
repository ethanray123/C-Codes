#include<stdio.h>
#include<conio.h>

int main()
{
    int num1;
    printf("Enter a Value: ");
    scanf("%d",&num1);
    
    switch(num1){
                 case 10:  printf("%d", num1*num1);break;
                 case  9:  printf("Enter another Value: ");
                           scanf("%d", &num1);
                           switch(num1){
                                        case 10: printf("%d", num1*num1);break;
                                        case  2:
                                        case  3: printf("%d", num1*99);break;
                                       }
                           break;
                 case  2:
                 case  3: printf("%d", num1*99);break;
                 }
    getch();
    return 0;
}
