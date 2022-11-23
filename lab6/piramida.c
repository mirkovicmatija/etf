#include <stdio.h>

int main(){
		int b ;
		do{
		scanf("%d",&b);
		}while( b > 31 || b < 1 );
		
		int j;
		for(int i = 0; i < b; i++){
		
				for( j = 1; j < b - i; j++ )
						printf(" ");
				for( j = 1; j <= i; j++ )
					printf("%d", j % 10);
				for (j = i + 1 ; j > 0; j--  )
					printf("%d", j % 10);

				printf("\n");
		}
		return 0;
}

