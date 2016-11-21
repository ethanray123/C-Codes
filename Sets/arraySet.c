#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 5
typedef int* Set;
//prototypes here
Set unionS(Set A,Set B,int *as);
Set intersectionS(Set A,Set B,int *as);
Set differenceS(Set A, Set B,int *as);

int main()
{
	int i,j,v,arrsize;
	Set A,B,C; int vals[10] = {1,3,2,4,3,5,4,6,5,7};
	A=(Set)malloc(sizeof(int)*5);
	B=(Set)malloc(sizeof(int)*5);
	for(i=j=v=0;v<10;v++){
		if(v%2==0){
			A[i]=vals[v];	
			printf("A[%d] = %d",i,A[i++]);
		}else{
			B[j]=vals[v];
			printf("\tB[%d] = %d\n",j,B[j++]);
		}
	}
	C=unionS(A,B,&arrsize); printf("\n   A Union B\n\n");
	for(i=0;i<arrsize;i++){
		printf("C[%d] = %d\n",i,C[i]);
	}
	C=intersectionS(A,B,&arrsize); printf("\n   A Intersection B\n\n");
	for(i=0;i<arrsize;i++){
		printf("C[%d] = %d\n",i,C[i]);
	}
	C=differenceS(A,B,&arrsize); printf("\n   A Minus B\n\n");
	for(i=0;i<arrsize;i++){
		printf("C[%d] = %d\n",i,C[i]);
	}
	free(C); C=NULL;
	return 0;
}

Set unionS(Set A,Set B,int *as)
{
	int i,x,y;
	Set C;
	C=(Set)malloc(sizeof(int));
	for(i=x=y=0;x!=SIZE && y!=SIZE;){
		C=(Set)realloc(C,sizeof(int)*i+1);
		if(A[x]==B[y]){
			C[i++]=A[x++];
			y++;
		}else if(A[x]<B[y]){
			C[i++]=A[x++];
		}else{
			C[i++]=B[y++];
		}
	}
	if(x==SIZE){
		while(y!=SIZE){
			C=(Set)realloc(C,sizeof(int)*i+1);
			C[i++]=B[y++];
		}
	}else{
		while(x!=SIZE){
			C=(Set)realloc(C,sizeof(int)*i+1);
			C[i++]=A[x++];
		}
	}
	(*as)=i;
	return C;
}

Set intersectionS(Set A,Set B,int *as)
{
	Set C;
	C=(Set)malloc(sizeof(int));
	int i,j,k;
	for(i=j=k=0;j!=SIZE && k!=SIZE;){
		C=(Set)realloc(C,sizeof(int)*i+1);
		if(A[j]<B[k]){
			j++;
		}else if(A[j]>B[k]){
			k++;
		}else{
			C[i++]=A[j++];k++;
		}
	}
	(*as)=i;
	return C;
}

Set differenceS(Set A, Set B,int *as)
{
	Set C;
	int i,a,b;
	C=(Set)malloc(sizeof(int));
	for(i=a=b=0;a!=SIZE && b!=SIZE;){
		C=(Set)realloc(C,sizeof(int)*i+1);
		if(A[a] < B[b]){
			C[i++]=A[a++];
		}else if(A[a] > B[b]){
			b++;
		}else{
			a++;
			b++;
		}
	}
	if(b==SIZE){
		while(a!=SIZE){
			C=(Set)realloc(C,sizeof(int)*i+1);
			C[i++]=A[a++];
		}
	}
	(*as)=i;
	return C;
}
