#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OPEN_SIZE 26
#define CLOSE_SIZE 53

typedef enum {
	EMPTY, DELETED, OCCUPIED
}statusType;    

typedef enum {
	TRUE, FALSE
}boolean;

/******************************************************************************
 * Data Structure Definition: Open and Closed Hashing Implementations         *
 ******************************************************************************/

typedef struct { 
	char FName[24];    /* firstname */
	char LName[16];    /* lastname */
	char MI;          /* middle initial */ 
}nameType; 

typedef struct {
	char IDen[9];     /* 8-digit ID Number which uniquely identifies the student record */
	nameType name; 
	char course[8]; 
	char year;         /* used as 1-byte integer */ 
	char gender;       /* F - female, M-male */
}studRec; 

typedef struct node {
	studRec stud;
	struct node *next;  
}*studPtr;

typedef struct {
	studPtr ptr;    
	statusType status;    
}closeNode;                 /* closed hash table node */ 

typedef struct {
	studPtr ptr;
	int count;            /*  holds the number of elements in the each group */
}openNode;

typedef struct Dic {
        openNode openHT[OPEN_SIZE];      /* open Hashing */     
        closeNode closeHT[CLOSE_SIZE];   /* Closed Hashing */   
        int closeHashCount;              /* holds the number of elements in the close hash table */
}*Dictionary;

typedef struct  {
	studRec data[CLOSE_SIZE];
	int last;                    /* index of last element */
} dataList;                     /* Array implementation of list */

/* End of Declarations of Structs, macros and enums */

//function Prototypes
int openHash(char lastname[]);
int closeHash(char ID[]);
dataList getData();
void displayHashValues(dataList data);

void initDictionary(Dictionary *D); 
char * getClosedHashStatus(Dictionary D, int ndx);
void displayOpenHashDic(Dictionary D);
void displayClosedHashDic(Dictionary D);
void displayDictionary(Dictionary D);

boolean isMember(Dictionary D, char ID[]);
void insertDictionary(studRec stud, Dictionary D);
void populateDictionary(Dictionary D);

boolean deleteMemID(Dictionary D, char ID[]);
void deleteIdManager(Dictionary D, char ID[]);

boolean deleteUniqueName(Dictionary D, char LN[]);
void deleteUniqueNameManager(Dictionary D, char LN[]);

//MAIN
int main()
{
    Dictionary A;
    dataList L;
    char *deleteID_01 = "12104029"; //{"Mary Grace", "Tan", 'A'}, "BSCS", 4, 'F'}
    char *deleteID_02 = "13101821"; //does not exist
    char *deleteID_03 = "13101820"; //{"Juan", "Zozobrano", 'N'}, "BSCS", 3, 'F'}
    char *lname_01 = "Baguio"; //not Unique
    char *lname_02 = "Ang";  //can be deleted

    L=getData(); 
    displayHashValues(L);
    initDictionary(&A);
    displayDictionary(A);
    populateDictionary(A);
    displayDictionary(A);
    deleteIdManager(A,deleteID_01);
    deleteIdManager(A,deleteID_02);
    deleteIdManager(A,deleteID_03);
    displayDictionary(A); 
    deleteUniqueNameManager(A,lname_01);
    deleteUniqueNameManager(A,lname_02); 
    displayDictionary(A);
    return 0;
}


int openHash(char lastname[])
{
    return (lastname[0]-65) % 26;
}
 
int closeHash(char ID[])
{
    int p,val=0,x=100;
    for(p=4;p<7;p++,x/=10){
         val+=(ID[p]-48)*x;
    }
    return (val*val)%53;
}

dataList getData()
{
	dataList L;
	int const DATA_COUNT = 15;
	studRec data[] = { 	{"12104029", {"Mary Grace", "Tan", 'A'}, "BSCS", 4, 'F'},
				{"14100686", {"John Joseph", "Mendoza", 'B'}, "BSCS", 2, 'M'},
				{"13101813", {"Bernardina", "Velasco", 'C'}, "BSCS", 3, 'F'},
				{"14101125", {"Faith Therese", "Flores", 'D'}, "BSCS", 2, 'F'},
				{"15101848", {"Ryan Christian", "Mercado", 'E'}, "BSCS", 1, 'M'},
				{"15104179", {"Simon Peter", "Amolo", 'F'}, "BSIT", 1, 'M'},
				{"15103188", {"Mikee", "Seno", 'G'}, "BSIT", 1, 'F'},
				{"14104110", {"Tom Christian", "Fernandez", 'H'}, "BSIT", 2, 'M'},
				{"13101845", {"Janine Angela", "Ang", 'I'}, "BSIT", 3, 'F'},
				{"12102385", {"Hans Christian", "Anderson", 'J'}, "BSIT", 4, 'M'},
				{"15102424", {"Albert John", "Baguio", 'K'}, "BSICT", 1, 'M'},
				{"14101125", {"Maria Sonia", "Gaviola", 'L'}, "BSCS", 2, 'F'},
				{"12107777", {"Antonette Marie", "Lee", 'M'}, "BSICT", 4, 'F'},
				{"13101820", {"Juan", "Zozobrano", 'N'}, "BSCS", 3, 'F'},
				{"15101824", {"Josephine", "Baguio", 'O'}, "BSICT", 1, 'M'},
				   };
	memcpy(L.data,data,sizeof(studRec)*DATA_COUNT);
    L.last=DATA_COUNT-1;
	return L;			
}

