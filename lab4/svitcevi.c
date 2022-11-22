#include <stdio.h>

int main(){
	int m, g;
	printf("unesite mjesec i godinu: ");
	scanf("%d %d",&m, &g);
	switch(m){
	case 1:
		printf("Mjesec JANUAR %d. godine ima 31 dana", g);
		break;
	case 2:
		printf("Mjesec FEBRUAR %d. godine ima %d dana", g ,((g%400==0)||(g%4==0 && g%100!=0))?29:28);
		break;
	case 3:
		printf("Mjesec MART %d. godine ima 31 dana", g);
		break;
	case 4:
		printf("Mjesec APRIL %d. godine ima 30 dana", g);
		break;
	case 5:
		printf("Mjesec MAJ %d. godine ima 31 dana", g);
		break;
	case 6:
		printf("Mjesec JUN %d. godine ima 30 dana", g);
		break;
	case 7:
		printf("Mjesec JUL %d. godine ima 31 dana", g);
		break;
	case 8:
		printf("Mjesec AVGUST %d. godine ima 31 dana", g);
		break;
	case 9:
		printf("Mjesec SEPTEMBAR %d. godine ima 30 dana", g);
		break;
	case 10:
		printf("Mjesec OKTOBAR %d. godine ima 31 dana", g);
		break;
	case 11:
		printf("Mjesec NOVEMBAR %d. godine ima 30 dana", g);
		break;
	case 12:
		printf("Mjesec DECEMBAR %d. godine ima 31 dana", g);
		break;
	default:
		printf("Greska");
	}
	return 0;
}
