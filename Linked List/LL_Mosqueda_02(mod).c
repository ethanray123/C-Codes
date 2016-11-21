#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct h{
        char name[21];
        int lvl,hp,mp;
        struct h *next;
}*node,ht;
//
void heroCreator(node *head);
void display(node *head);

int main()
{
    node a;
    heroCreator(&a);
    display(&a);
    getch();
    free(a);
    return 0;
}

void heroCreator(node *head)
{
     int i; node p; 
     (*head)=(node)malloc(sizeof(ht));
     p=(*head);
     for(i=1;i<6;i++){
          p->next = (node)malloc(sizeof(ht));
          printf("HERO[%d]\n",i); fflush(stdin);
          printf("Enter Name: ");
          gets(p->name);
          printf("Enter lvl: ");
          scanf("%d",&p->lvl);
          printf("Enter hp: ");
          scanf("%d",&p->hp);
          printf("Enter mp: ");
          scanf("%d",&p->mp);
          p=p->next;
          system("cls");
     }
     p->next=NULL;
}

void display(node *head)
{
     int i=1; node b;
     b=(*head);
     system("cls");
     while(b->next!=NULL){
          printf("~~~HERO[%d]~~~\nName: %s\n",i++,b->name);
          printf("lvl: %d\n",b->lvl);
          printf("hp: %d\n",b->hp);
          printf("mp: %d\n\n",b->mp);
          b=b->next;
     }
}
