#include<stdio.h>
#include<conio.h>
#include<math.h>
#define pi 3.1416

int volume(int radius, int height);

int main(){
    float vol,r,h;
    vol = volume(r,h);
    printf("The Cylinder's Volume is : %.2f",vol);
    getch();
    return 0;
}
int volume(int radius, int height){
    float a;
    printf("Enter The Cylinder's Radius: ");
    scanf("%d",&radius);
    printf("Enter The Cylinder's Height: ");
    scanf("%d",&height);
    a = ((radius*radius)*height*pi);
    return a;
}
