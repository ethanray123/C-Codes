#include<stdio.h>
#include<string.h>
#include<conio.h>
#define SIZE 9
typedef struct{
	int elem[SIZE];
	int last;
}PQ;

void initialize(PQ*);
void insertMin(PQ*,int);
void insert(PQ*,int);
void swap(PQ*,int,int);
void heapifyMax(PQ*);
void heapSortMin(PQ*);
int deletemin(PQ*);
void display(PQ);

int main()
{
    PQ P; int num,i,x;
    initialize(&P);
    //printf("Enter amount of numbers to HeapSort(Ascending): "); fflush(stdin);
//    scanf("%d",&num);
//    for(i=0;i<num;i++){
//         printf("Element no.%d: ",i+1);
//         fflush(stdin); scanf("%d",&x);
//         insert(&P,x);
//    }
    insert(&P,5);
    heapifyMax(&P);
    printf("after heapifyMax\n");
    display(P);
    insert(&P,3);
    heapifyMax(&P);
    printf("after heapifyMax\n");
    display(P);
    insert(&P,6);
    heapifyMax(&P);
    printf("after heapifyMax\n");
    display(P);
    insert(&P,4);
    heapifyMax(&P);
    printf("after heapifyMax\n");
    display(P);
    insert(&P,5);
    heapifyMax(&P);
    printf("after heapifyMax\n");
    display(P);
    insert(&P,2);
    heapifyMax(&P);
    printf("after heapifyMax\n");
    display(P);
    insert(&P,2);
    heapifyMax(&P);
    printf("after heapifyMax\n");
    display(P);
    insert(&P,8);
    heapifyMax(&P);
    printf("after heapifyMax\n");
    display(P);
    insert(&P,1);
    heapifyMax(&P);
    printf("after heapifyMax\n");
    display(P);
    heapSortMin(&P);
    display(P);
    
    return 0;
}

void initialize(PQ *P)
{
     int i;
     for(i=0;i<SIZE;i++){
          P->elem[i]=0;
     }
     P->last=-1;
}

void display(PQ P)
{
     int i;
     printf("PQ 'P' =");
     for(i=0;i<=P.last;i++){
          printf(" %d ",P.elem[i]);
     }printf("\tP.last = %d\n\t",P.last);
     for(i=0;i<=P.last;i++){
          printf(" %d ",i);
     }printf("\n");
     getch();
}

void insert(PQ *P,int x)
{
     if(P->last!=SIZE-1){
          P->elem[++P->last]=x;
     }
}

void swap(PQ *P,int p, int c)
{
     int tempval;
     printf("Before - Parent: %d\tChild: %d\n",P->elem[p],P->elem[c]); 
     tempval=P->elem[p];
     P->elem[p]=P->elem[c];
     P->elem[c]=tempval;
     printf("After - Parent: %d\tChild: %d\n",P->elem[p],P->elem[c]); getch();
}

void heapifyMax(PQ *P)
{
     int ppos,lc,rc,tree,tempval; 
     for(tree=(P->last-1)/2;tree>=0;tree--){                              
         ppos=tree;                                                                 
         printf("ppos = %d\n",ppos); 
         for(lc=(2*ppos) + 1, rc=lc + 1; lc < P->last && 
                (P->elem[ppos] < P->elem[lc] || (rc > P->last || P->elem[ppos] < P->elem[rc]));
					lc=(2*ppos) + 1, rc=lc + 1){
               printf("lc = %d\trc = %d\n",lc,rc);                                       //parent is lesser than lc or Rc
               printf("parent = %d, left child = %d, right child = %d\n",P->elem[ppos],P->elem[lc],P->elem[rc]);
               if(rc <= P->last){      
                     if(P->elem[ppos]<P->elem[lc] && P->elem[lc]>P->elem[rc]){           //parent is lesser than lc: swap parent and lc
                          swap(P,ppos,lc);
                          ppos=lc;
                          //printf("if ppos = %d\n",ppos);
                     }else if(P->elem[ppos]<P->elem[rc] && P->elem[lc]<=P->elem[rc]){    //parent is lesser than rc
                          swap(P,ppos,rc);
                          ppos=rc;
                          //printf("else if\n");
                     }
               }else{
                     if(rc > P->last && P->elem[ppos]<P->elem[lc]){
                          swap(P,ppos,lc);
                          ppos=lc; 
                          //printf("else\n");
                     }
               }      
         }
         if(P->last==1){
               if(P->elem[ppos]<P->elem[lc]){
                      swap(P,ppos,lc);
                      ppos=lc;                       
               }
         }
     }
}

int deletemin(PQ *P)
{
    int min;
    min=P->elem[P->last];
    P->elem[P->last]=P->elem[0]; 
    P->last--; printf("min=%d\n",min); 
    return min;
}
void heapSortMin(PQ *P)
{
     int i,oldlast;
     oldlast=P->last;
     for(i=P->last;i>0;i--){
          P->elem[0]=deletemin(P); //P->last is minused
          heapifyMax(P);
          display((*P));
     }
     P->last=oldlast; //P->last goes back to its original value
}