void displayHashValues(dataList L)
{
	int i,val;
    /*	system("cls"); */
	printf("\n%s", "Displaying Open and Closed Hash Values");
	printf("\n--------------------------------------\n");
	printf("\n%-10s","ID");
	printf("%-30s","Name");
	printf("%2s","Open HValues");
	printf("%20s","Closed HValues");
	printf("\n");   
    
    
    for(i=0;i<=L.last;i++){
        val=strlen(L.data[i].name.FName)+strlen(L.data[i].name.LName)+5;                   
        if(val>21){
               printf("\n%-10s",L.data[i].IDen);
	           printf("%s, %s %c.\t",L.data[i].name.LName,L.data[i].name.FName,L.data[i].name.MI);
	           printf("%2d",openHash(L.data[i].name.LName));
	           printf("%20d",closeHash(L.data[i].IDen),val);
	           printf("\n");                                                    
        }else{
               printf("\n%-10s",L.data[i].IDen);
	           printf("%s, %s %c.\t\t",L.data[i].name.LName,L.data[i].name.FName,L.data[i].name.MI);
	           printf("%2d",openHash(L.data[i].name.LName));
	           printf("%20d",closeHash(L.data[i].IDen),val);
	           printf("\n");
        } 
                   
    }
    
    printf("\n\nPress any key to continue...  ");
    getch();
    system("cls");
}

void initDictionary(Dictionary *D)
{
     int i;
     (*D)=(Dictionary)malloc(sizeof(struct Dic));
     for(i=0;i<OPEN_SIZE;i++){
          (*D)->openHT[i].ptr=NULL;
          (*D)->openHT[i].count=0;
     }
     for(i=0;i<CLOSE_SIZE;i++){     
          (*D)->closeHT[i].ptr=NULL;
          (*D)->closeHT[i].status=EMPTY;
     }
     (*D)->closeHashCount=0;
}

void displayDictionary(Dictionary D)
{
	displayOpenHashDic(D);
	displayClosedHashDic(D);
}

void displayOpenHashDic(Dictionary D)
{
     int i;
     printf("\n%s", "Displaying Open Hash Table");
	 printf("\n---------------------------\n\n");
	 for(i=0;i<OPEN_SIZE;i++){
	     printf("Group %2d, Count =  %d :: ",i,D->openHT[i].count);
	     if(D->openHT[i].ptr==NULL){
              printf("NULL");
         }else{
              studPtr trav; int x=0;
              trav=D->openHT[i].ptr; 
              while(trav!=NULL && x<D->openHT[i].count){ 
                   printf("%-10s",trav->stud.name.LName);
                   trav=trav->next;
              }
         }
         printf("\n");
     }
     printf("\nPress any key to continue..."); getch(); system("cls");
}

char * getClosedHashStatus(Dictionary D, int ndx)
{
     char *b;
     b=(char*)malloc(sizeof(char)*9);
     if(D->closeHT[ndx].status == OCCUPIED){
           strcpy(b,"OCCUPIED");
     }else if(D->closeHT[ndx].status == DELETED){
           strcpy(b,"DELETED");
     }else{
           strcpy(b,"EMPTY");
     }
     return b;
}


void displayClosedHashDic(Dictionary D)
{
     int i;
     printf("\n%s", "Displaying Close Hash Table");
	 printf("\n---------------------------\n\n");
	 printf("Total Element Count :: %d\n\n",D->closeHashCount);
	 for(i=0;i<CLOSE_SIZE;i++){
           printf("Index  %2d :: %-10s",i,getClosedHashStatus(D,i));
           if(strcmp(getClosedHashStatus(D,i),"OCCUPIED")==0){
                 printf("%-10s [%s]",D->closeHT[i].ptr->stud.IDen,D->closeHT[i].ptr->stud.name.LName);
           }
           printf("\n");
     }printf("\nPress any key to continue..."); getch(); system("cls");
}

