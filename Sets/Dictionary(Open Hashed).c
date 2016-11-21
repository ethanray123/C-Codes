#include<stdio.h>
#include<conio.h>
#define SIZE 10

typedef struct node{
        int elem;
        struct node* next;
}nodeType,*nPtr;
typedef nPtr Dictionary[SIZE];
typedef enum{TRUE,FALSE}boolType;

void initDictionary(Dictionary);
void displayDictionary(Dictionary);
void insert(Dictionary,int);
void deleteElem(Dictionary,int);
int Hash(int);
boolType isElem(Dictionary,int);

int main()
{
    Dictionary A;
    int i,x;
    boolType b;
    
    initDictionary(A);
    for(i=0;i<SIZE && A[i]==NULL;i++){}
    if(i==SIZE){ printf("Dictionary Initialized..\n"); }
    for(i=0;i<5;i++){
          printf("Enter an Element to add in the Dictionary: "); fflush(stdin);
          scanf("%d",&x);
          insert(A,x);
    }
    printf("Set A = {"); displayDictionary(A); printf(" }\n");
    
    printf("Enter an Element to check in the Set: "); fflush(stdin);
    scanf("%d",&x);
    b=isElem(A,x);
    if(b==TRUE){ 
          printf("%d is an elem of Set A..\n",x); 
    }else{ printf("%d is not an elem of Set A..\n",x); }
    getch();
    for(i=0;i<3;i++){
       printf("Enter an elem to Delete: "); fflush(stdin);
       scanf("%d",&x);
       deleteElem(A,x);
       printf("Set A = {"); displayDictionary(A); printf(" }\n");
       getch(); system("cls");
    }
    getch();
    return 0;
}
int Hash(int a)
{
     return a % 10;
}

void initDictionary(Dictionary D)
{
     int i;
     for(i=0;i<SIZE;i++){
           D[i]=NULL;
     }
}

void displayDictionary(Dictionary D)
{
     int i;
     nPtr temp;
     for(i=0;i<SIZE;i++){
          temp=D[i];               
          while(temp!=NULL){             
               printf(" %d",temp->elem);
               temp=temp->next;
          }
     }                          
}

boolType isElem(Dictionary D,int x)
{
     int hx=Hash(x); nPtr temp=D[hx];
     if(temp!=NULL){
          while(temp->next!=NULL && temp->elem != x){
              temp=temp->next;
          }
     }
     return (temp!=NULL && temp->elem==x)?TRUE:FALSE;
}
void insert(Dictionary D,int x)
{
     int hx; nPtr *trav; 
     hx=Hash(x); 
     if(D[hx]==NULL){  
          D[hx]=(nPtr)malloc(sizeof(nodeType));
          D[hx]->elem=x;
          D[hx]->next=NULL;
     }else{
           if(isElem(D,x)==TRUE){
                printf("Element already in Set..\n");
           }else{
                trav=&D[hx];
                while((*trav)!=NULL){trav=&(*trav)->next;} 
                (*trav)=(nPtr)malloc(sizeof(nodeType));
                (*trav)->elem=x; 
                (*trav)->next=NULL;
           }
     }
}

void deleteElem(Dictionary D,int x)
{
     int hx; nPtr *trav,temp;
     hx=Hash(x);
     if(isElem(D,x)==TRUE){
          trav=&D[hx];
          while(*trav!=NULL && (*trav)->elem!=x){
                trav=&(*trav)->next;
          }
          temp=(*trav);
          (*trav)=(*trav)->next;
          free(temp);
     }else{ printf("Element is not in Set..\n"); }
}
