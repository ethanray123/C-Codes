/******************************************************************
 * Project Name:  Dictionary and Priority Queue                    *
 * Programmer  :  Mosqueda, Ethan Ray F.                           *
 * Date Completed: August 11, 2016                                 *
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 		0X20
#define SIZE 		0XC
#define PRIME_SIZE	0XD
#define SYN_SIZE    0X7
#define EMPTY		"empty"
#define DELETED		"deleted"
#define HEAPSIZE	0XA


/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef enum {
	TRUE, FALSE
}boolean;

typedef struct {  
	char name[LENGTH];       /* Chocolate name */  
	int  weight;             /* Chocolate weight in grams */
}chocoDesc;

typedef struct {
    char prodID[SIZE];      /*  product ID uniquely identifies the products; EMPTY or DELETED */ 
	chocoDesc prodDesc;     /*  product description*/  
	float prodPrice;        /*  product price*/  
	int prodQty;            /* product count or quantity  */
}product;                   /* product record */


/* Closed hashing with separate synonym area */
typedef struct {
	product elem;           /* Element of the dictionary */
	int next;               /* pointer to a synonym */
}node;

typedef struct Dic {
	node prime[PRIME_SIZE];   /* Prime Data Area, where elements are stored if slot is empty or deleted */
	node syn[SYN_SIZE];       /* Synonym Area, where elements are stored if prime data is occupied  */
	int avail;				  /* Holds the index of the first available node in the synonym area */		
}*Dictionary;


/* Priority Queue */
typedef struct {
	chocoDesc data[HEAPSIZE];
	int last;                   /* index of last element in the Heap or List */
}Heap;


/**********************************************************
* Function Prototypes                                    *
 *********************************************************/
void initDictionary(Dictionary *D); 
void displayDictionary(Dictionary D);

int hash(char *IDen);
boolean isMember(Dictionary D, char *IDen);
void insertDic(Dictionary D, product P);
void populateDictionary(Dictionary D);

void deleteDic(Dictionary D, char *IDen); 

void initMaxHeap(Heap *H); 
void insertMaxHeap(Heap *H, chocoDesc C);
void populateMaxHeap(Heap *H, Dictionary D);
void displayMaxHeap(Heap H);

void swapChoco(chocoDesc *X, chocoDesc *Y) ;
void heapSort(Heap *H); 

/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *  
 *   3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *   4)  Uncomment or copy the print statement in each PROBLEM#  if the task is     *
 *       completed.                                                                 *
 ***********************************************************************************/
int main( ) 
 {	
  /*-------------------------------------------------------------------------------
   * Write all variable declaration here.                                         *
   *------------------------------------------------------------------------------*/
	Dictionary A;
    char delete01[] = "170145";
    char delete02[] = "15507";
    product insert01 = {"1501978", {"Hersheys", 100}, 100.50, 10};
    product insert02 = {"99094", {"Lindt", 100}, 175.50, 80};
    Heap B;
    /*---------------------------------------------------------------------------------*
     * 	Problem #1 ::  Display the newly initialized dictionary.                       *
     *---------------------------------------------------------------------------------*/
    printf("Problem #1:: ");
    initDictionary(&A); 
    displayDictionary(A); system("cls");
      
//    int ha;
//    printf("prime area size %d\n",PRIME_SIZE);
//    ha=hash("14551");
//    printf("14551 ha %d",ha);
/*---------------------------------------------------------------------------------
 * 	Problem #2 ::  Call populateDictionary() and display resulting dictionary.    *
 *--------------------------------------------------------------------------------*/
    printf("Problem #2:: ");
    populateDictionary(A);
    displayDictionary(A); system("cls");

 /*---------------------------------------------------------------------------------
  * 	Problem #3 ::  Call deleteDic() two times passing delete01 and delete02     * 
  *                 variables and display resulting dictionary. Call insertDic() two*
  *                 times passing insert01 and insert02 variables and display       *
  *                 resulting dictionary.                                           *                             *
  *---------------------------------------------------------------------------------*/
    deleteDic(A,delete01); //printf("A->avail=%d\n",A->avail); getch();
    deleteDic(A,delete02); /*printf("A->avail=%d\n",A->avail); getch();system("cls");*/
    printf("Problem #3:: After Delete "); 
    displayDictionary(A); system("cls"); 
    insertDic(A,insert01);
    insertDic(A,insert02);
    printf("Problem #3:: After Insert ");
    displayDictionary(A); system("cls");

/*---------------------------------------------------------------------------------
 * 	Problem #4 ::  Initialize and populate the max Heap and call displayMaxHeap().*
 *--------------------------------------------------------------------------------*/	
    initMaxHeap(&B); 
    populateMaxHeap(&B,A); system("cls");
    printf("Problem #4:: ");
    displayMaxHeap(B); system("cls");
	
/*---------------------------------------------------------------------------------
 * 	Problem #5 ::  Perform heapSort and display the resulting sorted list of choco *
 *                 records.                                                        *                                                     *
 *---------------------------------------------------------------------------------*/		
    heapSort(&B); system("cls");
    printf("Problem #5:: ");  
    displayMaxHeap(B);
    
	return 0;
}

