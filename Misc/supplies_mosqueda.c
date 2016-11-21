#include <stdio.h>
#include <conio.h>

int main()
{
    int ntbk, pen, padp;
    float totalbill;
    printf("^^^SCHOOL SUPPLIES^^^\n");
    printf("_____________________\n");
    printf("Enter no. of notebooks: ");
    scanf("%d",&ntbk);
    printf("Enter no. of pens: ");
    scanf("%d",&pen);
    printf("Enter no. of pads of paper: ");
    scanf("%d",&padp);
    
    totalbill=(ntbk*12.00)+(pen*7.50)+(padp*9.75);
    
    if(totalbill>=100 && totalbill<500){
          totalbill=totalbill-(totalbill*0.02);        
    }else if(totalbill>=500){
          totalbill=totalbill-(totalbill*0.10);
    }
    printf("Your Total Bill is: %.2f\n",totalbill);
    printf("Thank you for your patronage! \nHave a nice Day!");
    
    getch();
    return 0;
}
