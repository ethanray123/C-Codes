#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
        int data;
        struct node *next;
}*list,listType;

void createList(list *a);
void delElement(list *a,int elem);
void displayList(list head);
int isEqualList(list a, list b);

int main(){
    list l; char ans; int n;
    l=(list)malloc(sizeof(listType));
    createList(&l);
    if(l!=NULL){
          printf("list with elements 1-5 has been successfully created!\n Would you like to delete a node?(y or n): ");
          scanf("%c",&ans);
          if(ans=='y'){
                printf("Choose an element to delete: ");
                scanf("%d",&n);
                delElement(&l,n);
                displayList(l);
          }else{
                printf("Exiting Program...");
          }
    }else{
          printf("list Creation Unsuccessful..");
    }
    getch();
    return 0;
    
}

void createList(list *a)
{
     list trav; int i;
     trav=(*a);
     for(i=0;i<5;i++){
            trav->data = i + 1;
            trav->next = (list)malloc(sizeof(listType));
            trav = trav->next;
     }
     trav->next=NULL;
}

void displayList(list head){
     list trav; int ctr=1;
     trav=head;
     while(trav!=NULL){
           printf("node %d: %d\n\n",ctr++,trav->data);
           trav=trav->next;
     }
}

void delElement(list *a,int elem)
{
     list trav, temp;  
     trav=(*a);
     if(trav->data == elem){
          (*a)=trav->next;
          trav->next=NULL;
          free(trav);         
     }else{
          for(temp=(*a);trav->next!=NULL;trav=trav->next){
              if(trav->next->data == elem){
                     temp=trav->next;
                     trav->next=trav->next->next;
                     temp->next=NULL;
                     free(temp);
              }
          }
     }
}

int isEqualList(list a, list b)
{
    int equal=0;
    list travA, travB;
    travA = a;
    travB = b;
    while(travA->next!=NULL && travB->next!=NULL){
          if(travA->data == travB->data){
                equal=1;         
          }else{
                equal=0;
                break;
          }
          travA=travA->next;
          travB=travB->next;
    }
    return equal;
}

void changeElem(list *a,int x,int y)
{
     list trav;
     for(trav=(*a);trav->next!=NULL;trav=trav->next){
           if(trav->data == x){
                 trav->data = y;
           }
     }
}

struct node delNode(list *a,int elem)
{
       list trav, temp;  struct node n;
       n.next=NULL;
       trav=(*a);
       if(trav->data == elem){
          n.data=trav->data; 
          (*a)=trav->next;
          trav->next=NULL;
          free(trav);         
       }else{
          for(temp=(*a);trav->next!=NULL && trav->next->data != elem;trav=trav->next){
                n.data=trav->next->data;
                temp=trav->next;
                trav->next=trav->next->next;
                temp->next=NULL;
                free(temp);
          }
       }
       return n;
}

void insertToList(list *a,int elem)
{
     list trav,temp;
     temp=(list)malloc(sizeof(struct node));
     temp->data=elem;
     trav=(*a);
     if(temp->data < trav->data){
            if(temp->data == trav->data){
                  free(temp);
            }else{
                  temp->next = trav;
                  (*a)=temp;
            }
     }else{
           while(trav->next!=NULL && temp->data > trav->data && temp->data < trav->next->data){
                 trav=trav->next;
           }
           if(temp->data == trav->data){
                 free(temp);
           }
           temp->next = trav->next;
           trav->next = temp;
     }
}
