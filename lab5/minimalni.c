#include <stdio.h>

int main(){
	int n, min = n, u, i=0;
	scanf("%d",&n);
	do{
	printf("--> ");
	scanf("%d",&u);
	min = (u < min)? u : min;
	i++;
	} while(i<n);
	printf("Najmanj broj je %d.", min);
	return 0;
}

