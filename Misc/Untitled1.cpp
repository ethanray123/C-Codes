#include<stdio.h>
#include<conio.h>
#define SIZE 5
int main(){
	int array1[SIZE], i;
	for(i=0;i<SIZE;i++){
		printf("Enter a value for Array[%d] ",i);
		scanf("%d",&array1[i]);
	}
	for(i=0;i<SIZE;i++){
		printf("\nArray1[%d] = %d\n",i,array1[i]);
	}
	getch();
	return 0;
}
