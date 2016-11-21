#include<stdio.h>
#include<conio.h>

typedef char SET;
typedef enum{TRUE,FALSE}boolean;
void insert(SET *,int);
void del(SET *,int);
void displaybitpat(SET);
void displayelems(SET);
boolean find(SET,int);
int main()
{
	SET A = 0;
	insert(&A,4);
	insert(&A,5);
	insert(&A,6);
	insert(&A,0);
	displaybitpat(A);
	displayelems(A);
	printf("\n\nthen the value of A is %d",A);
	getch();
	system("cls");
	del(&A,6);
	displaybitpat(A);
	displayelems(A);
	printf("\n\nthen the value of A is %d",A);
	getch();
	system("cls");
	boolean b; int a=5;
	b=find(A,a);
	if(b==TRUE){
		printf("Elem %d exists",a);
	}else{
		printf("Elem %d doesn't exist",a);
	}
	getch();
	
	return 0;
}

void insert(SET *A,int elem)
{
	char mask = 1<<elem;
	(*A) = (*A)|mask;
}

void del(SET *A,int elem)
{
	char mask = 1<<elem;
	(*A) = (*A)&(~mask);
}

boolean find(SET A,int elem)
{
	return ((A>>elem&1)==1)?TRUE:FALSE;
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

void displayelems(SET A)
{
	int i;
	printf("\n\nSET A = { ");
	for(i=0;i<(sizeof(char)*8);i++){	
		if(((A>>i)&1)==1)
			printf("%d ",i);
	} printf("}");
}
