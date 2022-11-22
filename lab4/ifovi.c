#include <stdio.h>
#include <math.h>

int main(){
	int a,b,c; float s;
	printf("Unesite stranicu a: ");
	scanf("%d",&a);
	printf("Unesite stranicu b: ");
	scanf("%d",&b);
	printf("Unesite stranicu c: ");
	scanf("%d",&c);

	//ispitivanje velicina stranica
	if((a<b+c)&&(b<a+c)&&(c<a+b))
	{
		if((a==b)&&(b==c)){
			printf("Trougao je jednakostranican\n");
		}else if ((a==b)||(b==c)||(a==c))
			printf("Trougao je jednakokraki\n");
		else printf("Trougao je raznostranican\n");
	}
	else printf("Trougao se ne moze konstruisati\n");
	//ispitivanje ugla
	if((c*c == b*b + a*a)||(b*b == c*c + a*a)||(a*a == b*b + c*c)) printf("Trougao je pravougli\n");
	else printf("Trougao nije pravougli\n");
	//ispis obima i povrsine
	s = (a+b+c)/2.0;
	printf("Povrsina: %.2f\n",sqrt(s*(s-a)*(s-b)*(s-c)));
	printf("Obim: %.2f\n", (float)(a+b+c));
	return 0;
}
