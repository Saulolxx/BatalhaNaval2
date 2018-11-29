#include "game.h"

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
	Barco barco = {3, 1, 1, 1, 1, 2};
	int tab1[MAX][MAX], tab2[MAX][MAX];
	printf("%d", MAX);
	Jogador j1[2], j2;
	
	// Inicia Tabelas
	carregarTabuleiro(tab1);
	carregarTabuleiro(tab2);
	
	//Iniciar Jogadores
	iniciarJogador(&j1[0], barco, "Saulo Lins");
	iniciarJogador(&j1[1], barco, "Computador");
	
	//sortear as Frotas
	sorteiaFrota(j1[0].navio, barco, true);
	sorteiaFrota(j1[1].navio, barco, true);
	
	imprimeTabuleiro(tab1, j1);
	iniciaJogo(j1);
	
	system("pause");
	do{				
		switch(menuInicial()){
			case INDIVIDUAL:								
				switch(menuNivel()){
					case FACIL:
						//Carregar Tabela
						clrscr();
						carregarTabuleiro(tab1);
						iniciarJogador(&j1[0], barco, "Jogador 1");
						iniciarJogador(&j1[1], barco, "Máquina");
						//imprimeTabuleiro(tabuleiro, j1, j2);

						//Sortear os Barcos
						
						//Iniciar o Jogo
					
						system("pause");
						break;
					
					case NORMAL:
						system("cls");
						printf("Estou no modo Normal\n");
						system("pause");						
						break;
					
					case DIFICIL:
						system("cls");
						printf("Estou no modo Difícil\n");
						system("pause");
						break;
					
				}
				break;
				
			case DUPLA:
				switch(menuTipo()){
					case MANUAL:
						system("cls");
						printf("Estou no modo Manual\n");
						system("pause");
						break;
					
					case AUTOMATICO:
						system("cls");
						printf("Estou no modo Automatico\n");
						system("pause");						
						break;
					
				}
				break;
			
		
			case RANK:
				clrscr();
				printf("Estou no modo Rank\n");
				system("pause");
				break;
			
			case INST:
				clrscr();
				printf("Estou no modo Instruçao\n");
				system("pause");
				break;
			
			case SAIR:
				clrscr();
				exit(0);
				break;
			
		}
	}while(1<2);
	return 0;
}
