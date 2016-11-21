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
    SET C,*temp;
    temp=&C;
    (*temp)=(SET)malloc(sizeof(ctype));
    while(A!=NULL && B!=NULL){
           (*temp)->next=(SET)malloc(sizeof(ctype));
           if(A->elem < B->elem){
                 (*temp)->elem = A->elem;
                 A=A->next;
           }else if(A->elem > B->elem){
                 (*temp)->elem = B->elem;
                 B=B->next;
           }else if(A->elem == B->elem){
                 (*temp)->elem = A->elem;
                 A=A->next;
                 B=B->next;
           }
           temp=&(*temp)->next;
    }
    if(A==NULL){
          while(B!=NULL){
                 (*temp)->elem=B->elem;
                 (*temp)->next=(SET)malloc(sizeof(ctype));
                 temp=&(*temp)->next;
                 B=B->next;
          }      
    }else{
          while(A!=NULL){
                 (*temp)->elem=A->elem;
                 (*temp)->next=(SET)malloc(sizeof(ctype));
                 temp=&(*temp)->next;
                 A=A->next;
          }      
    }
    free(temp);
    (*temp)=NULL;
    return C;
}

SET AintersectionB(SET A, SET B){
    SET C, *temp;
    temp=&C;
    (*temp)=(SET)malloc(sizeof(ctype));
    while(A!=NULL && B!=NULL){
           (*temp)->next=(SET)malloc(sizeof(ctype));
           if(A->elem < B->elem){
                 A=A->next;
           }else if(A->elem > B->elem){
                 B=B->next;
           }else if(A->elem == B->elem){
                 (*temp)->elem = A->elem;
                 A=A->next;
                 B=B->next;
           }
           temp=&(*temp)->next;
    }
    free(temp);
    (*temp)=NULL;
    return C;
}

SET AminusB(SET A, SET B){
    SET C,*temp;
    temp=&C;
    (*temp)=(SET)malloc(sizeof(ctype));
    while(A!=NULL && B!=NULL){
           (*temp)->next=(SET)malloc(sizeof(ctype));
           if(A->elem < B->elem){
                 (*temp)->elem = A->elem;  
                 A=A->next;   
           }else if(A->elem > B->elem){
                 B=B->next;
           }else if(A->elem == B->elem){
                 A=A->next;
                 B=B->next;
           }
           temp=&(*temp)->next;
    }
    if(B==NULL){
           while(A!=NULL){
                 (*temp)->next=(SET)malloc(sizeof(ctype));
                 (*temp)->elem=A->elem;
                 temp=&(*temp)->next;
                 A=A->next;
           }
    }
    free(temp);
    (*temp)=NULL;
    return C;
}
