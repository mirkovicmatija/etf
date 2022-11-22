#include <stdio.h>

int main(){
	int n,k = 0,u,i = 0;
	scanf("%d",&n);
	do{
	printf("--> ");
	scanf("%d",&u);
	k += (u < 1)? 0 : 1;
	i++;
	} while(i<n);
	printf("Ukupni ima %d pozitivnih brojeva", k);
	return 0;
}

