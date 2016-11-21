#include<stdio.h>
#include<conio.h>
#include<ctype.h> /*toupper() is found*/
/*
 FUNCTION PROTOTYPES HERE
*/

void Deposit (float *);
void Withdraw (float *);
void Inquire (float);



int main(void)
{
	float balance = 500000.00;
	char choice;
	do{
		system("CLS");
		printf("\t\tMY ATM\n");
		printf("\t\t------\n");
		printf("\t\tD - Deposit\n");
		printf("\t\tW - Withdraw\n");
		printf("\t\tI - Inquire\n");
		printf("\t\tE - Exit\n");
		
		printf("\n\n\t\tEnter choice: ");
		scanf(" %c", &choice);
		
		choice = toupper(choice); /*converts character into uppercase*/
		switch(choice){
			case 'D': Deposit(&balance);
				      break;
			case 'W': Withdraw(&balance);
					  break;
			case 'I': Inquire(balance);
					  break;
			case 'E': printf("\t\tThank you for banking with us!"); 
			          break;
            default: printf ("\t\tTry another selection.");
		}
		getch();
	}while(choice!='E');
	getch();
	return 0;
}

/*
  OTHER FUNCTIONS HERE
*/
void Deposit (float *balance){
     float amount;
     printf ("Enter the amount to deposit: ");
     scanf ("%f", &amount);
     if (amount<0){
        printf ("Amount unacceptable");      
     }
     else{
        *balance=*balance+amount;    
     }
}

void Withdraw (float *balance){
     float amount;
     printf ("Enter the amount to withdraw: ");
     scanf ("%f", &amount);
     if (amount>=0){
     if (amount<=*balance){
         *balance=*balance-amount;                
     }  
     else {
         printf ("Cannot be withdrawn");
     }
     }
     else{
         printf ("Amount unacceptable");
     }
}

void Inquire(float balance){
     printf ("Your balance is %.2f.", balance);
}

