#include <stdio.h>

int main(){
	int a, b, nzs = 1, i = 2;
	printf("Unesite dvije cifre: ");
	scanf("%d %d", &a,&b);
	while(a != 1 || b != 1){
		if (a%i==0 || b%i==0){
			nzs *= i;
			a /= (a%i==0)? i:1;
			b /= (b%i==0)? i:1;
		}else i++;
	}
	printf("NZS je: %d", nzs);
	return 0;
}
