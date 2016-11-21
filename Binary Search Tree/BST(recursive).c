#include<stdio.h>
#include<conio.h>
typedef enum { TRUE, FALSE }boolean;
typedef struct nd{
        struct nd* left;
        int x;
        struct nd* right;
}*BST;

BST insert(BST,int);
boolean search(BST,int);
void display(BST);
BST findMin(BST);
BST deletion(BST,int);

int main()
{
    BST root=NULL;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,12);
    root = insert(root,19);
    root = insert(root,24);
    root = insert(root,9); system("cls");
    printf("root->x = %d\n",root->x);
    printf("root->left->x = %d\n",root->left->x);
    printf("root->left->left->x = %d\n",root->left->left->x);
    printf("root->left->right->x = %d\n",root->left->right->x);
    printf("root->right->x = %d\n",root->right->x);
    printf("root->right->right->x = %d\n",root->right->right->x);
    printf("root->right->left->x = %d\n",root->right->left->x);
    printf("root->right->right->left->x = %d\n",root->right->right->left->x);
    printf("root->left->left->right->x = %d\n",root->left->left->right->x);
    if(search(root,9) == TRUE){
         printf("FOUND\n");
    }else{
         printf("NOT FOUND\n"); 
    }
    display(root); getch(); system("cls");
    
    display(root);  
    printf("\nBefore\n\n");
    root = deletion(root,12);
    display(root); 
    printf("\nAfter Deletion of 12\n\n");
    getch(); system("cls");
    
    display(root);  
    printf("\nBefore\n\n");
    root = deletion(root,8);
    display(root); 
    printf("\nAfter Deletion of 8\n\n");
    getch(); system("cls");
    
    display(root); 
    printf("\nBefore\n\n");
    root = deletion(root,20);
    display(root); 
    printf("\nAfter Deletion of 20\n\n");
    getch(); system("cls");
    
    display(root);  
    printf("\nBefore\n\n");
    root = deletion(root,15);
    display(root); 
    printf("\nAfter Deletion of 15\n\n");
    getch(); system("cls");
    return 0;
}

BST insert(BST root,int data)
{
     if(root == NULL){
           BST temp = (BST)malloc(sizeof(struct nd));
           temp->left=temp->right=NULL;
           temp->x=data;   
           root=temp;
     }else if(data <= root->x){
           root->left = insert(root->left,data);
     }else{
           root->right = insert(root->right,data);
     }
     return root;
}

BST deletion(BST root, int data)
{
     if(root == NULL) return root;
     else if(data < root->x) root->left = deletion(root->left,data);
     else if(data > root->x) root->right = deletion(root->right,data);
     else{
           if(root->left==NULL && root->right==NULL){
                free(root);
                root=NULL;
           }else if(root->right==NULL){
                BST temp;
                temp = root;
                root = root->left;
                free(temp); 
           }else if(root->left==NULL){
                BST temp; 
                temp = root;
                root = root->right;
                free(temp);
           }else{
                BST temp = findMin(root->right);
                root->x = temp->x;
                root->right = deletion(root->right,temp->x);
           }
     }
     return root;
}

BST findMin(BST root){
    if(root->left == NULL) return root;
    else return findMin(root->left);
}

boolean search(BST root, int data)
{
        if(root == NULL) return FALSE;
        else if(root->x == data) return TRUE;
        else if(data < root->x) return search(root->left,data);
        else return search(root->right,data);
}

void display(BST root)
{
     if(root != NULL){
           display(root->left);
           printf("%d ",root->x);
           display(root->right);
     }
}


