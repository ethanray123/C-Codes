#include<stdio.h>
#include<conio.h>

int main(void){
    int grade=0, total=0, average, ctr=0;
    do{
       printf("Enter a Grade: ");
       scanf("%d",&grade);
       if(grade==999){
           printf("COMPUTING\n");    
       }
       else if(grade<0||grade>100){
           printf("Invalid Grade\n");
       }else{
             total+=grade;
             ctr++;
       }
    }while(grade!=999);
    
    average=total/ctr;
    printf("Average = %d", average);
    getch();
    return 0;
}

/*
do{
   system("cls");
   statement;
   getch();
}while(expression);
*/
