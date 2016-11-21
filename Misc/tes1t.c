#include<stdio.h>
#include<conio.h>
#define MAX 5
void arrDataTransfer(char arr[]);

int main()
{
	int i;
	char arr[100];
	for(i=0;i<MAX;i++){
		arr[i]='a';
	}
	printf("arr before transfer: \n\n");
	for(i=0;i<MAX;i++){
		printf("arr[%d] = %c\n",i,arr[i]);
	}
	arrDataTransfer(arr);
	
	printf("\narr after transfer: \n\n");
	for(i=0;i<MAX;i++){
		printf("arr[%d] = %c\n",i,arr[i]);
	}
	return 0;
}

void arrDataTransfer(char arr[])
{
	int i;
	for(i=0;i<MAX;i++){
		arr[i]='b';
	}
}
