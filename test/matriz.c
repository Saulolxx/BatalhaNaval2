#include <stdlib.h>
#include <stdio.h>
void imprimirTabela(int matriz[][]){
	
	printf
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			
		}
	}
}

int main(void){
	int matriz[10][10];
	int i, j;
	
	printf("Testando");
	
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			matriz[i][j] = 0;
		}
	}
	printf("\n");
	printf("   A B C D E F G H I J\n");
	printf("   -------------------");
	printf("\n");
	for(i=0; i<10; i++){
		printf("%d |", i);
		for(j=0; j<10; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
