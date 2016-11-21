#include <stdio.h>
#include <conio.h>
#define N 5

void input (int a[], int size); 
float average (int a[], int size); 
int min (int a[], int size); 
int retrieve (int pos, int a[], int size); 
int retrieve_last (int a[], int size); 
int retrieve_first (int a[]); 
int search (int X, int a[], int size);
void displayAll (int a[], int size); 

int main(void)
{
	int a[N], i; 
	int choice;
	int num;
	do{
		system("cls");
		printf("MENU\n");
		printf("----\n\n");
		printf("1 - input\n");
		printf("2 - average\n");
		printf("3 - minimum\n");
		printf("4 - retrieve number given index\n");
		printf("5 - last number in the list\n");
		printf("6 - first number in the list\n");
		printf("7 - search number\n");
		printf("8 - display list\n");
		printf("9 - exit\n\n");
		printf("Enter choice: ");		
		scanf("%d", &choice);
		system("cls");
		switch(choice)	{
			case 1: input(a,N); break;
			case 2: printf("\nAverage: %.2f", average(a,N)); break;
			case 3: printf("\nSmallest Number in the list: %d", min(a,N)); break;
			case 4: printf("\nEnter position: "); scanf("%d",&num);
					printf("\n\nNumber: %d", retrieve(num,a,N)); break;
			case 5: printf("\nLast Number in the list: %d", retrieve_last(a,N)); break;
			case 6: printf("\nFirst Number in the list: %d", retrieve_first(a)); break;
			case 7: printf("\nSearch Number: "); scanf("%d",&num);
					printf("\n\nFound in index: %d", search (num, a, N)); break;
			case 8: displayAll(a,N); break;
		}
		getch();
		
	} while (choice!= 9);
	getch();
	return 0;	
}

int search (int X, int a[], int size)
{
    int i;
    for(i=0;i<size;i++){
       if(a[i]==X){
        return i;
       }
    }return -1;
}

void input (int a[], int size)
{
    int i;
    for(i=0;i<size;i++){
       printf("Enter a[%d]: ",i);
       scanf("%d",&a[i]);
    }
}

float average (int a[], int size)
{
    int i, sum=0;
    for(i=0;i<size;i++){
       sum+=a[i];
    }
    return (float)sum/size; /*Type Casting*/
}

int min (int a[], int size)
{
    int i, min=a[0];
    for(i=1;i<size;i++){
       if(a[i] < min){
           min = a[i];
       }
    } return min;
} 



int retrieve (int pos,int a[],int size)
{
    if(pos >= 0 && pos < size){
           return a[pos];
    }
    return -1;
}


int retrieve_last (int a[], int size)
{
    return a[size-1];
}

int retrieve_first (int a[])
{
    return a[0];
}

void displayAll (int a[], int size)
{
    int i;
    for(i=0;i<size;i++){
       printf("\na[%d] = %d ",i,a[i]);
    }
}
