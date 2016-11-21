#include<stdio.h>
#include<conio.h>

typedef struct nd{
   enum{leaf,inode}ind;
   union{
        struct{
             int key;
        }lf;
        struct{
             int key[2];
             struct nd* ptr[3];
        }in;
   }U;
}TT,*TTT;

typedef enum {True,False}boolean;

void initLeaf(TTT *ndptr);
void initInode(TTT *ndptr);
void swap(TTT *a,TTT *b);
void insertElem(TTT *S,int elem);
void deleteElem();
boolean isMember();

int main(){
    TTT A=NULL,temp;
    int elems[7] = {16,8,5,2,12,7,19};
    int i;
    for(i=0;i<2;i++){
        insertElem(&A,elems[i]);
    }
    if(A->ind == leaf){
      printf("\nA -> leaf(%d)",A->U.lf.key);
    }else if(A->ind == inode){ 
      printf("\nA -> inode\n"); 
      for(temp=A->U.in.ptr[0],i=0;i<3 && A->U.in.ptr[i]!=NULL;i++,temp=A->U.in.ptr[i]){
            printf("child #%d = %d\n",1+i,temp->U.lf.key);
      }
    }
    getch();
    return 0;
}

void initInode(TTT *ndptr){
    int i;
    (*ndptr)=(TTT)malloc(sizeof(TT));
    (*ndptr)->ind=inode;
    for(i=0;i<3;i++){
         (*ndptr)->U.in.ptr[i]=NULL;
    }
}

void initLeaf(TTT *ndptr){
    (*ndptr)=(TTT)malloc(sizeof(TT));
    (*ndptr)->ind=leaf;
}

void swap(TTT *a,TTT *b){
     TTT *temp;
     temp=a;
     a=b;
     b=temp;
}

void insertElem(TTT *S,int elem){
     if((*S)==NULL){
          printf("A is NULL\n");          
          (*S)=(TTT)malloc(sizeof(TT));
          (*S)->ind=leaf;
          (*S)->U.lf.key=elem;
     }else if((*S)->ind==leaf){
           printf("A is a leaf\n");
           TTT temp,l;
           int i;
           initInode(&temp);
           
           if((*S)->U.lf.key < elem){
                 printf("A's leaf key is lesser than new elem\n");
                 temp->U.in.ptr[0]=(*S); 
                 (*S)=temp;
                 (*S)->ind=inode; 
                 initLeaf(&l);
                 l->U.lf.key=elem;
                 (*S)->U.in.ptr[1]=l; 
                 (*S)->U.in.key[0]=elem;
                 (*S)->U.in.key[1]=-1;
//                 printf("%d\n",(*S)->U.in.ptr[0]->U.lf.key);
//                 printf("%d\n",(*S)->U.in.ptr[1]->U.lf.key);
           }else if((*S)->U.lf.key > elem){
                 printf("A's leaf key is greater than new elem\n");
                 temp->U.in.ptr[1]=(*S); 
                 (*S)=temp;
                 (*S)->ind=inode; 
                 initLeaf(&l);
                 l->U.lf.key=elem; 
                 (*S)->U.in.ptr[0]=l; 
                 (*S)->U.in.key[0]=(*S)->U.in.ptr[1]->U.lf.key;
                 (*S)->U.in.key[1]=-1;
//                 printf("%d\n",(*S)->U.in.ptr[1]->U.lf.key);
//                 printf("%d\n",(*S)->U.in.ptr[0]->U.lf.key);
           }else{
                 printf("Error: elem already in Tree\n"); getch();
           }
     }else{
           TTT temp,l;
           if((*S)->U.in.key[1]==-1){
                 initLeaf(&l);
                 l->U.lf.key=elem; 
                 (*S)->U.in.ptr[2]=l;
                 
                 TTT *p = (*S)->U.in.ptr;
                 
                 if((*p)->U.lf.key > (*(p+2))->U.lf.key){
                      swap(p,(p+2));
                 }
                 if((*p)->U.lf.key > (*(p+1))->U.lf.key){
                      swap(p,(p+1));   
                 }
                 if((*(p+1))->U.lf.key > (*(p+2))->U.lf.key){
                      swap((p+1),(p+2));     
                 }
                 (*S)->U.in.key[0]=(*S)->U.in.ptr[1]->U.lf.key;
                 (*S)->U.in.key[1]=(*S)->U.in.ptr[2]->U.lf.key;
           }else{
                 initLeaf(&l);
                 l->U.lf.key=elem; 
                 initInode(&temp);
                 if(l->U.lf.key < (*S)->U.in.key[1]){
                       temp->U.in.ptr[0]=(*S)->U.in.ptr[1];
                       temp->U.in.ptr[1]=(*S)->U.in.ptr[2];
                       (*S)->U.in.ptr[1]=(*S)->U.in.ptr[0];
                       (*S)->U.in.ptr[0]=l;
                       TTT newN; initInode(&newN);
                       newN->U.in.ptr[0]=(*S);
                       newN->U.in.ptr[1]=temp;
                       (*S)=newN;
                 }else{
                       temp
                 }
           }
     }
}
