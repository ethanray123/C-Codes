#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define EMPTY '~'
#define DELETED '!'
#define MAX 20

typedef struct{
      char elem;
      int next;  
}cellType[MAX];

typedef struct{
      cellType cells;
      int avail;
}Dictionary;

typedef enum{TRUE,FALSE}boolean;

int hash(char);
void initialize(Dictionary *);
void display(Dictionary);
boolean member(Dictionary,char);
void insert(Dictionary *, char);
void deleteElem(Dictionary *, char);

int main()
{
    Dictionary D;
    int x,choice;
    char elem;
    
    initialize(&D);
    for(x=0;x<(MAX/2) && D.cells[x].elem==EMPTY;x++){}
    if(x==MAX/2){
         printf("Dictionary initialized..");
    }else{
         printf("Error.."); 
    }
    getch(); system("cls");
    
    do{
         printf("1 - display();\n");
         printf("2 - insert();\n");
         printf("3 - delete();\n");
         printf("4 - member();\n");
         printf("0 - exit\n");
         printf("Choose a number corresponding to a func.: ");
         fflush(stdin);
         scanf("%d",&choice);
         switch(choice){
               case 0:printf("Exitting..\n");break;
               case 1:display(D);break;
               case 2:printf("enter an elem to Add: "); fflush(stdin);
                      scanf("%c",&elem);insert(&D,elem);
                      break;
               case 3:printf("enter an elem to Delete: "); fflush(stdin);
                      scanf("%c",&elem);deleteElem(&D,elem);
                      break;
               case 4:printf("enter an elem to Search: "); fflush(stdin);
                      scanf("%c",&elem);
                      if(member(D,elem)==TRUE){
                           printf("Element in Dictionary");
                      }else{
                           printf("Element not in Dictionary"); 
                      }
                      break;
               default:printf("Invalid Choice");
         }
         getch(); 
         system("cls");
    }while(choice!=0);

    return 0;
}

int hash(char c)
{
     return (tolower(c)-97) % (MAX/2);
}

void initialize(Dictionary *D)
{
     int i;
     for(i=0;i<MAX-1;i++){
          if(i<10){              
             (*D).cells[i].elem=EMPTY;
             (*D).cells[i].next=-1;
          }else{
             (*D).cells[i].next=i+1;
          }
     }
     (*D).cells[i].next=-1;
     (*D).avail=MAX/2;
}

void display(Dictionary D)
{
     int i;
     for(i=0;i<MAX;i++){
          if(i<10){ printf("0"); }              
          printf("%d|  %c  |",i,D.cells[i].elem);
          if(D.cells[i].next<10 && D.cells[i].next>0){ printf("  0%d  |\n",D.cells[i].next); }
          else{printf("  %d  |\n",D.cells[i].next);}
     }
}

boolean member(Dictionary D, char c)
{
     int temp=hash(c); printf("c = %d hc = %d\n",c,temp);
     if(D.cells[temp].elem!=EMPTY){
           while(temp!=-1 && D.cells[temp].elem!=c){ 
                temp = D.cells[temp].next; 
           }
     }
     return (temp=-1 && D.cells[temp].elem==c)?TRUE:FALSE;
}

void insert(Dictionary *D, char c)
{
     int temp;
     int hc=hash(c); 
     
     if(member((*D),c)==FALSE){               
           if((*D).cells[hc].elem!=EMPTY){
                 temp=(*D).avail++;
                 (*D).cells[temp].elem=c;
                 (*D).cells[temp].next=(*D).cells[hc].next;
                 (*D).cells[hc].next=temp;
           }else{
                 (*D).cells[hc].elem=c;
           }      
     }else{
           printf("Element Already in Dictionary..\n");
     }
}

void deleteElem(Dictionary *D, char c)
{
     int *trav,temp;
     int hc=hash(c);
     
     if(member((*D),c)==TRUE){
           if((*D).cells[hc].elem==c){
                 (*D).cells[hc].elem=DELETED;                     
           }else{
                 trav=&(*D).cells[hc].next;
                 while((*trav)!=-1 && (*D).cells[(*trav)].elem!=c){
                       trav=&(*D).cells[(*trav)].next;
                 }
                 temp=(*trav);
                 (*trav)=(*D).cells[(*trav)].next;
                 (*D).cells[MAX-1].next=(*trav);
                 (*D).cells[temp].next=(*D).avail;
                 (*D).avail=temp;
           }
     }else{
           printf("Element is not in Dictionary..\n");
     }
}
