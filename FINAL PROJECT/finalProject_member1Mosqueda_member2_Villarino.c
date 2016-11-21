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
#include <unistd.h>

//structures
typedef struct da{
        int month;
        int day;
        int year;
}dateType;

typedef struct rec{
        char deliveryName[30];
        char deliveryType[20];
        char packageName[20];
        char from[30];
        char to[30];
        float weight;
        dateType dateOfOrder;
        dateType dateDelivered;
        int status;
}recordType;

typedef struct ml{
        recordType node;
        struct ml *next;
}masterlistType,*masterlist;

//function prototypes 
void loadData(masterlistType **); 
void displayOrders(masterlistType *); 
void addDelivery(masterlistType **);
void cancelDelivery(masterlistType **);
//Done by: Name 1
void checkStatus(masterlistType *);
void updateOrderStatus(masterlistType **);
void searchDelivery(masterlistType *); 
void wait(); 
//Done by: Name 2
                         /*Done by: Name1 or Name2 but should not be both and so on..
                           You and your partner should have equal number of functions assigned.*/

 
void initialize(masterlistType **);

int main(void)
{
    masterlist mainl; 
    initialize(&mainl);
    loadData(&mainl);
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
        system("cls");
        switch(choice){
           case 1: printf("\nAdding a delivery: \n"); 
                   addDelivery(&mainl);
                   wait(); break;
           case 2: printf("\nCanceling a delivery: \n"); 
                   cancelDelivery(&mainl);
                   wait(); break;
           case 3: printf("\nSearching order: \n"); 
                   searchDelivery(mainl);
                   wait(); break;
           case 4: printf("\nChecking order status: \n"); 
                   checkStatus(mainl);
                   wait(); break;
           case 5: printf("\nDisplaying orders: \n\n"); 
                   displayOrders(mainl);
                   wait(); break;
           case 6: printf("\nUpdating order status: \n"); 
                   updateOrderStatus(&mainl);
                   wait(); break;
           case 7: printf("\nGoodbye..."); sleep(750); exit(0); break;
           default: printf("\nInvalid choice."); wait();
        }system("cls");
    }while(choice!=7);
    getch();
    return 0;
}

void wait(void){
     printf("\n\n\tPress any key to return...");
     getch();
}

void addDelivery(masterlistType **main)
{
    int recordCnt=0;
    masterlistType *temp; FILE *fp,*fp2;
    temp = (masterlistType*)malloc(sizeof(masterlistType)); fflush(stdin);
    printf("Please Register the following...\n\n");
    printf("Your Name: ");
    gets(temp->node.deliveryName); fflush(stdin); 
    printf("Delivery Type: ");
    gets(temp->node.deliveryType); fflush(stdin); 
    printf("Contents of Package: ");
    gets(temp->node.packageName); fflush(stdin); 
    printf("Source of Delivery: ");
    gets(temp->node.from); fflush(stdin); 
    printf("Destination: ");
    gets(temp->node.to); fflush(stdin);
    printf("Weight(kg): ");
    scanf("%f",&temp->node.weight); fflush(stdin);
    printf("Status of Delivery(1 for In progress & 0 for Finished): ");
    scanf("%d",&temp->node.status);
    temp->next = (*main);
    (*main) = temp;
     
    fp2=fopen("numRecs.dat","rb");
    fscanf(fp2,"%d",&recordCnt); 
    recordCnt++;
    fclose(fp2);
    if(recordCnt==1){
       fp=fopen("List.dat","wb");
    }else{
       fp=fopen("List.dat","ab");
    }
    fp2=fopen("numRecs.dat","wb");
    fprintf(fp2,"%d ",recordCnt);
    fclose(fp2);
    
    masterlistType *trav;
    trav=(*main);
    masterlistType *hNext = NULL;
    hNext=trav->next;
    trav->next=NULL;
    //fseek(fp,0,SEEK_END);
	fwrite(trav,sizeof(masterlistType),1,fp);
	trav->next=hNext;
	hNext=NULL;
	trav=trav->next;//WRITING END
	trav=NULL;
    
    
    printf("\nWriting...");
    fclose(fp);
    fclose(fp2);
}

void displayOrders(masterlistType *main)
{
    /*FILE *fp;
	if((fp=fopen("List.dat","r"))==NULL){
		puts("Error: cannot open file");
		exit(1);
	}else{
          
    int i, listSize;
    rewind(fp)*/
    masterlistType *trav; int x=1;
    trav=main;
    if(trav==NULL){
          puts("No Records..");
    }
    while(trav!=NULL){
             printf("Order No. %d\n",x++);
             printf("Name of client: %s\n",trav->node.deliveryName);
             printf("Type of Delivery: %s\n",trav->node.deliveryType);
             printf("Contents of Package: %s\n",trav->node.packageName);
             printf("From(place): %s\n",trav->node.from);
             printf("To(place): %s\n",trav->node.to);
             printf("Weight of Package:  %.2f\n",trav->node.weight);
             printf("Status of Delivery: ");
             if(trav->node.status == 1){
                    printf("Currently In Progress\n\n");
             }else if(trav->node.status == 0){
                    printf("Delivery is Finished\n\n");
             }
             trav=trav->next;
    }
} 
void initialize(masterlistType **main)
{
     (*main)=NULL;
}

