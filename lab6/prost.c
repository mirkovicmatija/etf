#include <stdio.h>

int main(){
	int broj, k = 0, prost = 1;
	printf("n=");
	scanf("%d",&broj);
	while(prost){
		broj++;
		for(int i = 2;i <= (broj/2);i++){
			k += broj % i ? 0 : 1;
		}
		if(!k){
			printf("Trazeni broj je: %d",broj);
			prost = 0;
		}
	}
	return 0;
}