/************************************************************
 *  Problem 1 Function Definitions                          *
 ************************************************************/
void initDictionary(Dictionary *D)
{
	int p,s;
	(*D)=(Dictionary)malloc(sizeof(struct Dic));
	for(p=0;p<PRIME_SIZE;p++){                                             
	    strcpy((*D)->prime[p].elem.prodID,EMPTY);
	    (*D)->prime[p].next=-1;
    }    
    for(s=SYN_SIZE-1;s>=0;s--){
       (*D)->syn[s].next=s-1;
    } 
    (*D)->avail=SYN_SIZE-1;
}
 
void displayDictionary(Dictionary D)
{
		
	printf("\n\n%-7s", "Index");
	printf("%-12s","Prime Area");
	printf("%-10s","Synonyms");
    
    int p,trav;
    for(p=0;p<PRIME_SIZE;p++){
         printf("\n%5d", p);    
         if(strcmp(D->prime[p].elem.prodID,EMPTY)==0 || strcmp(D->prime[p].elem.prodID,DELETED)==0){
               if(strcmp(D->prime[p].elem.prodID,DELETED)==0){
                     printf("%9s",D->prime[p].elem.prodID); 
               }else{
                     printf("%7s",D->prime[p].elem.prodID);
               }
         }else{
               if(strlen(D->prime[p].elem.prodDesc.name)==4){
                     printf("%6s",D->prime[p].elem.prodDesc.name);                                            
               }else if(strlen(D->prime[p].elem.prodDesc.name)==5){  
                     printf("%7s",D->prime[p].elem.prodDesc.name);
               }else if(strlen(D->prime[p].elem.prodDesc.name)==6){
                     printf("%8s",D->prime[p].elem.prodDesc.name); 
               }else if(strlen(D->prime[p].elem.prodDesc.name)==7){
                     printf("%9s",D->prime[p].elem.prodDesc.name); 
               }else if(strlen(D->prime[p].elem.prodDesc.name)==8){
                     printf("%10s",D->prime[p].elem.prodDesc.name); 
               }else{
                     printf("%11s",D->prime[p].elem.prodDesc.name);
               }

         } 
         if(D->prime[p].next!=-1){                    
              trav=D->prime[p].next;    
              while(trav!=-1){   
                  if(strlen(D->syn[trav].elem.prodDesc.name)==9){
                        printf("%16s",D->syn[trav].elem.prodDesc.name);                                         
                  }else if(strlen(D->syn[trav].elem.prodDesc.name)==6){
                        if(strlen(D->prime[p].elem.prodID)==7){
                            printf("%11s",D->syn[trav].elem.prodDesc.name);
                        }else{
                            printf("%9s",D->syn[trav].elem.prodDesc.name);
                        }
                  }else if(strlen(D->syn[trav].elem.prodDesc.name)==7){                                  
                        printf("%13s",D->syn[trav].elem.prodDesc.name); 
                  }else if(strlen(D->prime[p].elem.prodDesc.name)==8){                                  
                        printf("%9s",D->syn[trav].elem.prodDesc.name); 
                  }else{
                        printf("%10s",D->syn[trav].elem.prodDesc.name);
                  }
                  trav=D->syn[trav].next;
              }
         }
    }
    printf("\n\nAvail :: %d",D->avail);

	printf("\n\nPress any key to continue. "); getch();		
}

/************************************************************
*  Problem 2 Function Definitions                          *
 ************************************************************/
int hash(char *IDen)
{
    int sum=0,digit=0,i;
    for(i=0;IDen[i]!='\0';i++){
          digit=IDen[i]-48;
          sum+=digit;
    }
    return sum%PRIME_SIZE;
}

boolean isMember(Dictionary D,char *IDen)
{
        boolean b;
        int ha=hash(IDen),i;
        if(strcmp(D->prime[ha].elem.prodID,IDen)!=0){
              if(strcmp(D->prime[ha].elem.prodID,EMPTY)==0){
                   b=FALSE;                                        
              }else{
                   i=D->prime[ha].next;
                   while(i!=-1 && strcmp(D->syn[i].elem.prodID,IDen)!=0){
                        i=D->syn[i].next; //printf("ey");       
                   } 
                   if(i==-1){
                        b=FALSE;  //printf("aha");   
                   }else{ 
                        /*printf("Elem in Dic\n");*/ b=TRUE; 
                   }
              }
        }else{ /*printf("Elem in Dic\n");*/b=TRUE; }
        return b;
}

