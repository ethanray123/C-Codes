#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
        char LN[16];
        char FN[24];
        char MI;
}nameType;

typedef struct{
        nameType name;
        unsigned long ID;
        char course[8];
        int year;
}studType;

typedef struct{
        studType data;
}nodeType,studArray[MAX];

typedef struct{
      studArray elem;  
      int last;  
}List;

void initList(List*);
void deleteAllOccur(List*,char*);
void changeLastName(List*,char*,char*);
int main()
{
    List L;
    int n;
    char nameLast[16],newLN[16];
    
    initList(&L);
    
    system("cls");
    for(n=0;n<=L.last;n++){
        printf("Name: %s, %c. %s\n",L.elem[n].data.name.LN,L.elem[n].data.name.MI,L.elem[n].data.name.FN);
        printf("ID: %d\n",L.elem[n].data.ID);
        printf("Course: %s\n",L.elem[n].data.course);
        printf("Year: %d\n\n",L.elem[n].data.year);
    }
    printf("Which Last Names need to be changed?: "); fflush(stdin);
    gets(nameLast);
    printf("What Name would you like?: "); fflush(stdin);
    gets(newLN);
    system("cls");
    //deleteAllOccur(&L,course);
    changeLastName(&L,nameLast,newLN);
    
    for(n=0;n<=L.last;n++){
        printf("Name: %s, %c. %s\n",L.elem[n].data.name.LN,L.elem[n].data.name.MI,L.elem[n].data.name.FN);
        printf("ID: %d\n",L.elem[n].data.ID);
        printf("Course: %s\n",L.elem[n].data.course);
        printf("Year: %d\n\n",L.elem[n].data.year);
    }
    getch();
    return 0;
}

void initList(List *L)
{
     int i;
     for(i=0;i<5;i++){
                      printf("Last Name: "); fflush(stdin);
                      gets(L->elem[i].data.name.LN);
                      printf("Middle Initial: "); fflush(stdin);
                      scanf("%c",&L->elem[i].data.name.MI);
                      printf("First Name: "); fflush(stdin);
                      gets(L->elem[i].data.name.FN);
                      printf("ID: "); fflush(stdin);
                      scanf("%d",&L->elem[i].data.ID);
                      printf("Course: "); fflush(stdin);
                      gets(L->elem[i].data.course);
                      printf("Year: "); fflush(stdin);
                      scanf("%d",&L->elem[i].data.year);
                      printf("\n");
     }
     L->last=i-1;
}
 
void deleteAllOccur(List *L,char *delCourse)
{
     int x;
     for(x=0;x <= L->last;){
           if(strcmp(delCourse,L->elem[x].data.course)==0){
                  if(x < L->last){
                        memmove(&L->elem[x].data,&L->elem[x+1].data,sizeof(studType)*(L->last-x));
                  }
                  L->last--;
           }else{
                 x++;
           }
     }
}

void changeLastName(List *L,char *oldLName,char *newLName)
{
     int x;
     for(x=0;x <= L->last;x++){
            if(strcmp(oldLName,L->elem[x].data.name.LN)==0){
                  strcpy(L->elem[x].data.name.LN,newLName);
            }
     }
}
