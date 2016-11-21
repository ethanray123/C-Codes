#include <stdio.h>
#include <conio.h>

void restockInventory(int *laptopCount, int newStock);
int buyLaptop(int *laptopCount, int numOfLaptopsToPurchase, float *amtPaid);

int main(void)
{
	int laptopCount = 50, newStock, numOfLaptopsToBuy, stat, choice;
	float money;
	
	do{
		printf("DCIS Computers\n(1)-Sell laptop\n(2)-Restock Inventory\n(3)-Exit\n\nInput choice: ");
		scanf("%d", &choice);system("cls");
		switch (choice){
			case 1: stat = buyLaptop(&laptopCount,numOfLaptopsToBuy,&money);
                    if(stat==1){
                          printf("Purchase was Successful\n\n");
                    }else{
                          printf("Purchase was Unsuccessful\n\n");
                    }break;
			case 2: restockInventory(&laptopCount,newStock);break;
			default: printf("Invalid Choice.\n");
		}
	}while (choice != 3);
	printf("Thank you!\n");
	return 0;
}

void restockInventory(int *laptopCount, int newStock){
     printf("Restock: ");
     scanf("%d",&newStock);
     *laptopCount+=newStock;
     printf("Stock  is now :%d\n\n",*laptopCount);
}
int buyLaptop(int *laptopCount, int numOfLaptopsToPurchase, float *amtPaid){
    float price;
    printf("Enter no. of Laptops to buy: ");
    scanf("%d",&numOfLaptopsToPurchase);
    price = numOfLaptopsToPurchase * 35000;
    if(numOfLaptopsToPurchase<=*laptopCount){
         printf("Total Price: %.2f\nPayment: ",price);
         scanf("%f",&*amtPaid);
         if(*amtPaid >= price){
               *laptopCount-=numOfLaptopsToPurchase;
               return 1;     
         }else{
               return 0;
         }
    }else{
          return 0;
    }
}
