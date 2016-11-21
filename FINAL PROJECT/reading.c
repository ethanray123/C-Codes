#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

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

void displayList(record);

int main()
{
    record head;
    displayList(head);
    getch();
    return 0;
}

void displayList(record head)
{
    FILE *fp; record trav; int x=0;
    if((fp=fopen("List.dat","rb"))==NULL){
          printf("Error"); getch(); exit(1);
    }
    trav=head;
    trav=(record)malloc(sizeof(recordType));    
    fread(trav,sizeof(recordType),1,fp);
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
    fclose(fp);
}
