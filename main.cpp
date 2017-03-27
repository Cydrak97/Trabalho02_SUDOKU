/*

	* Programa para gerar um sudoku aleatorio parte resolvido e entao resolve-lo.
	* Programa feito por Isaac Pinheiro && Welerson Ferreira.
	* 26/03/2017

*/

/* INCLUDES */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include "ui.cpp"

/* DEFINES */
#define N 9

/* PROTOTIPOS */
void embaralhar(int sudokuResolvido[][N]);
void preencheSudoku(int sudokuResolvido[][N]);
void copia(int sudokuIncompleto[][N], int sudokuResolvido[][N]);
void preencheCom0(int sudokuIncompleto[][N]);
void sair();

/* MAIN */
int main(){
	system("mode con:cols=90 lines=50");
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	int sudokuResolvido[N][N];
	int sudokuIncompleto[N][N];
	char op, loop;

	/* DEFINICAO PADRAO DA LINHA CHAVE (DE 1 A 9) */
	for(int i=1; i<=N; i++){
		sudokuResolvido[0][i-1] = i;
	}
	uiTitulo();
	embaralhar(sudokuResolvido);
	preencheSudoku(sudokuResolvido);
	copia(sudokuIncompleto, sudokuResolvido);
	preencheCom0(sudokuIncompleto);

	uiPrint(sudokuIncompleto);
	uiMenuItens("R- Resolver sudoku.;G- Gerar outro sudoku.;S-Sair.");
			op=_getch(); std::cout<< op;

	if(op=='R' || op=='r'){
		uiBr(2);
		uiPrint(sudokuResolvido);
		uiQuestion("Deseja executar novamente? S/N");
		loop=_getch();
		if(loop=='s' || loop=='S'){
			main();
		}
		else{
			sair();
		}
	}
	if(op=='G' || op=='g'){
		system("cls");
		main();
	}
	if(op=='S' || op=='s'){
		sair();
	}


	return 0;
}

/* FUNCOES */


	/* FUNCAO RESPONSAVEL POR EMBARALHAR A LINHA CHAVE DO SUDOKU */
void embaralhar(int sudokuResolvido[][N]){
	int r, temp;
	for(int i=0; i<N; i++){
		r= rand()%N;

		temp=sudokuResolvido[0][i];
		sudokuResolvido[0][i]=sudokuResolvido[0][r];
		sudokuResolvido[0][r]=temp;
	}
}

	/* FUNCAO RESPONSAVEL POR PREENCHER O SUDOKU CORRETAMENTE */
void preencheSudoku(int sudokuResolvido[][N]){
	int i, j, linha=1;
	for(j=1; j<3; j++){
		for(i=0; i<6; i++){
			sudokuResolvido[linha][i]=sudokuResolvido[linha-1][i+3];
		}
		for(i=6; i<N; i++){
			sudokuResolvido[linha][i]=sudokuResolvido[linha-1][i-6];
		}
		linha++;
	}

	for(j=3; j<4; j++){
		for(i=0; i<5; i++){
			sudokuResolvido[linha][i]=sudokuResolvido[linha-1][i+4];
		}
		for(i=5; i<N; i++){
			sudokuResolvido[linha][i]=sudokuResolvido[linha-1][i-5];
		}
		linha++;
	}

	for(j=4; j<6; j++){
		for(i=0; i<6; i++){
			sudokuResolvido[linha][i]=sudokuResolvido[linha-1][i+3];
		}
		for(i=6; i<N; i++){
			sudokuResolvido[linha][i]=sudokuResolvido[linha-1][i-6];
		}
		linha++;
	}

	for(j=6; j<7; j++){
		for(i=0; i<5; i++){
			sudokuResolvido[linha][i]=sudokuResolvido[linha-1][i+4];
		}
		for(i=5; i<N; i++){
			sudokuResolvido[linha][i]=sudokuResolvido[linha-1][i-5];
		}
		linha++;
	}

	for(j=7; j<9; j++){
		for(i=0; i<6; i++){
			sudokuResolvido[linha][i]=sudokuResolvido[linha-1][i+3];
		}
		for(i=6; i<N; i++){
			sudokuResolvido[linha][i]=sudokuResolvido[linha-1][i-6];
		}
		linha++;
	}
}

	/* FUNCAO RESPONSAVEL POR COPIAR O SUDOKU RESOLVIDO AO NAO RESOLVIDO */
void copia(int sudokuIncompleto[][N], int sudokuResolvido[][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			sudokuIncompleto[i][j] = sudokuResolvido[i][j];
		}
	}
}

	/* FUNCAO RESPONSAVEL POR PREENCHER O SUDOKU COM 0's */
void preencheCom0(int sudokuIncompleto[][N]){
	int i, j;
	for(int x=0; x<75; x++){
		i=rand()%N;
		j=rand()%N;
		sudokuIncompleto[i][j]=0;
	}
}



	/* FUNCAO RESPONSAVEL POR SAIR */
void sair(){
	exit(EXIT_SUCCESS);
}
