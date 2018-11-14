#include "game.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "portuguese");
	// 9 , 8, 8
	Barco barco = {3, 1, 1, 1, 1, 2};
	int tabuleiro[MAX][MAX];
	Jogador j1[2], j2;
	
	printf("Nome do Jogador 01: %s \n", j1[0].nome);
	iniciarJogador(&j1[0], barco, "Saulo Lins");
	//iniciarJogador(&j1[1], barco, "Saulo Lins");
	printf("Nome do Jogador 01: %s \n", j1[0].nome);
	printf("Numero de Jogadores registrados: %d\n\n", contarJogadores(j1));
	carregarTabuleiro(tabuleiro);
	imprimeTabuleiro(tabuleiro, j1);
	sorteiaFrota(tabuleiro, barco, true);
	imprimeTabuleiro(tabuleiro, j1);	
	//carregarTabuleiro(tabuleiro);
	//iniciaJogador(&j1, barco, "Testando");
	//imprimeTabuleiroS(tabuleiro, j1);
	
	
	system("pause");
	/*do{				
		switch(menuInicial()){
			case INDIVIDUAL:								
				switch(menuNivel()){
					case FACIL:
						//Carregar Tabela
						clrscr();
						carregarTabuleiro(tabuleiro);
						iniciaJogador(&j1, barco, "Jogador 1");
						iniciaJogador(&j2, barco, "Máquina");
						imprimeTabuleiro(tabuleiro, j1, j2);

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
	}while(1<2);*/
	return 0;
}
