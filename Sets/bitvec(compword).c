#include<stdio.h>
#include<stdlib.h>
typedef char SET;
typedef enum{TRUE,FALSE}boolean;

boolean isMember(int,SET);
void insertElem(int,SET*);
void deleteElem(int,SET*);
SET AunionB(SET,SET);
SET AintersectionB(SET,SET);
SET AdifferenceB(SET,SET);
void display(SET);

int main()
{
    int choice,check,elem;
    SET A=105;
    SET B=30;
    SET C=0;
    do{
       system("cls");
       printf("Set A = ");display(A);
       printf("Set B = ");display(B);
       printf("Set C = ");display(C);
       printf("Set U = {0 1 2 3 4 5 6 7}\n");
       printf("1 - isMember();\n");
       printf("2 - insertElem();\n");
       printf("3 - deleteElem();\n");
       printf("4 - AunionB();\n");
       printf("5 - AintersectionB();\n");
       printf("6 - AdifferenceB();\n\n");
       printf("Enter a number that corresponds to your desired function: "); fflush(stdin);
       scanf("%d",&choice);
       system("cls");
       switch(choice){
              case 0:printf("Exiting program..");break;
              case 1:display(A);
                     printf("Enter an Element to Find in set A: ");fflush(stdin);
                     scanf("%d",&check);
                     if(isMember(check,A)==TRUE){
                           printf("%d is an element of A",check);
                     }else{
                           printf("%d is not an element of A",check);
                     }break;
              case 2:display(A);
                     printf("Enter an Element to Insert into set A: ");fflush(stdin);
                     scanf("%d",&elem);
                     if(elem < 8){
                             insertElem(elem,&A);
                     }else{ printf("number not in scope of universal set..."); }
                     break;
              case 3:display(A);
                     printf("Enter an Element to Delete from set A: ");fflush(stdin);
                     scanf("%d",&elem);
                     if(elem < 8){
                             deleteElem(elem,&A);
                     }else{ printf("number not in scope of universal set..."); }
                     break;
              case 4:C=AunionB(A,B);
                     display(C);break;
              case 5:C=AintersectionB(A,B);
                     display(C);break;
              case 6:C=AdifferenceB(A,B);
                     display(C);break;
              default:printf("Incorrect choice.. Please try again");
       }
       getch();
    }while(choice!=0);
    return 0;
}

void displaybitpat(SET A)
{
	int i;
	for(i=(sizeof(char)*8)-1;i>=0;i--){
		if(i==3){
			printf(" ");
		}
		printf("%d",((A>>i)&1));
	}
}

void display(SET A)
{
    int i=0; 
    printf("{");
    for(i=0;i<(sizeof(char)*8);i++){
           if(((A >> i) & 1) == 1){
                printf(" %d",i);  
           }
    }
    printf(" }\n");
}

boolean isMember(int elem,SET A)
{
    return ((A >> elem)&1 == 1)?TRUE:FALSE;
}

void insertElem(int elem,SET *A)
{
    int mask=1 << elem;
    (*A)=(*A)|mask;
}

void deleteElem(int elem,SET *A)
{
     int filter=1 << elem;
     (*A)=(*A) & (~filter);
}

SET AunionB(SET A,SET B)
{
     SET C=0;
     int i,mask;
     for(i=0;i<(sizeof(char)*8);i++){
           if((A >> i)&1 == 1 || (B >> i)&1 == 1){
                 mask=1 << i;
                 C=C|mask;
           }
     }
     return C;
}
SET AintersectionB(SET A,SET B)
{
     SET C=0;
     int i,mask;
     for(i=0;i<(sizeof(char)*8);i++){
           if(((A >> i)&1) == 1 && ((B >> i)&1) == 1){
                 mask=1 << i;
                 C=C|mask;
           }
     }
     return C;
}
SET AdifferenceB(SET A,SET B)
{
     SET C=0;
     int i,mask;
     for(i=0;i<(sizeof(char)*8);i++){      
           if(((A >> i)&1) == 1 && ((B >> i)&1) == 0){
                 mask=1 << i;
                 C=C|mask;
           }
     }
     return C;
}
