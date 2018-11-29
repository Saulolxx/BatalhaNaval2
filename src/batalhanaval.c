#include "game.h"

/**
*	\brief Conta a quantidades de Jogadores dentro do Jogo ( Define se o Jogo ser� em Dupla ou Individual
*	\param jogadores Vetor de jogadores
*	\return Retorna um int com o valor de quantos jogadores foram inicializados;
*/
int contaJogador(Jogador jogadores[]){
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
*	\return Retorna uma fun��o
*/
void iniciarJogador(Jogador *jogador, Barco barco, char nome[]){
	jogador->acertos = false;
	jogador->ativo	= true;
	jogador->navios_qtd	= barco;
	jogador->vida	= 25;
	strcpy(jogador->nome, nome);
	carregarTabuleiro(jogador->navio);
}

/**
*	\brief Imprimir icone correto no tabuleiro
*	\param cod C�digo do icone (0 - 2)
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
*	\brief Limpa todo tabuleiro setando 0 | VAZIO_S em cada c�dula da matriz
*	\param tabuleiro Tabuleiro/Matriz do jogo a ser tratada [IN][OUT]
*	\return Retorna uma fun��o
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
*	\brief Imprime o Tabuleiro | Matriz na tela do usu�rio
*	\param tabuleiro Tabuleiro/Matriz do jogo a ser tratada [IN]
*	\param jogadores Vetor de Jogadores, contendo as informa��es necess�rias sobre cada um [IN]
*	\return Retorna uma fun��o
*/
void imprimeTabuleiro(int tabuleiro[][MAX], Jogador jogadores[]){
	int i, j;
	printf("\n\n");	
	if(contaJogador(jogadores) == 1){
		printf("\t       NOME: %10s               ENERGIA: %2d/25\n", jogadores[0].nome, jogadores[0].vida);
		printf("\t       ---------------------------------------------\n");
		printf("\t         |");
		for (i = 0 ; i < MAX ; i++) {
			printf("%3d", i+1);
		}
		printf("\n\t       --+------------------------------------------\n");
		for (i = 0 ; i < MAX ; i++) {
			printf("\t       %2d|", i+1);
			for (j = 0 ; j < MAX ; j++) {
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
		for (i = 0 ; i < MAX ; i++) {
			printf("%3d", i+1);
		}
		printf("              |");
		for (i = 0 ; i < MAX ; i++) {
			printf("%3d", i+1);
		}		
		printf("\n\t       --+------------------------------------------");
		printf("            --+------------------------------------------\n");		
		for (i = 0 ; i < MAX ; i++) {
			printf("\t       %2d|", i);
			for (j = 0 ; j < MAX ; j++) {
				imprimeIcone(tabuleiro[i][j]);
			}
			printf("         ");
			printf("   %2d|", i);
			for (j = 0 ; j < MAX ; j++) {
				imprimeIcone(tabuleiro[i][j]);
			}
			printf("\n");
		}
	}
}

/**
*	\brief Conta a quantidade de cada tipo de navio
*	\param tipo Inteiro referente ao tipo de navio a ser analisado
*	\param navios Todos os tipos de navios
*	\return Retorna a quantidade de navios
*/
int contaNavio(Barco *navios, int tipo){
	switch(tipo){
		case 0:
			return navios->corveta;
			break;

		case 1:
			return navios->cruzador;
			break;
		case 2:
			return navios->destroyer;
			break;
		case 3:
			return navios->fragata;
			break;
		case 4:
			return navios->porta_avioes;
			break;
		case 5:
			return navios->submarino;
			break;
	}
}

/**
*	/brief Inicia e coordena as rodadas do jogo
*	/param jogadores Recebe uma array de jogadores
*	/return Retorna uma fun��o
*/
void iniciaJogo(Jogador jogador[]){
	if(contaJogador(jogador) == 1){
	}
}

/**
*	\brief Sorteia a posi��o dos barcos conforme informado
*	\param tabuleiro Tabuleiro/Matriz do jogo onde ser� posicionado os barcos
*	\param func	Valor booleano para definir se o sorteio se dar� de maneira autom�tica ou manual (true: automatico, false: manuel)
*	\return Retorna uma fun��o
*/
void sorteiaFrota(int tabuleiro[][MAX],Barco navios, bool func){
	/**
	*	\var t_navio	Tipo de navio {0-5}
	*	\var linha		Posi��o horizontal onde os navios ser�o posicionados
	*	\var coluna		Posi��o vertical onde os navios ser�o posicionados
	*	\var direcao	Dire��o para qual o navio ser� posicionado
	*	\var s_navios	Soma de todos os navios
	*/
	int t_navio, s_navios, linha, coluna, direcao;
	
	srand((unsigned)time(NULL));
	
	s_navios = navios.corveta + navios.cruzador + navios.destroyer + navios.fragata + navios.porta_avioes + navios.submarino;
	if(func){
		while( s_navios > 0){
			t_navio	= rand()%6;
			
			while(contaNavio(&navios, t_navio) == 0){
				t_navio 	= rand()%6;
			}
			
			linha 	= rand()%14;
			coluna 	= rand()%14;
			direcao = rand()%2;
			
			
			if(verificaBarcos(t_navio, direcao, linha, coluna, tabuleiro)){
				posicionaBarcos(t_navio, direcao,linha, coluna, tabuleiro, &navios);
				s_navios--;
			}
		}
	}
}

/**
*	\brief Verifica se � poss�vel adicionar o navio nas coordenadas indicadas
*	\param barco N�mero correspondente ao tipo do barco (0-5)
*	\param direcao N�mero correspondente a dire��o qual o barco ser� posicionado ( 0 - Horizontal ; 1 - Vertical )
*	\param linha N�mero da linha na qual o barco ser� posicionado
*	\param coluna N�mero da coluna na qual o barco ser� posicionado
*	\param tabela Matriz/Tabela que ser� posicionado os barcos
*	\return Retorna um valor inteiro 1: � poss�vel adicionar o navio, 2: N�o � poss�vel adicionar o navio
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
 *	\brief Fun��es que verificam a posibilidade de instalar o barco nas coordenadas informadas, tendo como crit�rio as peculiaridades de cada barco
 *	\param direcao Dire��o na qual o barco ser� intalado (0: Horizontal, 1: Vertical)
 *	\param linha N�mero da linha na tabela aonde o barco ser� instalado
 *	\param coluna N�mero da coluna na tabela onde o barco ser� instalado
 *	\param tabela Tabela/Matriz onde os barcos ser�o instalados
 *	\return Retorna um int com o valor 1 para poss�vel instalar o barco e 0 para a falta de possibilidade de instalar o barco
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
*	\brief Verifica se � poss�vel adicionar o navio nas coordenadas indicadas
*	\param barco N�mero correspondente ao tipo do barco (0-5)
*	\param direcao N�mero correspondente a dire��o qual o barco ser� posicionado ( 0 - Horizontal ; 1 - Vertical )
*	\param linha N�mero da linha na qual o barco ser� posicionado
*	\param coluna N�mero da coluna na qual o barco ser� posicionado
*	\param tabela Matriz/Tabela que ser� posicionado os barcos
*	\return Retorna um valor inteiro 1: � poss�vel adicionar o navio, 2: N�o � poss�vel adicionar o navio
*/
 void posicionaBarcos(int barco, int direcao, int linha, int coluna, int tabela[][MAX], Barco *navio){
 	switch(barco){
 		case CORVET:
 			 posicionaCorveta(direcao, linha, coluna, tabela);
			 navio->corveta--;
 			 break;
 		case CRUZAD:
 			 posicionaCruzador(direcao, linha, coluna, tabela);
 			 navio->cruzador--;
 			 break;
 		case DESTRO:
 			 posicionaDestroyer(direcao, linha, coluna, tabela);
 			 navio->destroyer--;
 			 break;
 		case FRAGAT:
 			 posicionaFragata(direcao, linha, coluna, tabela);
 			 navio->fragata--;
 			 break;
 		case PORTAA:
 			 posicionaPortaAvioes(direcao, linha, coluna, tabela);
 			 navio->porta_avioes--;
 			 break;
 		case SUBMAR:
 			 posicionaSubmarino(direcao, linha, coluna, tabela);
 			 break;
	 }
 }
 
 /**
 *	\brief Fun��es respons�vel por posicionar os barcos onde desejado.
 *	\param direcao Dire��o na qual o barco ser� intalado (0: Horizontal, 1: Vertical)
 *	\param linha N�mero da linha na tabela aonde o barco ser� instalado
 *	\param coluna N�mero da coluna na tabela onde o barco ser� instalado
 *	\param tabela Tabela/Matriz onde os barcos ser�o instalados
 *	\return Retorna uma fun��o
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

