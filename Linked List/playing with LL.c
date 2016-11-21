#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//struct making
typedef struct node{
        int val;
        struct node *next;
}*node,nd;

//prototype making
void createList(node *l);
void displayList(node l);

int main()
{
    node root;
    createList(&root);
    displayList(root);
    getch();
    free(root);
    return 0;
}

void createList(node *l)
{
     node trav; int i;
     (*l)=(node)malloc(sizeof(nd));
     trav=(*l);
     for(i=1;i<=10;i++){
          trav->val=i;
          trav->next=(node)malloc(sizeof(nd));
          trav=trav->next;
     }
     trav->next=NULL;
}

void displayList(node l)
{
     node temp;
     if((l)!=NULL){
           printf("~~~~Display~~~~\n\n");
           temp=(l);
           while(temp->next!=NULL){
                  printf("%d ",temp->val);
                  temp=temp->next;
           }
     }
     free(temp);
}
