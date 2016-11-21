#include<stdio.h>
#include<conio.h>
#define HEAPSIZE	0XA
int main()
{
    char c[]="Ferrero",d[]="Mars";
    printf("Parent %s\nChild %s\n%d\n",c,d,strcmp(c,d));
    printf("HeapSIZE %d",HEAPSIZE);
    getch();
    return 0;
}
