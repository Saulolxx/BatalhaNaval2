#include "game.h"

/**
*	\brief Conta a quantidades de Jogadores dentro do Jogo ( Define se o Jogo será em Dupla ou Individual
*	\param jogadores Vetor de jogadores
*	\return Retorna um int com o valor de quantos jogadores foram inicializados;
*/
int contarJogadores(Jogador jogadores[]){
	int i, c = 0;
	for(i = 0; i < 2; i++){
		if(!jogadores[i].ativo){
			break;
		}
	}	
	return i;
}

/**
*	\brief instancia os jogadores no Jogo
*	\param
*	\return Retorna uma função
*/
void iniciarJogador(Jogador *jogador, Barco barco, char nome[]){
	jogador->acertos = false;
	jogador->ativo	= true;
	jogador->barco	= barco;
	jogador->vida	= 25;
	strcpy(jogador->nome, nome);
	carregarTabuleiro(jogador->tabuleiro);
}

/**
*	\brief Imprimir icone correto no tabuleiro
*	\param cod Código do icone (0 - 2)
*/
void imprimeIcone(int cod){
	switch(cod){
		case VAZIO_S:
			printf("  %c", AGUA);
			break;
		case AGUA_S:
			printf("  %c", T_AGUA);
			break;
		case NAVIO_S:
			printf("  %c", T_NAVIO);
			break;
	}
}

/**
*	\brief Limpa todo tabuleiro setando 0 | VAZIO_S em cada cédula da matriz
*	\param tabuleiro Tabuleiro/Matriz do jogo a ser tratada [IN][OUT]
*	\return Retorna uma função
*/
void carregarTabuleiro(int tabuleiro[][MAX]){
	int i, j;
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			tabuleiro[i][j] = VAZIO_S;
		}
	}
}

