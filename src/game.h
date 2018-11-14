#ifndef GAME_FUNCOES_H
#define GAME_FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include "conio2.h"

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

#define MAX 15
//Struct
/*
typedef enum{
	BARCO_A,
	BARCO_B
} Barco_t;

typedef struct {
	int tabela[MAX][MAX];
	Barco_t barco;
} Tabela;
*/

typedef enum{
	CORVET,
	CRUZAD,
	DESTRO,
	FRAGAT,
	PORTAA,
	SUBMAR
} t_Barco;

typedef struct{
	int corveta;
	int cruzador;
	int destroyer;
	int fragata;
	int porta_avioes;
	int submarino;
} Barco;

typedef enum {
	HORIZONTAL,
	VERTICAL
} Orientacao;

typedef enum{
	VAZIO_S,
	AGUA_S,
	NAVIO_S	
} Status_t;

typedef struct{
	char	nome[100];
	Barco 	barco;
	int		vida;
	bool 	acertos;
	bool 	ativo;
	int 	tabuleiro[MAX][MAX];
} Jogador;

typedef enum {
	AGUA = '.',
	T_AGUA = '-',
	NAVIO = '@',
	T_NAVIO = 'X'
} Icon;

// Funções do Menu
void colorText(char text[], int color);
int menuInicial();
int menuNivel();
int menuTipo();


// Funções Batalha Naval
void carregarTabuleiro(int tabuleiro[][MAX]);
void iniciaJogador(Jogador *j, Barco b, char nome[]);
void imprimeTabuleiroS(int tabela[][MAX], Jogador jogador);











#endif
