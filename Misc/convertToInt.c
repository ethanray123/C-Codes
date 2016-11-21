#include<stdio.h>
#include<conio.h>
#include<string.h>

int convertToInt(int num[],int size);
int main()
{
    int nums[]={1,2,5,9,1}, number=0,s;
    s=5;
    number=convertToInt(nums,s);
    printf("\nThe number is %d",number);
    getch();
    return 0;
}

int convertToInt(int num[], int size)
{
    int i,x,val=0;
    for(i=size-1,x=1;i>=0;i--,x*=10){
           val+=num[i]*x;
           printf("%d\n",val);
    }
    return val;
}
