#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100
typedef struct{
      char elem;
      int next;  
}HeapSpace[MAX];

typedef struct{
      HeapSpace H;
      int avail; 
}VirtualHeap;

typedef int Set;
typedef enum{TRUE,FALSE}Boolean;

void initSpace(VirtualHeap *);
void addElem(int *,VirtualHeap *);
void displayElems(int,VirtualHeap);
void delAllOccur(int *,VirtualHeap *,char);
void changeElem(int,VirtualHeap *,char,char);
void insertUniqueSorted(int *,VirtualHeap *);

int main()
{
    int L,choice;
    VirtualHeap VH;
    char del,rep;
    initSpace(&VH);
    L=-1;
    do{
       system("cls");
       printf("1 - addElem()\n");
       printf("2 - delAllOccur()\n");
       printf("3 - changeElem()\n");
       printf("4 - insertUniqueSorted()\n");
       printf("5 - displayElems\n");
       printf("0 - exit program\nEnter a Number based on the functions: ");
       fflush(stdin);
       scanf("%d",&choice);
       switch(choice){
              case 0:printf("\nExiting...");break;
              
              case 1:addElem(&L,&VH);
                     displayElems(L,VH);break;
                     
              case 2:printf("What do you want to delete?: "); fflush(stdin);
                     scanf("%c",&del);
                     delAllOccur(&L,&VH,del);
                     displayElems(L,VH);break;
                     
              case 3:printf("What Value needs to be changed?: "); fflush(stdin);
                     scanf("%c",&del);
                     printf("What Value should it be replaced with?: ");fflush(stdin);
                     scanf("%c",&rep); 
                     changeElem(L,&VH,del,rep);break;
              
              case 4:insertUniqueSorted(&L,&VH);
                     displayElems(L,VH);break;
              
              case 5:displayElems(L,VH);break;
              default:printf("\nInvalid Choice..."); 
       }
       getch();
    }while(choice!=0);
    return 0;
}

void initSpace(VirtualHeap *VH)
{
     int x,lim=MAX-1;
     VH->avail=0;
     for(x=VH->avail;x<lim;x++){
          VH->H[x].elem=0;
          VH->H[x].next=x+1;
     }VH->H[x].next=-1;
}

void addElem(int *L,VirtualHeap *VH)
{
     int temp;
     if(VH->avail!=-1){           
           printf("\navail = %d\n",VH->avail);
           printf("elem(char):"); 
           fflush(stdin);
           scanf("%c",&VH->H[VH->avail].elem);
           
           temp=VH->avail;
           VH->avail=VH->H[VH->avail].next;
           VH->H[temp].next=(*L);
           (*L)=temp;
           
     }else{
           printf("\navail = %d\n",VH->avail);
           printf("Insufficient Space...Free memory\n\n");
     }
}

void displayElems(int L,VirtualHeap VH)
{
     int x=L;
     if(x==-1){
           printf("\nList is Empty\n");
     }
     printf("\n");
     for(;x!=-1;x=VH.H[x].next){
           printf("%d - %c:%d\n",x,VH.H[x].elem,VH.H[x].next);
     }
}

void delAllOccur(int *x,VirtualHeap *VH,char occur)
{
     int *y=x,temp;
     
     while((*y)!=-1){
           if(VH->H[(*y)].elem==occur){
                 temp=VH->avail;
                 VH->avail=(*y);
                 (*y)=VH->H[VH->avail].next;
                 VH->H[VH->avail].next=temp;
           }else{
                 y=&VH->H[(*y)].next;
           }
     }
}

void insertUniqueSorted(int *L,VirtualHeap *VH)
{
     int *y=L,x=VH->avail,temp;
     
     if(VH->avail!=-1){           
           printf("\navail = %d\n",VH->avail);
           printf("elem(char):"); 
           fflush(stdin);
           scanf("%c",&VH->H[VH->avail].elem);
           
           while((*y)!=-1 && VH->H[(*y)].elem < VH->H[x].elem){
                 y=&VH->H[(*y)].next;                       
           }
           if((*y)==-1){
                 temp=VH->avail;
                 VH->avail=VH->H[VH->avail].next;
                 (*y)=temp;
           }else if(VH->H[(*y)].elem > VH->H[x].elem){
                 temp=VH->avail;
                 VH->avail=VH->H[VH->avail].next;
                 VH->H[temp].next=(*y);
                 (*y)=temp;
           }else if(VH->H[(*y)].elem == VH->H[x].elem){
                 printf("Value already in List...\n");
           }
     }else{
           printf("\navail = %d\n",VH->avail);
           printf("Insufficient Space...Free memory\n\n");
     }
}

void changeElem(int L,VirtualHeap *VH,char old,char replacement)
{
     int y;
     
     for(y=L;y!=-1;y=VH->H[y].next){
          if(VH->H[y].elem==old){
                VH->H[y].elem=replacement;      
                printf("Replaced Value\n");                                    
          }
     }
}

Boolean isSubset(Set A,Set B,VirtualHeap *VH)
{
        int x,y;
        for(x=A;x!=-1;){
              for(y=B;y!=-1 && VH->H[x].elem!=VH->H[y].elem;y=VH->H[y].next){}
              if(VH->H[x].elem==VH->H[y].elem){
                    x=VH->H[x].next;
              }else{ break; }
        }
        return (x==-1)?TRUE:FALSE;
}

Boolean setDifference(Set A,Set B,VirtualHeap *VH)
{
        Set C=-1;
        int x,y,z,temp;
        for(x=A;x!=-1;){
               for(y=B;y!=-1;y=VH->H[y].elem){
                     if(VH->H[x].elem==VH->H[y].elem){
                          x=VH->H[x].elem; break;
                     }
               }
               if(y==-1){
                     temp=VH->avail;
                     VH->avail=VH->H[VH->avail].next;
                     VH->H[temp].next=C;
                     C=temp;
                     VH->H[C].elem=VH->H[x].elem;
                     x=VH->H[x].next;
               }
        }
        return C;
}
