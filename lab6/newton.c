#include <stdio.h>
#include <math.h>

int main() {

	int n;
	double x,stepen;

	do {
	printf("Unesite n (prirodni broj) i x (realni broj)\n");
	scanf("%d %lf", &n, &x);
	}
	while ( (n < 0) && ( x <= 0) );
	double x0 = (x + 1) / n, xs;

	int n1 = n - 1;
    do{
		xs = x0;
		stepen = 1;
		for(int j = 0; j<n1; j++){
			stepen *= xs;
		}
		x0 = ((( n1 * xs) + (x/stepen))/n);
		
	}while(fabs(x0 - xs) > 0.0001);
		printf("%lf",x0);
		

	return 0;

}
