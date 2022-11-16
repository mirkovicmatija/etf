#include <stdio.h>

int main(){
	int broj, s = 0;
	printf("Unsite cifru: ");
	scanf("%d", &broj);
	while(broj != 0){
	s += broj % 10;
	broj /= 10;
	}
	printf("Suma cifara je: %d",s);
	return 0;
}
