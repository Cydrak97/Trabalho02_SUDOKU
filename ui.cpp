#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <string>

using namespace std;
#define N 9
//FUNCAO RESPONSAVEL POR GERAR O TITULO NA TELA
void uiTitulo(){
    printf("\n\t      ********  **      **  ******     ******   **      **  **      **  \n");
    printf("\t     *********  **      **  *******   ********  **     **   **      **  \n");
    printf("\t     **         **      **  **    **  ***  ***  **    **    **      **  \n");
    printf("\t       ****     **      **  **    **  **    **  **   ***    **      **  \n");
    printf("\t        ****    **      **  **    **  **    **  *******     **      **  \n");
    printf("\t            **  ***    ***  **    **  ***  ***  *******     ***    ***  \n");
    printf("\t     *********   ********   *******   ********  **    **     ********   \n");
    printf("\t     ********     ******    ******     ******   **     **     ******    \n\n");
}

/* FUNCAO RESPONSAVEL POR IMPRIMIR O SUDOKU */
void uiPrint(int sudoku[][N]){
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

void uiMenuItens(std::string s){
  std::string delimiter = ";";
  std::cout<<"\n\n\tOpcoes:\n";
  size_t pos = 0;
  std::string token;
  while ((pos = s.find(delimiter)) != std::string::npos) {
      token = s.substr(0, pos);
      std::cout << "\t\t" << token << std::endl;
      s.erase(0, pos + delimiter.length());
  }
  std::cout << "\t\t" << s << "\n\n"
  <<"\tInsira opcao: ";;
}

void uiQuestion(std::string str){
  		std::cout<<"\n\n\t"<<str;
}

void uiBr(int x=1){
  for(int i=1; i<=x ; i++){
    printf("\n");
  }
}
