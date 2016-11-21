#include<stdio.h>
#include<conio.h>
/*FUNCTION PROTOTYPES HERE*/
int inputNum(void);
int ifBingoNum(int);
char getBingoLetter(int num);

int main(void)
{
   int val, ret;
   val = inputNum(); /*function call to inputNum()*/
   ret = ifBingoNum(val); /*function call to ifBingoNum()*/
   if(ret == 0){
      printf("%c", getBingoLetter(val)); /*function call to getBingoLetter */
   }else{
      printf("Not a BINGO NUMBER");
   }
   
   getch();
   return 0;
}

/*user-defined functions*/
int inputNum(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    return num;
}
int ifBingoNum(int val)
{
   if( val > 0 && val <= 75 ){
      return 0;
   }else{
      return 1;
   }
}
char getBingoLetter(int num)
{
   char val;
   if(num > 60){
	val = 'O';
   }else if(num >= 46 && num <= 60){
	val = 'G';
   }else if(num >= 31 && num <= 45){
	val = 'N';
   }else if(num >= 16 && num <= 30){
	val = 'I';
   }else{
	val = 'B';
   }
   return val;
}

