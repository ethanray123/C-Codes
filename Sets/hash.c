#include<conio.h>
#include<stdio.h>

int hashHundreds(int);
int hashdigit(int);
int hashletter(char*);

int main (){
    int a; char n[10];
    printf("Enter a value to hash(to the Hundred's place): "); fflush(stdin);
    scanf("%d",&a);
    printf("The hash of %d is = %d\n",a,hashHundreds(a));
    
    printf("Enter a value to hash(digit 0 to 19): "); fflush(stdin);
    scanf("%d",&a);
    printf("The hash of %d is = %d\n",a,hashdigit(a));
    
    printf("Enter a value to hash(letter 0 to 49): "); fflush(stdin);
    gets(n);
    printf("The hash of %s is = %d\n",n,hashletter(n));
    getch();
    return 0;
}

int hashHundreds(int x)
{
    return (x % 1000) / 100;
}

int hashdigit(int x)
{
    int sum=0,digit=0;
    while(x%10 != 0){
          digit=x%10;
          printf("digit = %d\n",digit);
          x/=10;
          sum+=digit;
    }
    printf("sum of digits = %d\n",sum);
    return sum % 19;
}

int hashletter(char name[])
{
    int sum=0,letter,i=0;
    while(name[i]!='\0'){
         printf("name[%d] = %d\n",i,name[i]);
         sum+=name[i];
         i++;
    }
    printf("sum of letter values = %d\n",sum); 
    return sum % 49;
}
