#include<stdio.h>
#include<conio.h>

int main(void)
{
   int data1[] = { 100, 2, 1, 43, 7};
   int *ptr1, *ptr2, data2,i=0;
   
   ptr1 = data1;
   *(ptr1+2) = 5;
   ptr2 = &data2;
   data2 = *(data1 + 2);
   ptr2 = &data1[2];
   
   printf("ptr1 = %d\n",ptr1);
   printf("*(ptr1+1) = %d\n",*(ptr1+1));
   
   printf("ptr2[-1] = %d\n",ptr2[-1]);
   printf("*ptr2 = %d\n",*ptr2);
   printf("*data1 = %d\n",*data1);
   printf("*(data1+1) = %d\n",*(data1+1));
   
   printf("\n%d = ptr2[-1]\n",ptr2[-1]);
   printf("%d = *(data1 + *(data1+1))\n",*(data1 + *(data1+1)));
   printf("%d = both added by each other and by 9 \n\n\n\n-------------------------\n ", ptr2[-1] + *(data1 + *(data1+1)) + 9);
   for(i=0;i<5;i++){
       printf("%d  ",data1[i]);              
   }
   printf("\nValues in array - data1[]");
   getch();
   return 0;
}
