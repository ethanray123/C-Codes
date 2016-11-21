//Circular Array Implementation Queue
#include<stdio.h>
#include<conio.h>
#define MAX 8

typedef char ElemArray[MAX];

typedef struct{
       ElemArray E;
       int front;
       int rear;
}Queue;

void initQueue(Queue *);
void enqueue(Queue *,char);
void dequeue(Queue *);
void display(Queue);

int main(){
    Queue Q;
    int choice;
    char e;
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
     Q->rear=0;
     Q->front=1;
}

void enqueue(Queue *Q,char elem)
{
     if((Q->rear+2)%MAX!=Q->front){
           if((Q->rear+1)%MAX==Q->front){
                Q->front=Q->rear;
           }else{
                Q->rear=(Q->rear+1)%MAX; 
           }
           Q->E[Q->rear]=elem;
           printf("Q.E[Q.rear] = %c\n",Q->E[Q->rear]);
           printf("Q.E[Q.front] = %c\n",Q->E[Q->front]);
           printf("Q.rear%d\n\n",Q->rear);
     }else{
           printf("Queue is Full\n");
     }
     display(*Q);
}

void dequeue(Queue *Q)
{
     if((Q->rear+1)%MAX!=Q->front){
           Q->front=(Q->front+1)%MAX;
     }else{
           printf("Queue is Empty\n");
     }
     display(*Q);
}

void display(Queue Q)
{
     if((Q.rear+1)%MAX!=Q.front){
         printf("First elem: %c\n",Q.E[Q.front]);
         printf("Last elem: %c\n",Q.E[Q.rear]);
     }else{
           printf("Queue is Empty\n");
     }
}
