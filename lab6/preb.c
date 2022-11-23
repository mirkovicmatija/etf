#include <stdio.h>

int main(){
	int b, n, s=0, br_c = 0;
	scanf("%d",&b);
	n = b; 

	while(n){
		br_c++;
		n /= 10;
	}

	for(int i = 1; i <= br_c;i++){
		int p = 1;	
		for(int j = 0;j < i;j++){
			p *= b%10; 
		}
		s += p;
		b/=10;
	}
	printf("%d",s);
	return 0;
}

