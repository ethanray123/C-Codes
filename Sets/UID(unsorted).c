#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct cell{
        int elem;
        struct cell* next;
}ctype,*SET;

int main(){
    return 0;
}

SET AunionB(SET A, SET B){
    SET C,*temp,*trav;
    temp=&C;
    (*temp)=(SET)malloc(sizeof(ctype));
    while(A!=NULL){
        (*temp)->next=(SET)malloc(sizeof(ctype));      
        (*temp)->elem=A->elem;
        temp=&(*temp)->next;
        A=A->next;   
    }
    while(B!=NULL){
        trav=&C;           
        while((*trav)!=NULL && B->elem!=(*trav)->elem){trav=&(*trav)->next;}
        if((*trav)==NULL){
             (*temp)->next=(SET)malloc(sizeof(ctype));
             (*temp)->elem=B->elem;
             temp=&(*temp)->next;         
        }
        B=B->next;
    }
    free(temp);
    (*temp)=NULL;
    return C;
}

SET AintersectionB(SET A, SET B){
    SET C, *temp,*trav;
    temp=&C;
    (*temp)=(SET)malloc(sizeof(ctype));
    while(A!=NULL){
          trav=&B;
          while((*trav)!=NULL && A->elem != (*trav)->elem){
                trav=&(*trav)->next;         
          }
          if(A->elem == (*trav)->elem){
                (*temp)->next=(SET)malloc(sizeof(ctype));
                (*temp)->elem=A->elem;
                temp=&(*temp)->next;
          }         
          A=A->next;
    }
    free(temp);
    (*temp)=NULL;
    return C;
}

SET AminusB(SET A, SET B){
    SET C,*temp,*trav;
    temp=&C;
    (*temp)=(SET)malloc(sizeof(ctype));
    while(A!=NULL){
          trav=&B;         
          while((*trav)!=NULL && A->elem != (*trav)->elem){
                trav=&(*trav)->next;              
          }
          if((*trav)==NULL){
                (*temp)->next=(SET)malloc(sizeof(ctype));
                (*temp)->elem=A->elem;
                temp=&(*temp)->next;                    
          }
          A=A->next;
    }
    free(temp);
    (*temp)=NULL;
    return C;
}
