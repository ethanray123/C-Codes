#include<stdio.h>
#include<conio.h>
typedef enum { TRUE, FALSE }boolean;
typedef struct nd{
        struct nd* left;
        int x;
        struct nd* right;
}*BST;

typedef int Stack[10];
void insert(BST*,int);
boolean search(BST,int);
void display(BST);

int main()
{
    BST root=NULL;
    insert(&root,15);
    insert(&root,10);
    insert(&root,20);
    insert(&root,25);
    insert(&root,8);
    insert(&root,12);
    insert(&root,19);
    insert(&root,24);
    insert(&root,9);
    printf("root->x = %d\n",root->x);
    printf("root->left->x = %d\n",root->left->x);
    printf("root->left->left->x = %d\n",root->left->left->x);
    printf("root->left->right->x = %d\n",root->left->right->x);
    printf("root->right->x = %d\n",root->right->x);
    printf("root->right->right->x = %d\n",root->right->right->x);
    printf("root->right->left->x = %d\n",root->right->left->x);
    printf("root->right->right->left->x = %d\n",root->right->right->left->x);
    printf("root->left->left->right->x = %d\n",root->left->left->right->x);
    if(search(root,26) == TRUE){
         printf("FOUND\n");
    }else{
         printf("NOT FOUND\n"); 
    }
    display(root);
    getch();
    return 0;
}

void insert(BST* root,int data)
{
     BST *trav;
     BST temp = (BST)malloc(sizeof(struct nd));
     temp->left=temp->right=NULL;
     temp->x=data; 
     trav=root;
     printf("trav");
     if((*trav) == NULL){
           (*trav)=temp;
           printf("->x = %d\n\n",(*trav)->x);
     }else if(data <= (*trav)->x){
           while((*trav)->left!=NULL && data <= (*trav)->x){
                 trav=&(*trav)->left; printf("->left");
           }
           if(data <= (*trav)->x){
               (*trav)->left=temp;
               printf("->left->x = %d\n\n",(*trav)->left->x);
           }else{
               (*trav)->right=temp;  
               printf("->right->x = %d\n\n",(*trav)->right->x);
           }
           
     }else{
           while((*trav)->right!=NULL && data > (*trav)->x){
                 trav=&(*trav)->right; printf("->right");
           }
           if(data > (*trav)->x){
               (*trav)->right=temp;
               printf("->right->x = %d\n\n",(*trav)->right->x);
           }else{
               (*trav)->left=temp;  
               printf("->left->x = %d\n\n",(*trav)->left->x);
           }
     }
     
}

boolean search(BST root, int data)
{
        boolean b;
        BST trav=root;
        while(trav!=NULL && trav->x!=data){
                if(data < trav->x){
                     trav=trav->left;
                }else{
                     trav=trav->right;
                }
        }
        if(trav!=NULL){
             b=TRUE;       
        }else{ b=FALSE; }
        return b;
}

void deletion(BST *root, int data)
{
     BST *trav=root,temp;
     while(*trav!=NULL && (*trav)->x!=data){
                if(data < (*trav)->x){
                     trav=&(*trav)->left;
                }else{
                     trav=&(*trav)->right;
                }
     }
     if((*trav)->x==data){
          temp=*trav;
          if((*trav)->left==NULL && (*trav)->right==NULL){
                free(temp);               
          }else if((*trav)->left!=NULL && (*trav)->right==NULL){
                (*trav)=(*trav)->left;
                free(temp);
          }else if((*trav)->left==NULL && (*trav)->right!=NULL){
                (*trav)=(*trav)->right;
                free(temp);
          }else{
                
          }
          
     }
}
void display(BST root)
{
     if(root != NULL){
           if(root->left != NULL){
                display(root->left);
           }
           printf("%d ",root->x);
           if(root->right != NULL){
                display(root->right);
           }
     }
}

