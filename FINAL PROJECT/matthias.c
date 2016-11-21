/*
CS 1201 FINAL PROJECT
Name1: 
Name2:
Name of project: 
Description of project:  (3-5 sentences)                        
*/
#include <stdio.h>
//other libraries

//function prototypes here
//Done by: Name1 or Name2 but should not be both
void function1(int parameters);
void function2(void);
//and so on..
//You and your partner should have equal number of functions assigned.

typedef enum{ true, false } boolean;

typedef struct da{
        int month;
        int day;
        int year;
}dateType;

typedef struct rec{
        char deliveryName[20];
        char deliveryType[20];
        char packageName[20];
        char from[20];
        char to[20];
        float weight;
        dateType dateOfOrder;
        dateType dateDelivered;
        int status;
}recordType;

//structures here.
void wait(void){
     printf("\n\n\tPress any key to return...");
     getch();
}

int main(void)
{
    int choice;
    do{
        printf("\t[GLORIOUS SHIPPING PROGRAM 9000000]\n");
        printf("MENU:\n");
        printf("---------------------\n");
        printf("1. Add a Delivery\n");
        printf("2. Cancel a Delivery\n");
        printf("3. Search Order for Delivery\n");
        printf("4. Check Status of Order\n");
        printf("5. Display Orders\n");
        printf("6. Update Order Status\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
           case 1: printf("\nAdding a delivery...: coming soon..."); wait(); break;
           case 2: printf("\nCanceling a delivery...: coming soon..."); wait(); break;
           case 3: printf("\nSearching order...: coming soon..."); wait(); break;
           case 4: printf("\nChecking order status...: coming soon..."); wait(); break;
           case 5: printf("\nDisplaying orders...: coming soon..."); wait(); break;
           case 6: printf("\nUpdating order status...: coming soon..."); wait(); break;
           case 7: printf("\nGoodbye..."); sleep(750); exit(0); break;
           default: printf("\nInvalid choice."); wait();
        }system("cls");
    }while(choice!=7);
    
    return 0;
}
