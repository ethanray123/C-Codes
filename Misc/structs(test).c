#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct Name{
        char FN[21];
        char LN[21];
        char MI;
}nameType;

typedef struct Student{
        nameType name;
        int studId;
        char course[15];
        int year;
        float grade;
        struct Student *next;
}studentType,*stud;

typedef struct List{
        stud head;
        int studCnt;
}listType;

void display(stud s);
listType newEnrollees(listType l);

int main()
{
    char choice[5];
    listType list;
    list.head=(stud)malloc(sizeof(studentType));
    strcpy(list.head->name.FN,"Marceline");
    list.head->name.MI = 'F';
    strcpy(list.head->name.LN,"Vampire");
    list.head->studId=9000;
    strcpy(list.head->course,"Arts and Magic");
    list.head->year=4;
    list.head->grade=2.9;
    list.head->next = NULL;
    list.studCnt=1;
    display(list.head); 
    
    printf("there are currently %d student/s\n\n",list.studCnt);
    printf("would you like to enroll more students for the new school year?? <yes or no>: "); fflush(stdin);
    gets(choice);
    if(strcmp(choice,"yes")==0 || strncmp(choice,"y",1)==0){
          list = newEnrollees(list);  
          printf("Exiting...\npress any key to continue");         
    }else{
          printf("Exiting...\npress any key to continue"); 
    }
    getch();
    return 0;
}

void display(stud s)
{
     stud a=s;
     printf("\t\t\t      ||||||Enrollees||||||\n");
     printf("________________________________________________________________________________\n");
     for(a=s;a!=NULL;a=a->next){
               printf("Student's name: %s %c. %s\n",a->name.FN,a->name.MI,a->name.LN);
               printf("Student's ID: %d\n",a->studId);
               printf("Student's course: %-20s\n",a->course);
               printf("Year: %d\n",a->year);
               printf("Average grade: %.1f\n\n",a->grade);
     }
}

listType newEnrollees(listType l)
{
      stud b=l.head;
      int choice;
      do{
           b->next=(stud)malloc(sizeof(studentType));
           b=b->next;
           printf("First Name: "); fflush(stdin);
           gets(b->name.FN);
           printf("Middle Initial: "); fflush(stdin);
           scanf("%c",&b->name.MI); 
           printf("Last Name: "); fflush(stdin);
           gets(b->name.LN); 
           printf("Student ID: "); fflush(stdin);
           scanf("%d",&b->studId);
           printf("Course to be taken: "); fflush(stdin);
           gets(b->course); 
           printf("Year Level: "); fflush(stdin);
           scanf("%d",&b->year);
           printf("Last Year's Grade Average: "); fflush(stdin);
           scanf("%f",&b->grade);
           b->next=NULL;
           l.studCnt++;
           system("cls");
           display(l.head);
           
           printf("there are currently %d student/s\n\n",l.studCnt);
           printf("would you like to enroll another student? (1 or 0):  "); fflush(stdin);
           scanf("%d",&choice);
      }while(choice!=0);
      return l;
}