void insertDic(Dictionary D,product P)
{
     int ha,trav,temp;
     ha=hash(P.prodID); //printf("\nha for (%s) %d\n",P.prodDesc.name,ha);    
       if(isMember(D,P.prodID)==FALSE){
            if(strcmp(D->prime[ha].elem.prodID,EMPTY)==0 || strcmp(D->prime[ha].elem.prodID,DELETED)==0){
                 D->prime[ha].elem=P;
            }else{ 
                 temp=D->avail; 
                 D->avail=D->syn[D->avail].next;
                 D->syn[temp].elem=P;
                 D->syn[temp].next=D->prime[ha].next;
                 D->prime[ha].next=temp;
                 
                 /*
                 printf("D->syn[temp].elem (%s)\n",D->syn[temp].elem.prodDesc.name);
                 printf("D->syn[temp].next = %d",D->syn[temp].next);
                 
                 displayDictionary(D); system("cls");*/
            }
       }
}

void populateDictionary(Dictionary D)
{
	const int COUNT = 12;
	product data[] = { 	{"170145" , {"Toblerone", 135}, 150.75, 20},
						{"1356",    {"Ferrero", 200}, 250.75, 85},
						{"15507",   {"Cadbury", 120}, 200.00, 30},
						{"180731",  {"Mars", 100}, 150.75, 20},
						{"12015",   {"Kitkat", 50}, 97.75, 40},
						{"1450",    {"Ferrero", 100},150.50, 50},
						{"170145",  {"Toblerone", 50}, 90.75, 80},
						{"1601",	{"Meiji", 75}, 75.50, 60},
						{"13101813",{"Nestle", 100}, 124.50, 70},
						{"154535", 	{"Valor", 120}, 149.50, 90},
						{"14551",   {"Tango", 75}, 49.50, 100},
						{"1703451", {"Toblerone", 100}, 125.75, 60},
		              };
    int i,ha,trav,temp;
    for(i=0;i<COUNT;i++){
        insertDic(D,data[i]);
    }
}

/************************************************************
 *  Problem 3 Function Definitions                          *
 ************************************************************/
void deleteDic(Dictionary D,char *IDen)
{
     int ha,trav,temp,x;
     ha=hash(IDen); //printf("(%s)",IDen);
     if(isMember(D,IDen)==TRUE){
          //printf("Made it~ ");
          if(strcmp(D->prime[ha].elem.prodID,IDen)==0){
                 strcpy(D->prime[ha].elem.prodID,DELETED);
                 //printf("Primary Delete\n%s\n",D->prime[ha].elem.prodID); getch();
          }else{
                 trav=D->prime[ha].next;
                 x=D->syn[trav].next;
                 if(strcmp(D->syn[trav].elem.prodID,IDen)==0){
                      temp=trav;
                      D->prime[ha].next=D->syn[trav].next;
                      D->syn[temp].next=D->avail;
                      D->avail=temp;
                      //printf("if\n");
                 }else{
                      while(D->syn[x].next!=-1 && strcmp(D->syn[x].elem.prodID,IDen)!=0){
                           trav=D->syn[trav].next; 
                           x=D->syn[trav].next; //printf("ho");        
                      }
                      
                      temp=D->syn[trav].next;
                      D->syn[trav].next=D->syn[x].next;
                      D->syn[x].next=D->avail;
                      D->avail=temp;
                      //printf("else\n");
                 }
                 /*printf("trav %d\n",trav);
                 printf("temp %d\n",temp);
                 printf("Synonym Delete\n"); getch(); 
                 
                 displayDictionary(D); system("cls");*/
          }
     }else{
           printf("Elem not in Dic\n"); getch();
     }
}

/************************************************************
 *  Problem 4 Function Definition                           *
 ************************************************************/
void initMaxHeap(Heap *H)
{
     int i;
     for(i=0;i<HEAPSIZE;i++){
          H->data[i].weight=0;
     }
     H->last=-1;
}