boolean isMember(Dictionary D, char ID[])
{
     boolean b;  
     int ha=closeHash(ID),i; 
     if(D->closeHT[ha].ptr!=NULL){ printf("Made it..ha = %d\n",ha);
          if(strcmp(D->closeHT[ha].ptr->stud.IDen,ID)==0){ 
               b=TRUE;
          }else{
                i=ha;
                do{ 
                    i=(i+1) % CLOSE_SIZE; printf("i = %d,ha = %d\n",i,ha);
                }while(i!=ha && D->closeHT[i].status!=EMPTY && strcmp(D->closeHT[i].ptr->stud.IDen,ID)!=0);
                
                if(D->closeHT[i].status==EMPTY || i==ha){
                      b=FALSE;
                }else if(strcmp(D->closeHT[i].ptr->stud.IDen,ID)==0){
                      b=TRUE;
                }
          }
     }else{
           b=FALSE;
     }
     return b;
}

void insertDictionary(studRec stud, Dictionary D)
{
     if(isMember(D,stud.IDen)==FALSE){                          
           int chs=closeHash(stud.IDen),ohs=openHash(stud.name.LName),i;
           studPtr newStud=(studPtr)malloc(sizeof(studRec));
           newStud->stud=stud;
           newStud->next=NULL;
           
           if(D->closeHT[chs].status!=OCCUPIED){
                 //printf("Made it...\n");     
                 D->closeHT[chs].ptr=newStud;                  
                 D->closeHT[chs].status=OCCUPIED;
           }else{
                 i=chs;
                 do{ i=(i+1)%CLOSE_SIZE; /*printf("Made it and moved to hash %d..\n",i);*/}while(D->closeHT[i].status!=EMPTY && i!=chs);
                 D->closeHT[i].ptr=newStud;
                 D->closeHT[i].status=OCCUPIED;
           }
           D->closeHashCount++;
           //printf("Made it through..\n");
           if(D->openHT[ohs].ptr==NULL){
                 D->openHT[ohs].ptr=newStud;
           }else{
                 studPtr *trav;
                 trav=&D->openHT[ohs].ptr;
                 while((*trav)!=NULL && strcmp((*trav)->stud.name.LName,stud.name.LName)<0){
                      trav=&(*trav)->next;
                 }
                 if((*trav)==NULL || strcmp((*trav)->stud.name.LName,stud.name.LName)>0){
                      newStud->next=(*trav);
                      (*trav)=newStud;
                 }else if(strcmp((*trav)->stud.name.LName,stud.name.LName)<0 && strcmp((*trav)->next->stud.name.LName,stud.name.LName)>0){
                      newStud->next=(*trav)->next;
                      (*trav)->next=newStud;
                 }else{
                      newStud->next=(*trav)->next;
                      (*trav)->next=newStud; 
                 }
           }
           D->openHT[ohs].count++;
           printf("studRec Inserted.\n");
     }else{
           printf("studRec Already in Dictionary..\n");
     }
}

void populateDictionary(Dictionary D)
{
     int i;
     dataList L=getData();
     for(i=0;i<=L.last;i++){ 
          printf("try %d ",i);
          insertDictionary(L.data[i],D);
     }
}

boolean deleteMemID(Dictionary D, char ID[])
{
     boolean b; int i,hb;  
     if(isMember(D,ID)==TRUE){                   
           int ha=closeHash(ID);
           if(D->closeHT[ha].status==OCCUPIED && strcmp(D->closeHT[ha].ptr->stud.IDen,ID)==0){
                 D->closeHT[ha].status=DELETED;  
                 hb=openHash(D->closeHT[ha].ptr->stud.name.LName); //printf("%s",D->closeHT[ha].ptr->stud.name.LName);
                 D->openHT[hb].count--;           
           }else{
                 i=ha;
                 do{ i=(i+1)%CLOSE_SIZE; }while(D->closeHT[i].status!=EMPTY && strcmp(D->closeHT[i].ptr->stud.IDen,ID)!=0 && i!=ha);
                 if(strcmp(D->closeHT[i].ptr->stud.IDen,ID)==0){
                       D->closeHT[i].status=DELETED;
                       hb=openHash(D->closeHT[i].ptr->stud.name.LName); 
                       D->openHT[hb].count--;
                 }
           }
           b=TRUE;
           D->closeHashCount--;
     }else{
           b=FALSE;
     }
     return b;
}

