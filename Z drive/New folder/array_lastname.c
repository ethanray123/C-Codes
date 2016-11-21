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
			case 1: ____________________; break;
			case 2: printf("\nAverage: %.2f", ____________________; break;
			case 3: printf("\nSmallest Number in the list: %d", ____________________)); break;
			case 4: printf("\nEnter position: "); scanf("%d",&num);
					printf("\n\nNumber: %d", ____________________); break;
			case 5: printf("\nLast Number in the list: %d", ____________________); break;
			case 6: printf("\nFirst Number in the list: %d", ____________________); break;
			case 7: printf("\nSearch Number: "); scanf("%d",&num);
					printf("\n\nFound in index: %d", ____________________); break;
			case 8: ____________________; break;
		}
		getch();
		
	} while (____________________);
	getch();
	return 0;	
}


//function 1
void input (int a[], int size){
     int i;
     for(i=0;i<size;i++){
         printf("Enter a[%d]: ",i);
         scanf("%d",&a[i]);
     }
}
//function 2
float average (int a[], int size){
      int i;
      float ave;
      for(i=0;i<size;i++){
         ave+=a[i];
      }
      ave=ave/size;
      return ave;
}
//function 3
int min (int a[], int size){
      int i, small=a[0];
      for(i=0;i<size;i++){
         if(a[i]<small){
             small=a[i]; 
         }
      }
      return small;
}
//function 4
int retrieve (int pos,int a[],int size){
    if(pos >= 0 && pos < size){
           return a[pos];
    }
    return -1;
}
/*where pos is the index of the element to be retrieved and size is the size of a[]*/ 
//function 5
int retrieve_last (int a[], int size){
    return a[size-1];
} 
//function 7
int search (int X, int a[], int size){
    int i;
    for(i=0;i<size;i++){
        if(a[i]==x){
           return 1;
        }  
    }return -1;
} 
//function 6
int retrieve_first (int a[]){
    return a[0];
}
//function 8
void displayAll (int a[], int size){
    int i;
    for(i=0;i<size;i++){
         if(a[i]<small){
             small=a[i]; 
         }
      } 
}
/*where size is the size of a[]*/ 