void insertMaxHeap(Heap *H,chocoDesc C)
{ 
     int p,c,val;
     if(H->last != HEAPSIZE-1){
          c=++H->last; //printf("H->last = %d\n",H->last);
          for(p=(c-1)/2;c!=0 && strcmp(H->data[p].name,C.name)<0;c=p,p=(c-1)/2){
                H->data[c]=H->data[p];
                //printf("H->data[p-%d]=%s\n",p,H->data[p].name);
                //printf("H->data[c-%d]=%s\n",c,H->data[c].name);
          }
          if(c==0){
                H->data[c]=C;
                //printf("H->data[c-%d]=%s\n",c,H->data[c].name);
          }else{
                H->data[c]=C;
                //printf("H->data[c-%d]=%s\n",c,H->data[c].name);
          }
     }else{
          //printf("No more Space in heap\n"); getch();
     }//if-else statement
}//end of func

void populateMaxHeap(Heap *H, Dictionary D)
{
	const int COUNT = 14;
	product data[] = { 	{"170145" , {"Toblerone", 135}, 150.75, 20},
						{"1356",    {"Ferrero", 200}, 250.75, 85},
						{"15507",   {"Cadbury", 120}, 200.00, 30},
						{"180731",  {"Mars", 100}, 150.75, 20},
						{"12015",   {"Kitkat", 50}, 97.75, 40},
						{"1450",    {"Ferrero", 100},150.50, 50},
						{"170145",  {"Toblerone", 50}, 90.75, 80},
						{"1501978", {"Hersheys", 100}, 100.50, 10},
					    {"99094",   {"Lindt", 100}, 175.50, 80},
						{"1601",	{"Meiji", 75}, 75.50, 60},
						{"13101813",{"Nestle", 100}, 124.50, 70},
						{"154535", 	{"Valor", 120}, 149.50, 90},
						{"14551",   {"Tango", 75}, 49.50, 100},
						{"1703451", {"Toblerone", 100}, 125.75, 60},
		              };
    int i,x=0;
    for(i=0;i<COUNT;i++){
        if(isMember(D,data[i].prodID)==TRUE){  
          //printf("%s %d\n",data[i].prodDesc.name,data[i].prodDesc.weight);
          insertMaxHeap(H,data[i].prodDesc);
//            if(H->last != HEAPSIZE-1){
//              x=++H->last;              
//              H->data[x]=data[i].prodDesc;
//            }
        }
    }
}	

void displayMaxHeap(Heap H)
{
	printf("\n\n%-7s", "Index");
	printf("%-12s","Choco Name");
	printf("%-10s","Choco Weight");
    int i;
    if(H.last!=-1){
         for(i=0;i<=H.last;i++){
              printf("\n%5d  ",i);
	          printf("%-12s",H.data[i].name);
	          printf("%-10d",H.data[i].weight);
         }
    }
	printf("\n\nPress any key to continue. "); getch();		
}

/************************************************************
 *  Problem 5 Function Definitions                          *
 ************************************************************/
void heapSort(Heap *H)
{
     int i,oldlast,tree,p,lc,rc;
     oldlast=H->last;
     for(i=H->last;i>0;i--){     
         //printf("Before: ");
         //printf("[0] = %s\n[%d] = %s\n",H->data[0].name,H->last,H->data[H->last].name);                       
         swapChoco(&H->data[0],&H->data[H->last--]); 
         //printf("After: ");
         //printf("[0] = %s\n[%d] = %s\n",H->data[0].name,H->last,H->data[H->last].name);   
         for(tree=(H->last-1)/2;tree>=0;tree--){
             p=tree;
             for(lc=(p*2)+1,rc=lc+1; lc < H->last && 
                   (strcmp(H->data[p].name,H->data[lc].name)<0 || (rc > H->last || strcmp(H->data[p].name,H->data[rc].name)<0));
                        lc=(p*2)+1,rc=lc+1){
                   if(rc <= H->last){
                         if(strcmp(H->data[p].name,H->data[lc].name)<0 && strcmp(H->data[lc].name,H->data[rc].name)>0){
                              swapChoco(&H->data[p],&H->data[lc]);
                              p=lc;
                         }else if(strcmp(H->data[p].name,H->data[rc].name)<0 && strcmp(H->data[lc].name,H->data[rc].name)<=0){
                               swapChoco(&H->data[p],&H->data[rc]);
                               p=rc;
                         }
                   }else{
                         if(strcmp(H->data[p].name,H->data[lc].name)<0){
                               swapChoco(&H->data[p],&H->data[lc]);
                               p=lc;
                         }
                   }
             }//inner for
         }//outer for
         //displayMaxHeap(*H);
     }//heapsort for
     H->last=oldlast;
}

void swapChoco(chocoDesc *X,chocoDesc *Y)
{
     chocoDesc temp;
     temp=(*X);
     (*X)=(*Y);
     (*Y)=temp;
}
