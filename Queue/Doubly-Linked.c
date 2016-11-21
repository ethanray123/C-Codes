//Doubly-Linked Queue
#include<stdio.h>
#include<conio.h>

typedef struct nd{
       char elem;
       struct nd *prev;
       struct nd *next;
}*Queue,nodeType;

void initQueue(Queue *);
void enqueue(Queue *,char);
void dequeue(Queue *);
void display(Queue);

int main(){
    Queue Q;
    int choice;
    char e;
    initQueue(&Q);
    do{
       system("cls");  
       printf("1 - initQueue()\n");
       printf("2 - enqueue()\n");
       printf("3 - dequeue()\n");
       printf("4 - display()\n");
       printf("0 - exit()\n\n");
       
       fflush(stdin);
       scanf("%d",&choice);
       system("cls");
       switch(choice){
             case 1:initQueue(&Q);
                    display(Q);break;
             case 2:printf("Enter an element to add: "); fflush(stdin);
                    scanf("%c",&e);
                    enqueue(&Q,e);break;
             case 3:dequeue(&Q);break;
             case 4:display(Q);break;
             case 0:printf("Exiting..\n");break;
             default:printf("error\n");
       }
       getch();
    }while(choice!=0);
    return 0;
}

void initQueue(Queue *Q)
{
     (*Q)=NULL;
}

void enqueue(Queue *Q,char nElem)
{
     Queue temp;
     if((*Q)==NULL){
           (*Q)=(Queue)malloc(sizeof(nodeType));
           (*Q)->next=(*Q);
           (*Q)->prev=(*Q);
     }else{
           temp=(Queue)malloc(sizeof(nodeType));
           (*Q)->prev->next=temp;
           temp->prev=(*Q)->prev;
           (*Q)->prev=temp;
           temp->next=(*Q);
     }
     (*Q)->prev->elem=nElem;
     display(*Q);
}

void dequeue(Queue *Q)
{
     if((*Q)!=NULL){             
           if((*Q)->next==(*Q)){
                (*Q)=NULL;
           }else{
                Queue temp;
                temp=(*Q);
                (*Q)->next->prev=(*Q)->prev;
                (*Q)->prev->next=(*Q)->next;
                (*Q)=(*Q)->next; 
                free(temp);
           }
     }
     display((*Q));
}

void display(Queue Q)
{
     if(Q!=NULL){
           printf("First Elem: %c \n",Q->elem);
           printf("Last Elem: %c \n",Q->prev->elem);
     }else{
           printf("Queue is Empty\n");
     }
}
