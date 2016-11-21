/*
CS 1201 FINAL PROJECT
Name1: Ethan Ray F. Mosqueda
Name2: Matthias Villarino
Name of project: (temporary)Mailin' N Sendin'
Description of project:  (3-5 sentences)  
       This Project is mainly focused on providing a delivery system for people so that they would have an easier way in Ordering for a Delivery. This will be a 
user-friendly program and will guide the user in what to do and what to input. Having the options to add and cancel deliveries are also two of the strengths of 
this Project. The developers do hope they can exceed the expectations of the users and give the delivery system they require.
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//structures
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
        struct rec *next;
        int recordCnt;
}recordType,*record;

typedef struct ml{
        record head;
        int recordCnt;
}masterlistType;
//function prototypes 

int loadData(record*); //Done
void displayOrders(masterlistType); //Done
void addDelivery();
void cancelDelivery();
void searchDelivery();
//Done by: Name 1
int checkStatus();
void updateOrderStatus();
void wait();
//Done by: Name 2
                         /*Done by: Name1 or Name2 but should not be both and so on..
                           You and your partner should have equal number of functions assigned.*/

   

int main(void)
{
    masterlistType mainl; 
    mainl.recordCnt=0; mainl.head=NULL;
    mainl.recordCnt=loadData(&mainl.head);
    system("cls");
    int choice;
    do{
        printf("\t[Mail N' Send]\n");
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
           case 1: printf("\nAdding a delivery: \n"); 
                   addDelivery(&mainl);
                   wait(); break;
           case 2: printf("\nCanceling a delivery...: coming soon..."); wait(); break;
           case 3: printf("\nSearching order...: coming soon..."); wait(); break;
           case 4: printf("\nChecking order status...: coming soon..."); wait(); break;
           case 5: printf("\nDisplaying orders: \n"); 
                   displayOrders(mainl);
                   wait(); break;
           case 6: printf("\nUpdating order status...: coming soon..."); wait(); break;
           case 7: printf("\nGoodbye..."); sleep(750); exit(0); break;
           default: printf("\nInvalid choice."); wait();
        }system("cls");
    }while(choice!=7);
    return 0;
}

void wait(void){
     printf("\n\n\tPress any key to return...");
     getch();
}

void addDelivery(masterlistType main)
{
    record temp, trav; FILE *fp;
    temp = (record)malloc(sizeof(recordType)); fflush(stdin);
    printf("Name: ");
    gets(temp->deliveryName); fflush(stdin); 
    printf("Delivery Type: ");
    gets(temp->deliveryType); fflush(stdin); 
    printf("Contents of Package: ");
    gets(temp->packageName); fflush(stdin); 
    printf("Source of Delivery: ");
    gets(temp->from); fflush(stdin); 
    printf("Destination: ");
    gets(temp->to); fflush(stdin);
    printf("Weight(kg): ");
    scanf("%f",&temp->weight); fflush(stdin);
    printf("Status of Delivery(1 for In progress & 0 for Finished): ");
    scanf("%d",&temp->status);
    temp->next = main.head;
    main.head = temp;
    main.recordCnt++;
    
    trav=main.head;
    fp=fopen("List.bnf","ab");
    trav=main.head;
    fwrite(trav,sizeof(recordType),1,fp);
    fclose(fp);
}

void displayOrders(masterlistType main)
{
    record trav; int x=1;
    trav=main.head;
    while(x!=main.recordCnt){
             printf("Order No. %d",x++);
             printf("Name of client: %s\n",trav->deliveryName);
             printf("Type of Delivery: %s\n",trav->deliveryType);
             printf("Contents of Package: %s\n",trav->packageName);
             printf("From(place): %s\n",trav->from);
             printf("To(place): %s\n",trav->to);
             printf("Weight of Package:  %.2f\n",trav->weight);
             printf("Status of Delivery: ");
             if(trav->status == 1){
                    printf("Currently In Progress\n\n");
             }else if(trav->status == 0){
                    printf("Delivery is Finished\n\n");
             }
             trav=trav->next;
    }
} 

int loadData(record *head)
{
    FILE *fp; record trav; int cnt=0, x=0;
    if((fp = fopen("List.bnf","rb"))==NULL){
          printf("error 404\n"); getch();
          return 0;
    }
    
    (*head)=(record)malloc(sizeof(recordType));
    trav=(*head);
    while((fread(trav,sizeof(recordType),1,fp)) != 0){
        cnt++;
        if(cnt>0)
          trav=(record)malloc(sizeof(recordType));  
    }
    printf("Data Successfully Loaded...\n");
    
    /*
    printf("Name of client: %s\n",trav->deliveryName);
    printf("Type of Delivery: %s\n",trav->deliveryType);
    printf("Contents of Package: %s\n",trav->packageName);
    printf("From(place): %s\n",trav->from);
    printf("To(place): %s\n",trav->to);
    printf("Weight of Package: %.2f\n",trav->weight);
    printf("Status of Delivery: ");
    if(trav->status == 1){
                    printf("Currently In Progress");
    }else if(trav->status == 0){
                    printf("Delivery is Finished");
    }
    getch();
    */
    sleep(750);
    system("cls");  
    fclose(fp);
    return cnt;
}
