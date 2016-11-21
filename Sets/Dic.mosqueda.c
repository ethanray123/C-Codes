#include<stdio.h>
#include<conio.h>
#define SIZE 10

typedef struct node {
   int elem;
   struct node *next;
}ctype, *List;

typedef List Dictionary[SIZE]; 
typedef enum {TRUE, FALSE} booltype;

int hash(int);
void initDictionary(Dictionary);
void insert(Dictionary,int);
booltype isMember(Dictionary,int);
void display(Dictionary);
void deleteElem(Dictionary,int);

int main(){
    Dictionary D;
    initDictionary(D);
    insert(D,0);
    insert(D,13);
    insert(D,20);
    insert(D,28);
    insert(D,30);
    insert(D,33);
    insert(D,45);
    insert(D,48);
    insert(D,108); 
    display(D);
    system("cls");
    insert(D,72);
    insert(D,23);
    insert(D,45); 
    display(D);    
    system("cls");
    deleteElem(D,108);
    deleteElem(D,31);
    display(D);
    return 0;
}

int hash(int x)
{
    return x % 10;
}

void initDictionary(Dictionary D)
{
     int i;
     for(i=0;i<SIZE;i++){
           D[i]=NULL;
     }
     printf("Initialized\n");
     getch();
}

void insert(Dictionary D, int x)
{
     int hx=hash(x);
     if(isMember(D,x)==FALSE){
           List newElem=(List)malloc(sizeof(ctype));
           newElem->elem=x;
           
           List *temp=&D[hx];             
             
           while((*temp)!=NULL && (*temp)->elem < x){
                 temp=&(*temp)->next;
           }
           if((*temp)==NULL || (*temp)->elem > x){
                 newElem->next=(*temp);
                 (*temp)=newElem;
           }/*else if((*temp)->elem < x && (*temp)->next->elem > x){
                 newElem->next=(*temp)->next;
                 (*temp)->next=newElem; printf("ping");
           }*/
           printf("Inserted %d\n",x);
     }else{
           printf("Elem %d already in Dictionary..\n\n",x);
     }
     //display(D);
     getch();
}

booltype isMember(Dictionary D, int x)
{
         List trav;
         int hx=hash(x);
         if(D[hx]!=NULL){
             trav=D[hx];
             while(trav!=NULL && trav->elem!=x){
                 trav=trav->next;               
             }
         }
         return (D[hx]!=NULL && trav!=NULL && trav->elem==x)? TRUE:FALSE;
}

void display(Dictionary D)
{
     int i; List trav;
     for(i=0;i<SIZE;i++){       
            printf("%d = {",i);
            trav=D[i];
            while(trav!=NULL){
                   printf(" %d ",trav->elem);
                   trav=trav->next;
            }printf("}\n\n");
     }
     getch();
}

void deleteElem(Dictionary D,int x)
{
     if(isMember(D,x)==TRUE){
          int hx=hash(x);
          List delElem,*trav;
          trav=&D[hx];
          while((*trav)!=NULL && (*trav)->elem!=x){
                 trav=&(*trav)->next;
          }
          if((*trav)->elem==x){
                 delElem=(*trav);
                 (*trav)=(*trav)->next;
          }
          free(delElem);
          printf("deleted %d\n",x);
     }else{
          printf("Elem %d not in Dictionary..\n\n",x);
     }
     getch();
}
