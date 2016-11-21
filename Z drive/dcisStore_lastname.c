#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void AddItems(int *, int *, int *);
void SellItems(int *, int *, int *);
void UpdatePrice(void);
void ViewInventory(int *, int *, int *);

float totalInventoryValue;
float bPrice, pPrice, idPrice;

int main()
{
	int choice;
	int ballpen = 50, paper = 100, idSling = 20; /*inventory of items*/
	
	do{
		printf("DCIS Store");
		printf("\n\n[1] Add Items");
		printf("\n[2] Sell Items");
		printf("\n[3] Update Price");
		printf("\n[4] View Inventory");
		printf("\n[5] Exit");
		printf("\n\nEnter choice: ");
		fflush(stdin);scanf("%d", &choice);	
		system("cls");
		switch(choice){
			case 1: AddItems(&ballpen, &paper, &sling);break;
			case 2: SellItems(&ballpen, &paper, &sling);break;
			case 3: UpdatePrice(void);break;
			case 4: ViewInventory(&ballpen, &paper, &sling);break;
		}
		getch();
	}while(choice != 5);
}

void AddItems(int *b, int *p, int *s){
     int temp;
     printf("How Many Items to Stock: \n\n");
     printf("Ballpen: ");
     scanf("%d",&temp); *b+=temp;
     printf("Paper: ");
     scanf("%d",&temp); *p+=temp;);
     printf("ID sling: ");
     scanf("%d",&temp); *s+=temp;);
     
}

void SellItems(int *b, int *p, int *s){
     int temp;
     printf("How Many Items to Stock: \n\n");
     printf("Ballpen: ");
     scanf("%d",&temp); *b-=temp;
     printf("Paper: ");
     scanf("%d",&temp); *p-=temp;);
     printf("ID sling: ");
     scanf("%d",&temp); *s-=temp;);
}

void UpdatePrice(){
     char choice;
     printf("Enter Choice: ");
     scanf("%d", &choice)
}

void
