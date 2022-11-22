#include <stdio.h>

int main(){
	int a,b,sum_a = 1, sum_b = 1;
	printf("Unesite brojeve: ");
	scanf("%d %d",&a,&b);
	for(int i = 2;i <= a/2 ;i++){
		sum_a += (a%i==0)?i:0;
	}	
	for(int i = 2;i <= b/2;i++){
		sum_b += (b%i==0)?i:0;
	}
	printf(((sum_a == b) && (sum_b == a))?"Brojevi su prijateljski":"Brojevi nisu prijateljski");
	return 0;
}