void loadData(masterlistType **main)
{
    FILE *fp,*fp2; int recordCnt=0,i=0;
    masterlistType *trav;
    if((fp = fopen("List.dat","rb"))==NULL){
          printf("Data Unrecovered\n"); 
    }else{
       trav=(*main);
       if((fp2=fopen("numRecs.dat","rb"))==NULL){
               exit(1);
       }   
       rewind(fp);
       rewind(fp2);
       fscanf(fp2,"%d",&recordCnt);
       printf("RecordCnt: %d \n",recordCnt);
       if(recordCnt==0){
                printf("No Data in File");        
       }else{
       (*main)=(masterlistType*)malloc(sizeof(masterlistType));
       fread((*main),sizeof(masterlistType),1,fp);
       puts("Reading...");
       trav=(*main);
       for(i=1;i<recordCnt;i++){
                trav->next=(masterlistType*)malloc(sizeof(masterlistType));
                fread(trav->next,sizeof(masterlistType),1,fp);
                puts("Reading...");
                trav=trav->next;
       }
       trav->next=NULL;
       getch();
       printf("Data Successfully Loaded...\n");
       }
    }
    sleep(750);
    system("cls");  
    fclose(fp);
}

void cancelDelivery(masterlistType **main)
{
     masterlistType *trav,*temp; char clientName[30]; FILE *fp; int recordCnt=0;
     printf("Enter a Name of a Client for his/her Order to be Cancelled: "); fflush(stdin);
     gets(clientName);
     trav=(*main);
     if(strcmpi(trav->node.deliveryName,clientName) == 0){
          (*main)=trav->next;
          trav->next=NULL;
          free(trav);         
          fp=fopen("numRecs.dat","rb");
          fscanf(fp,"%d",&recordCnt); 
          recordCnt--;
          printf("Check phase 1");
     }else{
          for(temp=(*main); trav->next!=NULL; trav=trav->next){
              if(strcmpi(trav->next->node.deliveryName, clientName) == 0){
                     temp=trav->next;
                     trav->next=trav->next->next;
                     temp->next=NULL;
                     free(temp);
                     fp=fopen("numRecs.dat","rb");
                     fscanf(fp,"%d",&recordCnt); 
                     recordCnt--;
                     break;
              }
              printf("Check");
          }
          if(trav->next==NULL && strcmpi(trav->next->node.deliveryName, clientName) == 0){
            printf("Order not Found.."); getch();
          }
     }
     
     fp=fopen("numRecs.dat","wb");
     fprintf(fp,"%d ",recordCnt);
     fclose(fp);
     
     fp=fopen("List.dat","wb");
     masterlistType *write=(*main);
     while(write!=NULL){
           fseek(fp,0,SEEK_END);
           fwrite(write,sizeof(masterlistType),1,fp);
           write=write->next;
     }fclose(fp);
}

void searchDelivery(masterlistType *main){
     FILE *fp; char search[30]; int x=0;
     masterlistType *trav;
     trav=main;
     if((fp=fopen("List.dat","rb"))==NULL){
        puts("Error: cannot open"); getch();
        exit(1);
     }else{
        printf("Enter a client's name: "); fflush(stdin);
        gets(search);
        while(trav!=NULL){
           if((strcmpi(search,trav->node.deliveryName))==0){
              x+=1;
              printf("\"%s\" Found!\n",search);
              printf("Order No. %d\n",x);
              printf("Name of client: %s\n",trav->node.deliveryName);
              printf("Type of Delivery: %s\n",trav->node.deliveryType);
              printf("Contents of Package: %s\n",trav->node.packageName);
              printf("From(place): %s\n",trav->node.from);
              printf("To(place): %s\n",trav->node.to);
              printf("Weight of Package:  %.2f\n",trav->node.weight);
              printf("Status of Delivery: ");
              if(trav->node.status == 1){
                     printf("Currently In Progress\n\n");
              }else if(trav->node.status == 0){
                     printf("Delivery is Finished\n\n");
              }
              trav=trav->next;
           }else{
              x+=1;
              trav=trav->next;
           }
        }
        if((strcmpi(search,trav->node.deliveryName))!=0){
               printf("Record Not Found...");                   
        }
     }
}

void checkStatus(masterlistType *main){
     FILE *fp; char search[30]; int x=0, r=0;
     masterlistType *trav;
     trav=main;
     if((fp=fopen("List.dat","rb"))==NULL){
        puts("Error: cannot open"); getch();
        exit(1);
     }else{
        printf("Enter a client's name to check: "); fflush(stdin);
        gets(search);
        while(trav!=NULL){
           if((strcmpi(search,trav->node.deliveryName))==0){
              x+=1; r=1;
              printf("Delivery Status: ");
              if(trav->node.status == 1){
                     printf("Currently In Progress\n\n");
              }else if(trav->node.status == 0){
                     printf("Delivery is Finished\n\n");
              }
              trav=trav->next;
           }else{
              x+=1;
              trav=trav->next;
           }
        }if(r==0){
            printf("No results...\n");
         }
     }fclose(fp);
}

void updateOrderStatus(masterlistType **main){
     FILE *fp, *fp2; masterlistType *trav; int recordCnt, i;
     trav=(*main);
     if((fp=fopen("List.dat","r+b"))==NULL){
        puts("Error: cannot open"); getch();
        exit(1);
     }else{
        if((fp2=fopen("numRecs.dat","rb"))==NULL){
           puts("Error: cannot open"); getch();
           exit(1);
        }else{
           fscanf(fp2,"%d",&recordCnt);
           for(i=0; i<recordCnt; i++){
              if(trav->node.status == 1){
                 trav->node.status = 0;
                 trav=trav->next;
              }
           }
        }
     }fclose(fp); fclose(fp2);
}
