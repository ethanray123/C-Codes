#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//structures
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
}recordType,*record;

typedef struct ml{
        record head;
        int recordCnt;
}masterlistType;

void wait();
void displayOrders(record);    

int main(void)
{
    masterlistType masterl;
    record trav,trav2; 
    FILE *fp; int i=0,j;
    masterl.head=NULL;
    if((fp=fopen("List.bnf","rb"))==NULL){ 
          printf("Error"); exit(1);
    }
    trav = masterl.head;
    do{
          trav=(record)malloc(sizeof(recordType));
          fread(trav,sizeof(recordType),1,fp);
          trav=trav->next;
          i++;
    }while(i <= masterl.recordCnt);
    displayOrders(masterl.head);
    getch();
    fclose(fp);
    return 0;
}

void wait(void){
     printf("\n\n\tPress any key to return...");
     getch();
}

void displayOrders(record head)
{
     record trav;
     trav = head;
     if(trav==NULL){
             printf("Something went Wrong");
     }
     while(trav!=NULL){
             printf("Name of client: %s\n",trav->deliveryName);
             printf("Type of Delivery: %s\n",trav->deliveryType);
             printf("Contents of Package: %s\n",trav->packageName);
             printf("From(place): %s\n",trav->from);
             printf("To(place): %s\n",trav->to);
             printf("Weight of Package:  %.2f\n",trav->weight);
             printf("Status of Delivery: ");
             if(trav->status == 1){
                    printf("Currently In Progress");
             }else if(trav->status == 0){
                    printf("Delivery is Finished");
             }
             trav=trav->next;
     }
}
