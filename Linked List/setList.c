#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node{
        int data;
        struct node* next;
}*list;

typedef enum{
        TRUE,FALSE
}boolean;

void creatingLists(list *,list *);
void displayList(list);
boolean subsetList(list,list);
list intersectionList(list,list);
list unionList(list,list);

int main ()
{
    list A,B,C,D;
    int choice;
    boolean subset;
    A=NULL; B=NULL; C=NULL; D=NULL;

    if(A == NULL && B == NULL){
         creatingLists(&A,&B);
    }
    do{
       system("cls");
       printf("A: ");
       displayList(A);
       printf("B: ");
       displayList(B);
       printf("1 - Is list A subset of list B?\n");
       printf("2 - Find the Intersection of both lists\n");
       printf("3 - Find the Union of both lists\n");
       printf("0 - Exit\n\n");
       printf("What do you want to do?: "); fflush(stdin);
       scanf("%d",&choice);

       switch(choice){
             case 1:subset=subsetList(A,B);
                    if(subset == TRUE){
                          printf("A is a Subset of B");
                    }else{
                          printf("A is not a Subset of B");
                    }
                    break;
             case 2:C=intersectionList(A,B);
                    printf("A Intersection B: ");
                    displayList(C);
                    break;
             case 3:D=unionList(A,B);
                    printf("A Union B: ");
                    displayList(D);
                    break;
             case 0:printf("Exiting...");break;
             default: printf("Invalid Choice...");
       }
       getch();
    }while(choice!=0);
    free(A);
    free(B);
    free(C);
    free(D);
    return 0;
}

void creatingLists(list *a,list *b)
{
     int i;
     printf("___Kindly Create Two Lists___ \n\n");
     printf("Enter values for list A: \n");
     for(i=0;i<4;i++){
           (*a)=(list)malloc(sizeof(struct node)); fflush(stdin);
           scanf("%d",&(*a)->data);
           a=&(*a)->next;
     }
     (*a)=NULL;

     printf("Enter values for list B: \n");
     for(i=0;i<5;i++){
           (*b)=(list)malloc(sizeof(struct node)); fflush(stdin);
           scanf("%d",&(*b)->data);
           b=&(*b)->next;
     }
     (*b)=NULL;
}

void displayList(list a)
{
     if(a==NULL){
          printf("NULL\n");
     }
     while(a!=NULL){
           printf("%d ",a->data);
           a=a->next;
     }
     printf("\n\n");
}

boolean subsetList(list a,list b)
{
        
        while(a != NULL && b != NULL && a->data >= b->data){
                if(a->data == b->data){
                       a=a->next;
                }
                b=b->next;
        }
        

        return (a==NULL)?TRUE:FALSE;
}

list intersectionList(list a,list b)
{
    list c, *temp;
    temp=&c;
    (*temp)=(list)malloc(sizeof(struct node));
    while(a != NULL && b != NULL){
            if(a->data > b->data){
                  b=b->next;
            }else if(b->data > a->data){
                  a=a->next;
            }else{
                  (*temp)->data=a->data;
                  (*temp)->next=(list)malloc(sizeof(struct node));
                  temp=&(*temp)->next;
                  a=a->next;
                  b=b->next;
            }
    }
     free(temp);
    (*temp)=NULL;
    return c;
}

list unionList(list a, list b)
{
    list d; list *temp;
    temp=&d;
    (*temp)=(list)malloc(sizeof(struct node));
    while(a != NULL && b != NULL){
            (*temp)->next=(list)malloc(sizeof(struct node));
            if(a->data == b->data){
                  (*temp)->data=a->data;
                  a=a->next;  
                  b=b->next;
            }else if(a->data < b->data){
                  (*temp)->data=a->data;
                  a=a->next;  
            }else if(a->data > b->data){
                  (*temp)->data=b->data;
                  b=b->next;  
            }
            temp=&(*temp)->next;
    }
    if(a==NULL){
          while(b!=NULL){
                (*temp)->data=b->data;
                (*temp)->next=(list)malloc(sizeof(struct node));
                temp=&(*temp)->next;
                b=b->next;    
          }           
    }else{
          while(a!=NULL){
                (*temp)->data=a->data;
                (*temp)->next=(list)malloc(sizeof(struct node));
                temp=&(*temp)->next;
                a=a->next;              
          }      
    }
    free(temp);
    (*temp)=NULL;
    return d;
}
