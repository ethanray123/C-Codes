#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define EMPTY '~'
#define DELETED '!'
#define MAX 20
typedef char Dictionary[MAX];
typedef enum{TRUE,FALSE}boolean;

void initialize(Dictionary);
int hash(char);
void insert(Dictionary,char);
void display(Dictionary);
void deleteElem(Dictionary,char);
boolean member(Dictionary,char);

int main()
{
    Dictionary D;
    int x,choice;
    char elem;
    
    initialize(D);
    for(x=0;x<MAX && D[x]==EMPTY;x++){}
    if(x==MAX){
         printf("Dictionary initialized..\n");
         getch(); system("cls");
    }
    
    
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
                      scanf("%c",&elem);insert(D,elem);
                      break;
               case 3:printf("enter an elem to Delete: "); fflush(stdin);
                      scanf("%c",&elem);deleteElem(D,elem);
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

void initialize(Dictionary D)
{
     int i;
     for(i=0;i<MAX;i++){
          D[i]=EMPTY;
     }
}

int hash(char c)
{
     return (tolower(c)-97) % MAX;
}

void insert(Dictionary D, char c)
{
     int i;
     int hc=hash(c); 
     
     if(member(D,c)==FALSE){
          if(D[hc]==DELETED || D[hc]==EMPTY){
               D[hc]=c;
          }else{ 
               i=hc; 
               do{ 
                   i=(i+1) % MAX; //printf("%d\n",i);
               }while(i!=hc && D[i]!=EMPTY && D[i]!=DELETED); 
               D[i]=c;
          }
     }else{
          printf("Element Already in Dictionary..\n");
     }
}

void display(Dictionary D)
{
     int i;
     for(i=0;i<MAX;i++){
          if(i<10){ printf("0"); }              
          printf("%d|  %c  |\n",i,D[i]);
     }
}

void deleteElem(Dictionary D, char c)
{
     int i;
     int hc=hash(c);
     if(member(D,c)==TRUE){
          if(D[hc]==c){
               D[hc]=DELETED;        
          }else{
               i=hc; 
               do{ 
                   i=(i+1) % MAX; 
               }while(i!=hc && D[i]!=c && D[i]!=EMPTY);
               D[i]=DELETED;
          }
     }else{
           printf("Element is not in Dictionary\n");
     }
}

boolean member(Dictionary D, char c)
{
        boolean b;
        int i,hc=hash(c); printf("c = %d hc = %d\n",c,hc);
        if(D[hc]==c){
              b=TRUE;
        }else{
              i=hc; 
              do{ i=(i+1) % MAX; }while(i!=hc && D[i]!=c);
              if(D[i]==c){
                    b=TRUE;
              }else{
                    b=FALSE;
              }
        }
        return b;
}
