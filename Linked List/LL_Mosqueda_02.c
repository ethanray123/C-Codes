#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct h{
        char name[21];
        int lvl,hp,mp;
        struct h *next;
}*node,ht;
//
void heroCreator(ht **head);
void display(ht **head);

int main()
{
    ht *a;
    heroCreator(&a);
    display(&a);
    getch();
    free(a);
    return 0;
}

void heroCreator(ht **head)
{
     int i; ht *p; 
     (*head)=(ht*)malloc(sizeof(ht));
     p=(*head);
     for(i=1;i<6;i++){
          p->next = (ht*)malloc(sizeof(ht));
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
     }
     p->next=NULL;
}

void display(ht **head)
{
     int i; ht *b;
     b=(*head);
     system("cls");
     for(i=1;i<=5;i++){
          printf("~~~HERO[%d]~~~\nName: %s\n",i,b->name);
          printf("lvl: %d\n",b->lvl);
          printf("hp: %d\n",b->hp);
          printf("mp: %d\n\n",b->mp);
          b=b->next;
     }
}
