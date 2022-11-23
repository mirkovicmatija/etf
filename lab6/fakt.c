#include <stdio.h>

int main(){
	int b,n,s=0,br_c = 0;
	scanf("%d",&b);
	n = b; 

	while(n){
		br_c++;
		n /= 10;
	}
	for (int i = 0; i < br_c; i++){
		int fakt = 1;
		for (int j = 1; j <= b% 10 ;j++){
			fakt *= j;
		}
		s += fakt;
		b/=10;
	}
	printf("Suam je:%d",s);
	return 0;
}
