#include <windows.h>
#include <stdio.h>
#include <string.h>

int main(){

char nome[]="que beleza, dona teresa";
int i;

	for( i = 0; i < strlen(nome); i++){
		printf("%c", nome[i]);
		Sleep(50);
	}
}
