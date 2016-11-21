#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct nodes{
        int x;
        struct nodes *next;
}*node,nd;
//
void evenNumList(node *head);
void display(node *head);

int main()
{
    node a;
    evenNumList(&a);
    display(&a);
    getch();
    free(a);
    return 0;
}

void evenNumList(node *head)
{
     int i=2; node p; 
     (*head)=(node)malloc(sizeof(nd));
     (*head)->x = i;
     p=(*head);
     printf("~~~Execution Check~~~\n\np->x: %d\t\tp: %d\n\n",p->x,p);
     for(i=4;i<=10;i+=2){
          p->next = (node)malloc(sizeof(nd));
          p->next->x = i;
          printf("p->next->x: %d",p->next->x);
          p=p->next;
          printf("\tp: %d\n\n",p);
     }
     p->next=NULL;
}

void display(node *head)
{
     /*int i=0; nd *b;
     b=(*head);
     for(i=0;i<5;i++){
          printf("\na->x: %d\n",b->x);
          b=b->next;
     }*/
     node b;
     if((*head)!=NULL){
            printf("~~~Display~~~\n\nFirst Node x: %d\n",(*head)->x);
            for(b=(*head);b->next!=NULL;b=b->next);
                 printf("Last Node x: %d",b->x);
     }
     free(b);      
}
