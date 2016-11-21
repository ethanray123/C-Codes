#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct nd{
        int elem;
        struct nd *next;
}*List,ListType;

void createList(List *l);
void delNode(List *l,int num);
void displayList(List l);

int main(){
    List l; char ans; int n;
    l=(List)malloc(sizeof(ListType));
    createList(&l);
    if(l!=NULL){
          displayList(l);  
          printf("\n\nList with elements 1-5 has been successfully created!\n Would you like to delete a node?(y or n): ");
          scanf("%c",&ans);
          if(ans=='y'){
                printf("Choose an element to delete: ");
                scanf("%d",&n);
                delNode(&l,n);
                system("cls");
                displayList(l);
          }else{
                printf("Exiting Program...");
          }
    }else{
          printf("List Creation Unsuccessful..");
    }
    getch();
    return 0;
    
}

void createList(List *l)
{
     List trav; int i;
     trav=(*l);
     for(i=0;i<5;i++){
            trav->elem = i+1;
            trav->next = (List)malloc(sizeof(ListType));
            trav = trav->next;
     }
     trav->next=NULL;
}

void delNode(List *l,int num)
{
     List *trav,temp;  
     trav=l;
     if((*trav)->elem == num){
     		temp=(*trav);
          	(*trav)=(*trav)->next;
          	free(temp);         
     }else{
          while((*trav)!=NULL){
              if((*trav)->elem==num){
              		temp=(*trav);
                    (*trav)=(*trav)->next;
                    free(temp);
              }
              trav=&(*trav)->next;
          }
     }
}

void displayList(List l)
{
     List temp;
     if(l!=NULL){
           printf("\n\n~~~~Display~~~~\n\n");
           temp=l;
           while(temp->next!=NULL){
                  printf("%d ",temp->elem); 
                  temp=temp->next; 
           }
     }
}



