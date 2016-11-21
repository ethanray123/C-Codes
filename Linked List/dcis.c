#include<stdio.h>
#include<conio.h>
#include<string.h>
//structs and what not
typedef struct stud{
        int idNum;
        char FN[24],LN[24],MI;
        char course[10];
        int yearLevel;
}studType;

typedef struct nodeT{
        studType student;
        struct nodeT *next;
}nodeType;

typedef struct listType{
        nodeType *head;
        int studentCtr;
}LIST;

//prototypes
void displayLinkedList(LIST L);
void populateDCIS(LIST *L); //sorted via idNum
LIST sortCourse(LIST L); 
void searchID(LIST L); //search ID and display info
void updateYearLevel(LIST *L);

//main func
int main()
{
    int choice;
    LIST masterl;
    masterl.head = NULL;
    do{
        system("cls");             
        printf("Welcome to DCIS Intel\n\n");
        printf("1 - Display Linked List\n");
        printf("2 - Populate DCIS\n");
        printf("3 - Sort Course\n");
        printf("4 - Search an ID\n");
        printf("5 - Update Year Level\n");
        printf("0 - Exit Program\n");
        printf("Enter a Function to be executed: "); fflush(stdin);
        scanf("%d",&choice);
        switch(choice){
              case 0:printf("Exiting the program...");break; 
              case 1:displayLinkedList(masterl);break;
              case 2:populateDCIS(&masterl);break;
              case 3:masterl = sortCourse(masterl);
                     break;
              case 4:searchID(masterl);break;
              case 5:updateYearLevel(&masterl);break;
              default:printf("Invalid Choice"); getch();
        }
    }while(choice!=0);
    getch();
    return 0;
}

void displayLinkedList(LIST L)
{
     nodeType *trav; int i=1;
     if(L.head!=NULL){
           system("cls");
           printf("\t\t\t\t~~~~Display~~~~\n\n");
           printf("Student ID\tName\t\t\tCourse\t\tYear Level\n\n");
           trav=L.head;
           while(trav!=NULL){
                  printf("%d. %d\t",i++,trav->student.idNum);
                  printf("%s %c. %s\t\t",trav->student.FN,trav->student.MI,trav->student.LN); 
                  printf("%s\t\t%d\n",trav->student.course,trav->student.yearLevel);
                  trav=trav->next;
           }
     }else{
           printf("NULLED or Haven't added\n");
     }
     getch();
     free(trav);
}

void populateDCIS(LIST *L) //sorted via idNum
{
     nodeType *temp, *trav;
     (*L).studentCtr = 0;
     while((*L).studentCtr!=5){
          system("cls");
          temp = (nodeType*)malloc(sizeof(nodeType));
          printf("%d.\nID No(8 digits): ",++(*L).studentCtr); fflush(stdin);
          scanf("%d",&temp->student.idNum);
          printf("First Name: "); fflush(stdin);
          gets(temp->student.FN);
          printf("Middle Initial: "); fflush(stdin);
          scanf("%c",&temp->student.MI);
          printf("Last Name: "); fflush(stdin);
          gets(temp->student.LN);
          printf("Course: ");
          gets(temp->student.course);
          printf("Year Level: ");
          scanf("%d",&temp->student.yearLevel);
          if((*L).head == NULL){
                //printf("if entered");
                (*L).head = temp;
                (*L).head->next = NULL;
                temp = temp->next;   
          }else{
                //printf("else entered");
                trav = (*L).head;
                if(temp->student.idNum < trav->student.idNum){
                         temp->next = (*L).head;
                         (*L).head = temp;
                }else{
                      while(trav->next!=NULL && temp->student.idNum > trav->student.idNum && temp->student.idNum > trav->next->student.idNum){
                               trav=trav->next;
                      }
                      temp->next = trav->next;
                      trav->next = temp;
                }
          }
     }
}

LIST sortCourse(LIST L)
{    
     LIST New; nodeType *temp, *trav1,*trav2,*trav3;
     New.studentCtr = L.studentCtr;
     New.head = NULL;
     New.head = (nodeType*)malloc(sizeof(nodeType));
     temp = New.head;
     trav1=trav2=trav3=L.head;
     while(trav1!=NULL){
           if(trav1->student.course == "BSCS"){
                  temp = trav1;
                  temp->next = (nodeType*)malloc(sizeof(nodeType));
                  temp=temp->next;
                  printf("Went through CS");
           }
           trav1 = trav1->next;
     }
     
     while(trav2!=NULL){
           if(trav2->student.course == "BSIT"){
                  temp = trav2;
                  New.head = temp;
                  printf("Went through IT");
           }
           trav2 = trav2->next;
     }
     
     while(trav3!=NULL){
           if(trav3->student.course == "BSICT"){
                  temp = trav3;
                  New.head = temp;
                  printf("Went through ICT");
           }
           trav3 = trav3->next;
     }
     return (New);
     getch();
}
void searchID(LIST L) //search ID and display info
{
     nodeType *trav; int id=0;
     trav = L.head;
     system("cls");
     printf("ID Search: \n\nEnter a ID No: "); fflush(stdin);
     scanf("%d",&id);
     while(trav->student.idNum != id && trav->next != NULL){
            trav=trav->next;
     }
     if(trav->student.idNum == id){
           printf("ID Found!!!\n");
           printf("ID No: %d\n",trav->student.idNum);
           printf("Name: %s %c. %s\n",trav->student.FN,trav->student.MI,trav->student.LN); 
           printf("Course: %s\nYear Level: %d\n",trav->student.course,trav->student.yearLevel);
     }else{
           printf("ID Not Found...");
     }
     getch();
}
void updateYearLevel(LIST *L)
{
     nodeType *trav;
     trav = (*L).head;
     if(trav == NULL){
           printf("List is not Created or List Error");  
     }else{
           while(trav != NULL){
           if(trav->student.yearLevel == 2)
                 trav->student.yearLevel++;
           trav=trav->next;
           }
           printf("Year has been Updated.");
     }
     getch();
}
