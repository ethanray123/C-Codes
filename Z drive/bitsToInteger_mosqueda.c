#include<stdio.h>
#include<conio.h>
#include<math.h>

void displayBitPattern(int val, int bits[]);
int convertToDecimal(int bits[]);

int main(){
    int val;
    int bits[8]={0,0,1,1,0,1,1,0};
    val=convertToDecimal(bits);
    displayBitPattern(val,bits);
    getch();
    return 0;
}

void displayBitPattern(int val, int bits[]){
     int i;
     printf("This Bit Pattern: ");
     for(i=0;i<8;i++){
          printf("%d",bits[i]);            
     }
     printf("\n\nis Equivalent to: %d", val);
}

int convertToDecimal(int bits[]){
     int i, pv, sum=0;
     for(i=0, pv=128; i<8; i++, pv/=2){
          sum+=bits[i]*pv;
     }
     return sum;                
}
