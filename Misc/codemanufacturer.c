#include<stdio.h>
#include<stdio.h>

int main(void)
{
    int code;
    printf("Input the Code Number: ");
    scanf("%d", &code);
    switch(code)
    {
            case 1:
                 printf("Disk Drive Manufacturer: 3M Corporation");
                 break;
            case 2:
                 printf("Disk Drive Manufacturer: Maxell Corporation");
                 break;
            case 3:
                 printf("Disk Drive Manufacturer: Sony Corporation");
                 break;
            case 4:
                 printf("Disk Drive Manufacturer: Verbatim Corporation");
                 break;
            default:
                    printf("Error: Invalid Code");
    }
    getch();
    return 0;
}