void deleteIdManager(Dictionary D, char ID[])
{
     if(deleteMemID(D,ID)==TRUE){
           printf("Record with ID# %s is DELETED.\n",ID);
     }else{
           printf("Record with ID# %s does Not Exist.\n",ID);
     }
     printf("\nPress any key to continue..."); getch(); system("cls");
}

boolean deleteUniqueName(Dictionary D, char LN[])
{
       boolean b=FALSE; int ha,i,hb;
       char ID[9];                     
       ha=openHash(LN); printf("ha = %d\n",ha);
       studPtr *trav,temp;
       
       
       
       trav=&D->openHT[ha].ptr; 
       if(strcmp(D->openHT[ha].ptr->stud.name.LName,LN)==0 && D->openHT[ha].ptr->next==NULL){
                                                           
              b=TRUE;
              if(b==TRUE){
                          printf("meep\n");    printf("hb = %d\n",hb);  
                          if(D->closeHT[hb].status==OCCUPIED && strcmp(D->closeHT[hb].ptr->stud.IDen,ID)==0){
                          D->closeHT[hb].status=DELETED; 
                          D->closeHashCount--;                                                
                          }else{
                                i=hb; printf("i=%d %s\n",i,D->closeHT[hb].ptr->stud.IDen);
                                do{
                                        i=(i+1) % CLOSE_SIZE;  printf("i=%d %s\n",i,D->closeHT[i].ptr->stud.IDen);
                                }while(i!=hb && strcmp(D->closeHT[i].ptr->stud.IDen,ID)!=0 && D->closeHT[i].status!=EMPTY);
                                printf("%s",D->closeHT[i].ptr->stud.IDen);
                                D->closeHT[i].status=DELETED;
                                D->closeHashCount--;
                                printf("POLIO\n");
                   
                          }
              }
                                                           
              temp=(*trav);
              (*trav)=(*trav)->next;
              free(temp);
              D->openHT[ha].count--; 
              printf("1b=TRUE\n");
              
              memcpy(ID,D->openHT[ha].ptr->stud.IDen,sizeof(char)*9); 
              hb=closeHash(ID);
              
       }else{
             while((*trav)!=NULL && strcmp((*trav)->stud.name.LName,LN)!=0){
                   trav=&(*trav)->next;
             }
             if((*trav)==NULL){
                   b=FALSE; 
                   printf("b=FALSE\n");       
             }else if(strcmp((*trav)->stud.name.LName,LN)==0 && (*trav)->next==NULL){
                   memcpy(ID,(*trav)->stud.IDen,sizeof(char)*9); printf("(*trav)->stud.IDen = %s\n",(*trav)->stud.IDen);
                   hb=closeHash(ID); printf("hb = %d\n",hb);
                   
                   b=TRUE;
                   if(b==TRUE){
                               printf("meep\n");    printf("hb = %d\n",hb);  
                               if(D->closeHT[hb].status==OCCUPIED && strcmp(D->closeHT[hb].ptr->stud.IDen,ID)==0){
                               D->closeHT[hb].status=DELETED; 
                               D->closeHashCount--;                                                
                               }else{
                                     i=hb; printf("i=%d %s\n",i,D->closeHT[hb].ptr->stud.IDen);
                                     do{
                                        i=(i+1) % CLOSE_SIZE;  printf("i=%d %s\n",i,D->closeHT[i].ptr->stud.IDen);
                                     }while(i!=hb && strcmp(D->closeHT[i].ptr->stud.IDen,ID)!=0 && D->closeHT[i].status!=EMPTY);
                                     printf("%s",D->closeHT[i].ptr->stud.IDen);
                                     D->closeHT[i].status=DELETED;
                                     D->closeHashCount--;
                                     printf("POLIO\n");
                   
                               }
                   }
                   
                   temp=(*trav);
                   (*trav)=(*trav)->next;
                   free(temp);
                   printf("2b=TRUE\n"); 
                   D->openHT[ha].count--; 
                   
             }else if(strcmp((*trav)->stud.name.LName,LN)==0 && strcmp((*trav)->next->stud.name.LName,LN)==0){
                   b=FALSE;
                   printf("got here where b=FALSE\n"); 
             }
       }
       
       return b;
}

void deleteUniqueNameManager(Dictionary D, char LN[])
{
     if(deleteUniqueName(D,LN)==TRUE){
           printf("%s Record is DELETED.\n",LN);
     }else{
           printf("%s Record does Not Exist or not Unique.\n",LN);
     }
     printf("\nPress any key to continue..."); getch(); system("cls");
}
