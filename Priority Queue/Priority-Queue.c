#include<stdio.h>
#include<string.h>
#include<conio.h>
#define SIZE 15
typedef struct{
	int elem[SIZE];
	int last;
}PQ;

void initialize(PQ *P);
void insertMin(PQ *P,int x);
void insert(PQ *P,int x);
void heapifyMin(PQ *P);
void heapSortMax(PQ *P);
int deletemin(PQ *P);
void display(PQ P);

int main()
{
	PQ A;
	int x,y,z;
	
	initialize(&A);
	scanf("%d",&x);
	for(y = 0;y < x;y++){
		printf("Element no.%d: ",y+1);
		fflush(stdin); scanf("%d",&z);
		insert(&A,z);
	}
	display(A);
	heapifyMin(&A);
	display(A);
	heapSortMax(&A);
	display(A);
	getch();
	return 0;
}
void initialize(PQ *P)
{
	P->last = -1;
}
void insertMin(PQ *P,int x)
{
	int cPos,pPos; 
	if(P->last < SIZE-1){
		cPos = ++P->last;
		P->elem[cPos] = x;
		for(pPos = (cPos-1)/2;pPos >= 0 && P->elem[cPos] < P->elem[pPos];){
			P->elem[cPos] = P->elem[pPos];
			P->elem[pPos] = x;
			cPos = pPos;
			pPos = (cPos-1)/2;
		}
	}
}
void insert(PQ *P,int x)
{
	if(P->last != SIZE-1){
		P->elem[++P->last] = x;
	}
}
void heapifyMin(PQ *P)
{
	int tree,pPos,LC,RC,tempPos,top;
	for(tree = (P->last-1)/2; tree >= 0;tree--){
		pPos = tree;
		top = P->elem[pPos];
		for(LC = (pPos*2)+1,RC = LC+1;LC < P->last && (top > P->elem[LC] ||
			(RC > P->last || top >  P->elem[RC]));){
				tempPos = (RC > P->last || P->elem[LC] < P->elem[RC])?LC:RC;
				P->elem[pPos] = P->elem[tempPos];
				P->elem[tempPos] = top;
				pPos = tempPos;
				LC = (pPos*2)+1;
				RC = LC+1;
			}
	}
}
int deletemin(PQ *P)
{
	int retVal,pPos,LC,RC,tempPos,newMin;
	retVal = P->elem[0];
	if(P->last > 0){
		newMin = P->elem[0] = P->elem[P->last--];
		pPos = 0;
		for(LC = 1,RC = 2;LC <= P->last && (newMin > P->elem[LC] || (RC > P->last || newMin >  P->elem[RC]));){
				tempPos = (RC > P->last || P->elem[LC] < P->elem[RC])?LC:RC;
				P->elem[pPos] = P->elem[tempPos];
				P->elem[tempPos] = newMin;
				pPos = tempPos;
				LC = (pPos*2)+1;
				RC = LC+1;
			}
	}else if (P->last == 0){
		P->last--;
	}	
	return retVal;
}
void heapSortMax(PQ *P)
{
	int oldLast,x;
	oldLast = P->last;
	for(x = 0;x < oldLast;x++){
		P->elem[oldLast-x] = deletemin(P);
	}
	P->last = oldLast;
}
void display(PQ P)
{
	int x;
	for(x = 0;x < P.last;x++){
		printf("%d - ",P.elem[x]);
	}
		printf("%d ",P.elem[x]);
		printf("\n");
}
