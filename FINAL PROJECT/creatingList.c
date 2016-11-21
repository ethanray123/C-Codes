#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

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
}recordType,*record;

typedef struct ml{
        record head;
        int recordCnt;
}masterlistType;

void createList(record *);
void readList();

int main()
{
    masterlistType masterl;
    /*record trav,trav2; 
    FILE *fp;
    masterl.recordCnt=0;
    createList(&masterl.head);
    masterl.recordCnt++;
    if(masterl.head!=NULL){
       system("cls");
       printf("Register Successful..\n");
    }else{
       exit(1);  
    }
    
    fp=fopen("List.bnf","wb");
    trav=masterl.head;
    fwrite(&masterl,sizeof(masterlistType),1,fp);
    fclose(fp);*/
    readList();
    getch();
    return 0;
}

void createList(record *head)
{
    record temp;
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
    temp->next = (*head);
    (*head) = temp;
}

void readList()
{
    FILE *fp; record trav; int x=0; masterlistType main;
    if((fp=fopen("List.bnf","rb"))==NULL){
          printf("Error"); exit(1);
    }   
    fread(&main,sizeof(recordType),1,fp);
    trav=main.head;
    printf("Name of client: %s\n",trav->deliveryName);
    printf("Type of Delivery: %s\n",trav->deliveryType);
    printf("Contents of Package: %s\n",trav->packageName);
    printf("From(place): %s\n",trav->from);
    printf("To(place): %s\n",trav->to);
    printf("Weight of Package: %.2f\n",trav->weight);
    printf("Status of Delivery: ");
    if(trav->status == 1){
                    printf("Currently In Progress\n\n");
    }else if(trav->status == 0){
                    printf("Delivery is Finished\n\n");
    }
}
