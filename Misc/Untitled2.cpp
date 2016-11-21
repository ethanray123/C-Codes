#include<stdio.h>

int b[5];

int callThis(int num) {
	return num - b[4]++;
}

int main(void){
	int a[10] = { 7, 5, -1, 3, 0, 6 };
	int *ptr = &b[3];
	
	printf("\n%d %d", b[3], *ptr);
	
	a[9] = b[0] = callThis( a[ a[1] ] );
	printf("\nbefore: %d %d", b[0], a[9] *2 );
	
	*ptr = callThis( a[9] ) + a[1];
	printf("\nafter: %d %d", b[3], a[ ptr[-3] ] - a[1]);
	return 0;
}