/**
*	\brief Imprime o Tabuleiro | Matriz na tela do usuário
*	\param tabuleiro Tabuleiro/Matriz do jogo a ser tratada [IN]
*	\param jogadores Vetor de Jogadores, contendo as informações necessárias sobre cada um [IN]
*	\return Retorna uma função
*/
void imprimeTabuleiro(int tabuleiro[][MAX], Jogador jogadores[]){
	int i, j;
	
	printf("\n\n");	
	if(contarJogadores(jogadores) == 1){
		printf("\t       NOME: %10s               ENERGIA: %2d/25\n", jogadores[0].nome, jogadores[0].vida);
		printf("\t       ---------------------------------------------\n");
		printf("\t         |");
		for (i = 0 ; i < MAX - 1 ; i++) {
			printf("%3d", i+1);
		}
		printf("\n\t       --+------------------------------------------\n");
		for (i = 1 ; i < MAX ; i++) {
			printf("\t       %2d|", i);
			for (j = 1 ; j < MAX ; j++) {
				imprimeIcone(tabuleiro[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("\t       NOME: %10s               ENERGIA: %2d/25", jogadores[0].nome, jogadores[0].vida);
		printf("\t        NOME: %10s               ENERGIA: %2d/25\n", jogadores[1].nome, jogadores[1].vida);		
		printf("\t       ---------------------------------------------");
		printf("            ---------------------------------------------\n");		
		printf("\t         |");
		for (i = 0 ; i < MAX-1 ; i++) {
			printf("%3d", i+1);
		}
		printf("              |");
		for (i = 0 ; i < MAX-1 ; i++) {
			printf("%3d", i+1);
		}		
		printf("\n\t       --+------------------------------------------");
		printf("            --+------------------------------------------\n");		
		for (i = 1 ; i < MAX ; i++) {
			printf("\t       %2d|", i);
			for (j = 1 ; j < MAX ; j++) {
				imprimeIcone(tabuleiro[i][j]);
			}
			printf("         ");
			printf("   %2d|", i);
			for (j = 1 ; j < MAX ; j++) {
				imprimeIcone(tabuleiro[i][j]);
			}
			printf("\n");
		}
	}
}

/**
*	\brief Sorteia a posição dos barcos conforme informado
*	\param tabuleiro Tabuleiro/Matriz do jogo onde será posicionado os barcos
*	\param func	Valor booleano para definir se o sorteio se dará de maneira automática ou manual (true: automatico, false: manuel)
*	\return Retorna uma função
*/
void sorteiaFrota(int tabuleiro[][MAX],Barco barcos, bool func){
	int barco, linha, coluna, direcao = HORIZONTAL, sbarcos, i;
	srand((unsigned)time(NULL));
	sbarcos = (barcos.corveta + barcos.cruzador + barcos.destroyer + barcos.fragata + barcos.porta_avioes + barcos.submarino);
	if(func){
		while(sbarcos > 0){
			barco 	= rand()%6;
			linha 	= rand()%14;
			coluna 	= rand()%14;
			direcao = rand()%2;
			
			if(verificaBarcos(barco, direcao, linha, coluna, tabuleiro)){
				posicionaBarcos(barco, direcao,linha, coluna, tabuleiro);
				sbarcos--;
			}
			
		}
	}
}

/**
*	\brief Verifica se é possível adicionar o navio nas coordenadas indicadas
*	\param barco Número correspondente ao tipo do barco (0-5)
*	\param direcao Número correspondente a direção qual o barco será posicionado ( 0 - Horizontal ; 1 - Vertical )
*	\param linha Número da linha na qual o barco será posicionado
*	\param coluna Número da coluna na qual o barco será posicionado
*	\param tabela Matriz/Tabela que será posicionado os barcos
*	\return Retorna um valor inteiro 1: É possível adicionar o navio, 2: Não é possível adicionar o navio
*/
 int verificaBarcos(int barco, int direcao, int linha, int coluna, int tabela[][MAX]){
 	switch(barco){
 		case CORVET:
 			return verificaCorveta(direcao, linha, coluna, tabela);
 		case CRUZAD:
 			return verificaCruzador(direcao, linha, coluna, tabela);
 		case DESTRO:
 			return verificaDestroyer(direcao, linha, coluna, tabela);
 		case FRAGAT:
 			return verificaFragata(direcao, linha, coluna, tabela);
 		case PORTAA:
 			return verificaPortaAvioes(direcao, linha, coluna, tabela);
 		case SUBMAR:
 			return verificaSubmarino(direcao, linha, coluna, tabela);
	 }
 }
 
 /**
 *	\brief Funções que verificam a posibilidade de instalar o barco nas coordenadas informadas, tendo como critério as peculiaridades de cada barco
 *	\param direcao Direção na qual o barco será intalado (0: Horizontal, 1: Vertical)
 *	\param linha Número da linha na tabela aonde o barco será instalado
 *	\param coluna Número da coluna na tabela onde o barco será instalado
 *	\param tabela Tabela/Matriz onde os barcos serão instalados
 *	\return Retorna um int com o valor 1 para possível instalar o barco e 0 para a falta de possibilidade de instalar o barco
 */
 int verificaCorveta(int direcao, int linha, int coluna, int tabela[][MAX]){
 	int i, j;
 	
 	if(!direcao){
 		for(i = linha; i <= (linha+2); i++){
 			if(i > (MAX-1) || tabela[i][coluna] == NAVIO_S){
 				return 0;
			 }
		 }
	 }else{
	 	for(j = coluna; j <= (coluna+2); j++){
	 		if( j > (MAX-1) || tabela[linha][j] == NAVIO_S){
	 			return 0;
			 }
		 }
	 }
	 
	 return 1;
 }
 
 int verificaCruzador(int direcao, int linha, int coluna, int tabela[][MAX]){
 	int i, j;
 	
 	if(!direcao){
 		for(i = linha; i < (linha+5); i++){
 			if( i > (MAX-1) || tabela[i][coluna] == NAVIO_S){
 				return 0;
			 }
		 }
	 }else{
	 	for(j = coluna; j < (coluna+5); j++){
	 		if( j > (MAX-1) || tabela[linha][j] == NAVIO_S){
	 			return 0;
			 }
		 }
	 }
	 
	 return 1;
 }
 
 int verificaDestroyer(int direcao, int linha, int coluna, int tabela[][MAX]){
 	int i, j;
 	
 	if(!direcao){
 		for(i = linha; i < (linha+4); i++){
 			if( i > (MAX-1) || tabela[i][coluna] == NAVIO_S){
 				return 0;
			 }
		 }
	 }else{
	 	for(j = coluna; j < (coluna+4); j++){
	 		if( j > (MAX-1) || tabela[linha][j] == NAVIO_S){
	 			return 0;
			 }
		 }
	 }
	 
	 return 1;
 }
 
 int verificaFragata(int direcao, int linha, int coluna, int tabela[][MAX]){
 	int i, j;
	for(i = linha; i < (linha+2); i++){
		for(j = coluna; j < (coluna+2); j++){
			if( i > (MAX-1) || tabela[i][j] == NAVIO_S){
				return 0;
		 	}
		 }
	 }
	 return 1;
 }
 
 int verificaPortaAvioes(int direcao, int linha, int coluna, int tabela[][MAX]){
 	int i, j;
 	if(!direcao){
		for(i = linha; i < (linha+2); i++){
			for(j = coluna; j < (coluna+6); j++){
				if( i > (MAX-1) || tabela[i][j] == NAVIO_S){
					return 0;
			 	}
			 }
		 }	
	 }else{
		for(i = linha; i < (linha+6); i++){
			for(j = coluna; j < (coluna+2); j++){
				if( i > (MAX-1) || tabela[i][j] == NAVIO_S){
					return 0;
			 	}
			 }
		 }		 	
	 }
	 return 1;
 }
 
 int verificaSubmarino(int direcao, int linha, int coluna, int tabela[][MAX]){
 	int i, j;
 	
 	if(!direcao){
 		for(i = linha; i <= (linha+3); i++){
 			if(i > (MAX-1) || tabela[i][coluna] == NAVIO_S){
 				return 0;
			 }
		 }
	 }else{
	 	for(j = coluna; j <= (coluna+3); j++){
	 		if( j > (MAX-1) || tabela[linha][j] == NAVIO_S){
	 			return 0;
			 }
		 }
	 }
	 
	 return 1;
 }
 
/**
*	\brief Verifica se é possível adicionar o navio nas coordenadas indicadas
*	\param barco Número correspondente ao tipo do barco (0-5)
*	\param direcao Número correspondente a direção qual o barco será posicionado ( 0 - Horizontal ; 1 - Vertical )
*	\param linha Número da linha na qual o barco será posicionado
*	\param coluna Número da coluna na qual o barco será posicionado
*	\param tabela Matriz/Tabela que será posicionado os barcos
*	\return Retorna um valor inteiro 1: É possível adicionar o navio, 2: Não é possível adicionar o navio
*/
 void posicionaBarcos(int barco, int direcao, int linha, int coluna, int tabela[][MAX]){
 	switch(barco){
 		case CORVET:
 			 posicionaCorveta(direcao, linha, coluna, tabela);
 			 break;
 		case CRUZAD:
 			 posicionaCruzador(direcao, linha, coluna, tabela);
 			 break;
 		case DESTRO:
 			 posicionaDestroyer(direcao, linha, coluna, tabela);
 			 break;
 		case FRAGAT:
 			 posicionaFragata(direcao, linha, coluna, tabela);
 			 break;
 		case PORTAA:
 			 posicionaPortaAvioes(direcao, linha, coluna, tabela);
 			 break;
 		case SUBMAR:
 			 posicionaSubmarino(direcao, linha, coluna, tabela);
 			 break;
	 }
 }
 
 /**
 *	\brief Funções responsável por posicionar os barcos onde desejado.
 *	\param direcao Direção na qual o barco será intalado (0: Horizontal, 1: Vertical)
 *	\param linha Número da linha na tabela aonde o barco será instalado
 *	\param coluna Número da coluna na tabela onde o barco será instalado
 *	\param tabela Tabela/Matriz onde os barcos serão instalados
 *	\return Retorna uma função
 */
void posicionaCorveta(int direcao, int linha, int coluna, int tabela[][MAX]){
	int i, j;
	
	if(!direcao){
		for(i = linha; i <= (linha+2); i++){
			tabela[i][coluna] = NAVIO_S;
		}
	}else{
		for(j = coluna; j <= (coluna+2); j++){
			tabela[linha][j] = NAVIO_S;
		}
	}
}
 
void posicionaCruzador(int direcao, int linha, int coluna, int tabela[][MAX]){
	int i, j;
	
	if(!direcao){
		for(i = linha; i <= (linha+5); i++){
			tabela[i][coluna] = NAVIO_S;
		}
	}else{
		for(j = coluna; j<= (coluna+5); j++){
			tabela[linha][j] = NAVIO_S;
		}
	}
}

void posicionaDestroyer(int direcao, int linha, int coluna, int tabela[][MAX]){
	int i, j;
	
	if(!direcao){
		for(i = linha; i <= (coluna+4); i++){
			tabela[i][coluna] = NAVIO_S;
		}
	}else{
		for(j = coluna; j <= (coluna+4); j++){
			tabela[linha][j] = NAVIO_S;
		}
	}
}
 
void posicionaFragata(int direcao, int linha, int coluna, int tabela[][MAX]){
	int i, j;
	
	for(i = linha; i <= (linha+2); i++){
		for(j = coluna; j <= (coluna+2); j++){
			tabela[i][j] = NAVIO_S;
		}
	}
}

void posicionaPortaAvioes(int direcao, int linha, int coluna, int tabela[][MAX]){
	int i, j;
	
	if(!direcao){
		for(i = linha; i <= (linha+2); i++){
			for(j = coluna; j <= (coluna+6); j++){
				tabela[i][j] = NAVIO_S;
			}
		}
	}else{
		for(i = linha; i <= (linha+6); i++){
			for(j = coluna; j <= (coluna+2); j++){
				tabela[i][j] = NAVIO_S;
			}
		}		
	}
}

void posicionaSubmarino(int direcao, int linha, int coluna, int tabela[][MAX]){
	int i, j;
	
	if(!direcao){
		for(i = linha; i <= (linha+3); i++){
			tabela[i][coluna] = NAVIO_S;
		}
	}else{
		for(j = coluna; j <= (coluna+3); j++){
			tabela[linha][j] = NAVIO_S;
		}
	}
}

