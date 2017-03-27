#include <stdio.h>
#include <stdlib.h>

/* FUNCAO RESPONSAVEL POR GERAR O TITULO NA TELA */
void uiTitulo(){
std::cout<<"\n\t      ********  **      **  ******     ******   **      **  **      **  \n"
       <<"\t     *********  **      **  *******   ********  **     **   **      **  \n"
       <<"\t     **         **      **  **    **  ***  ***  **    **    **      **  \n"
       <<"\t       ****     **      **  **    **  **    **  **   ***    **      **  \n"
       <<"\t        ****    **      **  **    **  **    **  *******     **      **  \n"
       <<"\t            **  ***    ***  **    **  ***  ***  *******     ***    ***  \n"
       <<"\t     *********   ********   *******   ********  **    **     ********   \n"
       <<"\t     ********     ******    ******     ******   **     **     ******    \n\n";
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

void uiQuestion(string str){
  		std::cout<<"\n\n\t"<<str;
}

void uiBr(int x=1){
  for(int i=1; i<=x ; i++){
    printf("\n");
  }
}
