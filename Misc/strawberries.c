#include<stdio.h>
#include<conio.h>

int straw(int ns, int tlp);

int main(){
    int a,b,s;
    s = straw(a, b);
    printf("The Number of Strawberries per Student is: %d",s);
    getch();
    return 0;
}
int straw(int ns, int tlp){
    int sb;float x;
    printf("How many Students are there?: ");
    scanf("%d",&ns);
    printf("What is the Total weight(in Pounds) of the Strawberries?: ");
    scanf("%d",&tlp);
    x = tlp*16;
    x = x*0.50;
    sb = x/ns;
    return sb;
}
