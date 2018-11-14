#include "game.h"


void escreverTexto(char texto[]){
	int i;
	_setcursortype(1);
	for(i = 0; i < strlen(texto); i++){
		printf("%c", texto[i]);
		delay(30);
	}
}

void escreverTextoColorido(char texto[], int color){
	int i;
	_setcursortype(1);
	for(i = 0; i < strlen(texto); i++){
		colorChar(texto[i], color);
		delay(30);
	}
}

void colorChar(char c, int color){
	textcolor(color);
	putchar(c);
	textcolor(LIGHTGRAY);
}

void colorText(char text[], int color){
	textcolor(color);
	printf("%s", text);
	textcolor(LIGHTGRAY);
}

void logo(){
printf("\t\t\t ______                  _ _              ______                   _ \n");
printf("\t\t\t(____  \\       _        | | |            |  ___ \\                 | |\n");
printf("\t\t\t ____)  ) ____| |_  ____| | | _   ____   | |   | | ____ _   _ ____| |\n");
printf("\t\t\t|  __  ( / _  |  _)/ _  | | || \\ / _  |  | |   | |/ _  | | | / _  | |\n");
printf("\t\t\t| |__)  | ( | | |_( ( | | | | | ( ( | |  | |   | ( ( | |\\ V ( ( | | |\n");
printf("\t\t\t|______/ \\_||_|\\___)_||_|_|_| |_|\\_||_|  |_|   |_|\\_||_| \\_/ \\_||_|_|\n");
colorText("\t\t\t\t Créditos: Adinair, Filipe, João Comunista, Marcola, Saulo Lins", GREEN);
printf("\n\n");
}

void imprimirSeta(){
	textcolor(YELLOW);
	putchar('>');
	textcolor(LIGHTGRAY);
}

int menuInicial(){
	
	int tecla, y = 14, level,x, z;
	
	clrscr();
	logo();
	printf("\n\n");
	printf("\t\t\t\t\t       --------------------------------\n");
	printf("\t\t\t\t\t       |        MENU PRINCIPAL        |\n");
    printf("\t\t\t\t\t       --------------------------------\n");
    printf("\t\t\t\t\t       |     1 JOGAGOR                |\n");
    printf("\t\t\t\t\t       |     2 JOGAGORES              |\n");
    printf("\t\t\t\t\t       |     INSTRUÇÕES DO JOGO       |\n");
    printf("\t\t\t\t\t       |     RANKING                  |\n");
    printf("\t\t\t\t\t       |     ");
    colorText("SAIR", LIGHTRED);
    printf("                     |\n");
    printf("\t\t\t\t\t       --------------------------------\n\n\n");
	gotoxy(52,14);
	imprimirSeta();
	do{
		_setcursortype(0);
		tecla = getch();
		
		switch(tecla){
			case BAIXO:
				gotoxy(52, y);
				putchar(' ');
				
				if(y == 18){
					y = 14;
				}else{
					y++;
				}
				
				gotoxy(52,y);
				imprimirSeta();
				break;
			
			case CIMA:
				gotoxy(52,y);
				putchar(' ');
				
				if(y == 14){
					y = 18;
				}else{
					y--;
				}
				
				gotoxy(52,y);
				imprimirSeta();
				break;
			
			case ENTER:
				switch(y){
					case 14:
						return INDIVIDUAL;
						break;
					case 15:
						return DUPLA;
						break;
					case 16:
						return INST;
						break;
					case 17:
						return RANK;
						break;
					case 18:
						return SAIR;
						break;
				}
				break;
			case ESC:
				return SAIR;
				break;
		}
	}while(1<2);
}

int menuNivel(){
	
	int tecla, x = 39;
	
	clrscr();
	logo();
	gotoxy(40,15);
	escreverTextoColorido("Fácil", LIGHTGREEN);
	gotoxy(55,15);
	escreverTexto("Normal");
	gotoxy(70,15);
	escreverTextoColorido("Difícil", LIGHTRED);
	gotoxy(39,15);
	imprimirSeta();
	
	do{
		_setcursortype(0);
		tecla = getch();
		
		switch(tecla){
			case ESQUERDA:
				gotoxy(x, 15);
				putchar(' ');
				
				if(x <= 39){
					x = 69;
				}else{
					x-=15;
				}
				
				gotoxy(x, 15);
				imprimirSeta();
				break;
				
			case DIREITA:
				gotoxy(x, 15);
				putchar(' ');
				
				if(x >= 69){
					x = 39;
				}else{
					x+=15;
				}
				
				gotoxy(x, 15);
				imprimirSeta();
				break;
				
			case ENTER:
				switch(x){
					case 39:
						return FACIL;
						break;
					case 54:
						return NORMAL;
						break;
					case 69:
						return DIFICIL;
						break;
				}
				break;
			
			case ESC:
				return SAIR;
				break;
		}
	}while(1<2);
}

int menuTipo(){
		
	int tecla, x = 44;
	
	clrscr();
	logo();
	gotoxy(45,15);
	escreverTextoColorido("Manual", LIGHTGREEN);
	gotoxy(65,15);
	escreverTextoColorido("Automático", LIGHTRED);
	gotoxy(44,15);
	imprimirSeta();
	
	do{
		_setcursortype(0);
		tecla = getch();
		
		switch(tecla){
			case ESQUERDA:
				gotoxy(x, 15);
				putchar(' ');
				
				if(x <= 44){
					x = 64;
				}else{
					x-=20;
				}
				
				gotoxy(x, 15);
				imprimirSeta();
				break;
				
			case DIREITA:
				gotoxy(x, 15);
				putchar(' ');
				if(x >= 64){
					x = 44;
				}else{
					x+=20;
				}
				
				gotoxy(x, 15);
				imprimirSeta();
				break;
				
			case ENTER:
				switch(x){
					case 44:
						return MANUAL;
						break;
					case 64:
						return AUTOMATICO;
						break;
				}
				break;
			case ESC:
				return SAIR;
				break;
		}
	}while(1<2);
}
