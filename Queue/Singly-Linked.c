//Singly-Linked Queue
#include<stdio.h>
#include<conio.h>

typedef struct nd{
       char elem;
       struct nd *next;
}*ndPtr,nodeType;

typedef struct{
       ndPtr front;
       ndPtr rear;
}Queue;

void initQueue(Queue *);
void enqueue(Queue *,char);
void dequeue(Queue *);
void display(Queue);

int main()
{
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
     Q->front=NULL;
     Q->rear=NULL;
}

void enqueue(Queue *Q, char newE)
{
     if(Q->front==NULL){
           Q->rear=(ndPtr)malloc(sizeof(nodeType));
           Q->front=Q->rear;
     }else{
           Q->rear->next=(ndPtr)malloc(sizeof(nodeType));
           Q->rear=Q->rear->next;
     }
     Q->rear->elem=newE;
     Q->rear->next=NULL;
     display((*Q));
}

void dequeue(Queue *Q){
     if(Q->front!=NULL){
          ndPtr temp;
          temp=Q->front;
          Q->front=Q->front->next;
          free(temp);
     }
     display((*Q));
}

void display(Queue Q)
{
     if(Q.front!=NULL){
           printf("First Elem %c ",Q.front->elem);
           printf("Last Elem %c ",Q.rear->elem);
     }else{
           printf("Queue is Empty\n");
     }
}
