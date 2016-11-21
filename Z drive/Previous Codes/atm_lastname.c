#include<stdio.h>
#include<conio.h>
#include<ctype.h> /*toupper() is found*/
/*
 FUNCTION PROTOTYPES HERE
*/

float Deposit (float balance);
float Withdraw (float balance);
void Inquire (float balance);
void ATM(float balance);


int main(void)
{
	float balance = 500000.00;
	/* FUNCTION CALL OF ATM() */
    ATM(balance);
	getch();
	return balance;
}

/*
  OTHER FUNCTIONS HERE
*/
float Deposit(float balance){
      float depo;
      printf("Amount to be Deposited: ");
      scanf("%f",&depo);
      if(depo > 0){
          balance+=depo;
      }else{
          printf("Invalid Deposit"); 
      }
      return balance;
}
float Withdraw(float balance){
      float with;
      printf("Amount to be Withdrawn: ");
      scanf("%f",&with);
      if(with <= balance && with>=0){
          balance-=with;
      }else{
          printf("Invalid Withdrawal.. ");  
      }
      return balance; 
}
void Inquire(float balance){
      printf("Current Balance is: %.2f",balance);
}


void ATM(float balance)
{
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
		scanf("%c", &choice);
		
		choice = toupper(choice); /*converts character into uppercase*/
		switch(choice){
			case 'D': balance=Deposit(balance);/*FUNCTION CALL OF Deposit()*/
				      break;
			case 'W': balance=Withdraw(balance);/*FUNCTION CALL OF Withdraw()*/
					  break;
			case 'I': Inquire(balance);/*FUNCTION CALL OF Inquire()*/
					  break;
			case 'E': printf("\t\tThank you for banking with us!"); 
			          break;
		}
		getch();
	}while(choice!='E');
	
}
