/**
*	Header - Cabeçalho do programa
*/

#ifndef GAME_FUNCOES_H
#define GAME_FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>		//Habilita a opção de caráctere Booleana
#include <locale.h>
#include <string.h>
#include "conio2.h"			//Facilita a utilização da biblioteca conio.h

/*
	Define o valor das teclas segunda tabela ASCII
*/
#define BAIXO 80
#define CIMA 72
#define ENTER 13
#define ESQUERDA 75
#define DIREITA 77
#define ESC 27

/*
	Define retornos da função menuInicial()
*/
#define INDIVIDUAL 1
#define DUPLA 2
#define RANK 3
#define INST 4
#define SAIR 5
/*
	Define retornos da função menuNivel()
*/
#define FACIL 10
#define NORMAL 11
#define DIFICIL 12
/*
	Define retornos da função menuTipo()
*/
#define MANUAL 20
#define AUTOMATICO 21

#define MAX 15					//Valor máximo adotado nas matrizes


//	Define os tipos de barcos
typedef enum{
	CORVET,
	CRUZAD,
	DESTRO,
	FRAGAT,
	PORTAA,
	SUBMAR
} t_Barco;

//	Define a tipagem de váriavel Barco
typedef struct{
	int corveta;
	int cruzador;
	int destroyer;
	int fragata;
	int porta_avioes;
	int submarino;
} Barco;


//	Define os tipos de orientações
typedef enum {
	HORIZONTAL,
	VERTICAL
} Orientacao;

// Define os Status que serão adotados pelas matrizes
typedef enum{
	VAZIO_S,
	AGUA_S,
	NAVIO_S	
} Status_t;

// Define a tipagem de váriavel Jogador
typedef struct{
	char	nome[100];
	Barco 	barco;
	int		vida;
	bool 	acertos;
	bool 	ativo;
	int 	tabuleiro[MAX][MAX];
} Jogador;

// Define os icones a serem utilizados na matriz/tabuleiro
typedef enum {
	AGUA = '.',
	T_AGUA = '-',
	NAVIO = '@',
	T_NAVIO = 'X'
} Icon;

// Lista de funções do menu
void escreverTexto(char texto[]);
void escreverTextoColorido(char texto[], int color);
void colorChar(char c, int color);
void colorText(char text[], int color);
void logo();
void imprimirSeta();
int menuInicial();
int menuNivel();
int menuTipo();

// Lista de funções da batalha naval
int contarJogadores(Jogador jogadores[]);
void iniciarJogador(Jogador *jogador, Barco barco, char nome[]);
void imprimeIcone(int cod);
void carregarTabuleiro(int tabuleiro[][MAX]);
void imprimeTabuleiro(int tabuleiro[][MAX], Jogador jogadores[]);
void sorteiaFrota(int tabuleiro[][MAX],Barco barcos, bool func);
int verificaBarcos(int barco, int direcao, int linha, int coluna, int tabela[][MAX]);
int verificaCorveta(int direcao, int linha, int coluna, int tabela[][MAX]);
int verificaCruzador(int direcao, int linha, int coluna, int tabela[][MAX]);
int verificaDestroyer(int direcao, int linha, int coluna, int tabela[][MAX]);
int verificaFragata(int direcao, int linha, int coluna, int tabela[][MAX]);
int verificaPortaAvioes(int direcao, int linha, int coluna, int tabela[][MAX]);
int verificaSubmarino(int direcao, int linha, int coluna, int tabela[][MAX]);
void posicionaBarcos(int barco, int direcao, int linha, int coluna, int tabela[][MAX]);
void posicionaCorveta(int direcao, int linha, int coluna, int tabela[][MAX]);
void posicionaCruzador(int direcao, int linha, int coluna, int tabela[][MAX]);
void posicionaDestroyer(int direcao, int linha, int coluna, int tabela[][MAX]);
void posicionaFragata(int direcao, int linha, int coluna, int tabela[][MAX]);
void posicionaPortaAvioes(int direcao, int linha, int coluna, int tabela[][MAX]);
void posicionaSubmarino(int direcao, int linha, int coluna, int tabela[][MAX]);

#endif
