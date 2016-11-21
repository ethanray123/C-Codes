#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct nd{
     int num;   
     struct nd *next;
}*List, listType;

void createNode(List *head, int n);
void displayList(List head);
int delNode(List *head,int nodeCtr);

int main(){
    List h=NULL; int choice, ndctr=0, nelem, ind;
    do{
         printf("Current No. of Nodes: %d\nWhat do you want to do?\n\n",ndctr); 
         printf("0 - Create a Node\n1 - Delete a Node\n2 - Display\n3 - Exit\n\n__"); 
         scanf("%d",&choice);
         if(choice == 0){
                   system("cls");
                   printf("Enter a number to put in Node: ");
                   scanf("%d",&nelem);
                   createNode(&h,nelem);
                   if(h!=NULL){
                               ndctr++;
                               printf("List has successfuly been created\n");
                               printf("Numbers Inside\n\n");
                               displayList(h);
                   }else{
                               printf("Error(List not Created)");
                   }
         }else if(choice == 1){
               system("cls");
               printf("NODES: \n\n");
               displayList(h);
               ind=delNode(&h,ndctr);
               if(ind==1){
                     printf("\nChanges have been implemented..\n");
                     displayList(h);
                     ndctr--;
               }else if(ind==0){
                     printf("Node not Found..");
               }
         }else if(choice == 2){
               system("cls");
               displayList(h);
         }
         getch(); system("cls");
    }while(choice != 3);
    printf("Exiting Program..");
    getch();
    return 0;
}

void createNode(List *head, int n){
     List temp;
     temp = (List)malloc(sizeof(listType));
     temp->num = n;
     temp->next = (*head);
     (*head) = temp;
}

void displayList(List head){
     List trav; int ctr=1;
     trav=head;
     while(trav!=NULL){
           printf("node %d: %d\n\n",ctr++,trav->num);
           trav=trav->next;
     }
}

int delNode(List *head,int nodeCtr){
     int node, ctr=1, retval; List trav,temp; 
     trav=temp=(*head);
     printf("Which node should be deleted?: "); fflush(stdin); scanf("%d",&node);
     if(node<=nodeCtr){
           if(ctr==node){
                   temp=(*head);
                   (*head)=(*head)->next;
                   free(temp);
           }else{
                   while(ctr!=node){
                            temp=temp->next;
                            ctr++;
                   }
                   while(trav->next != temp){
                            trav=trav->next;
                   }
                   trav->next=temp->next;
                   free(temp);
           }
           retval = 1;
     }else{
           retval = 0;
     }
     return retval;
}
