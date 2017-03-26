/*

	* Programa para gerar um sudoku aleatório parte resolvido e então resolve-lo.
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

/* DEFINES */
#define N 9

/* PROTÓTIPOS */
void titulo();
void embaralhar(int sudokuResolvido[][N]);
void preencheSudoku(int sudokuResolvido[][N]);
void copia(int sudokuIncompleto[][N], int sudokuResolvido[][N]);
void preencheCom0(int sudokuIncompleto[][N]);
void imprime(int sudokuResolvido[][N]);
void sair();

/* MAIN */
int main(){
	system("mode con:cols=90 lines=50");
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	int sudokuResolvido[N][N];
	int sudokuIncompleto[N][N];
	char op, loop;
	
	/* DEFINIÇÃO PADRÃO DA LINHA CHAVE (DE 1 A 9) */
	for(int i=1; i<=N; i++){
		sudokuResolvido[0][i-1] = i;
	}
	titulo();
	embaralhar(sudokuResolvido);
	preencheSudoku(sudokuResolvido);
	copia(sudokuIncompleto, sudokuResolvido);
	preencheCom0(sudokuIncompleto);
	
	imprime(sudokuIncompleto);
	std::cout<<"\n\n\tOpções:\n"
		<<"\t\tR- Resolver sudoku.\n"
		<<"\t\tG- Gerar outro sudoku.\n"
		<<"\t\tS- Sair.\n\n"
		<<"\tInsira opção: ";op=_getch(); std::cout<< op;
	
	if(op=='R' || op=='r'){
		printf("\n\n");
		imprime(sudokuResolvido);
		
		std::cout<<"\n\n\tDeseja executar novamente? S/N ";loop=_getch();
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

/* FUNÇÕES */
	/* FUNÇÃO RESPONSÁVEL POR GERAR O TÍTULO NA TELA */
void titulo(){
	std::cout<<"\n\t      ********  **      **  ******     ******   **      **  **      **  \n"
    		 <<"\t     *********  **      **  *******   ********  **     **   **      **  \n"
    		 <<"\t     **         **      **  **    **  ***  ***  **    **    **      **  \n"
    		 <<"\t       ****     **      **  **    **  **    **  **   ***    **      **  \n"
    		 <<"\t        ****    **      **  **    **  **    **  *******     **      **  \n"
    		 <<"\t            **  ***    ***  **    **  ***  ***  *******     ***    ***  \n"
    		 <<"\t     *********   ********   *******   ********  **    **     ********   \n"
    		 <<"\t     ********     ******    ******     ******   **     **     ******    \n\n";
}

	/* FUNÇÃO RESPONSÁVEL POR EMBARALHAR A LINHA CHAVE DO SUDOKU */
void embaralhar(int sudokuResolvido[][N]){
	int r, temp;
	for(int i=0; i<N; i++){
		r= rand()%N;
		
		temp=sudokuResolvido[0][i];
		sudokuResolvido[0][i]=sudokuResolvido[0][r];
		sudokuResolvido[0][r]=temp;
	}
}

	/* FUNÇÃO RESPONSÁVEL POR PREENCHER O SUDOKU CORRETAMENTE */
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

	/* FUNÇÃO RESPONSÁVEL POR COPIAR O SUDOKU RESOLVIDO AO NÃO RESOLVIDO */
void copia(int sudokuIncompleto[][N], int sudokuResolvido[][N]){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			sudokuIncompleto[i][j] = sudokuResolvido[i][j];
		}	
	}
}

	/* FUNÇÃO RESPONSÁVEL POR PREENCHER O SUDOKU COM 0's */
void preencheCom0(int sudokuIncompleto[][N]){
	int i, j;
	for(int x=0; x<75; x++){
		i=rand()%N;
		j=rand()%N;
		sudokuIncompleto[i][j]=0;
	}
}

	/* FUNÇÃO RESPONSÁVEL POR IMPRIMIR O SUDOKU */
void imprime(int sudoku[][N]){
	int i, j;
	printf("\t\t\t\t|=======|=======|=======|\n");
	for(i=0; i<N; i++){
	printf("\t\t\t\t| ");
		for(j=0; j<N; j++){
			if(j==3 || j==6){
				printf("| ");
			}
			printf("%i ", sudoku[i][j]);
		}
		printf("|");
		printf("\n");
		if(i==2 || i==5){
			printf("\t\t\t\t|=======|=======|=======|\n");
		}
	}
	printf("\t\t\t\t|=======|=======|=======|\n");
}

	/* FUNÇÃO RESPONSÁVEL POR SAIR */
void sair(){
	exit(EXIT_SUCCESS);
}
