#include <stdio.h>



void abrirficheiro (char m[1000][1000]){
    FILE *f;
    int x,y,l,c;
    f=fopen("/Users/carlosbeiramar/CLionProjects/teste/cmake-build-debug/tabuleiro.txt","r");

    fscanf(f,"%d %d",&x,&y);                // para tirar de printar a dimensao da matriz que esta em cima o 3 por 4

    for (l=0;l<x;l++)
    {
        for (c = 0; c < y; c++)
        {
            fscanf(f," %c", &m[l][c]);          //para guardar o que tem dentro do tabuleiro na matriz
            printf(" %c", m[l][c]);             //imprimir os chares da matriz
        }
        printf("\n");
    }
    fclose(f);
}




void alteratabuleiro (char m[1000][1000]){
    int l,c;
    char sub;

    printf("Escolha a posicao da matriz que pretende alterar\n");

    scanf("%d %d",&l,&c);

    if (m[l][c] != '.') {
        printf("Nao pode colocar nada aqui\n");
    }

    else {
        printf("Escolha o caracter que deseja (X ou O)\n");
        scanf("%c", &sub);
            if (sub != 'X' && sub != 'O') {
                printf("Introduza um char valido\n");
                alteratabuleiro(m);
            }
            else {
                m[l][c] = sub;
            }
        }
  }

void guardaalteracao(char m[1000] [1000]){
    FILE *f;
    int x,y;
    int l,c;
    f=fopen("/Users/carlosbeiramar/CLionProjects/teste/cmake-build-debug/tabuleiro.txt","r");
    fscanf(f,"%d %d",&x,&y);
    fclose(f);

    f=fopen("/Users/carlosbeiramar/CLionProjects/teste/cmake-build-debug/tabuleiro.txt","w");

          // para tirar de printar a dimensao da matriz que esta em cima o 3 por 4

    fprintf(f,"%d %d\n",x,y);
    for (l=0;l<x;l++) {
        for (c = 0; c < y; c++) {
            fprintf(f,"%c ",m[l][c]);
        }
     fprintf(f,"\n");
    }

   fclose(f);
}


    void menu (char m[1000][1000]) {
    int x;

    printf("Escolha uma das seguintes opçoes:\n");
    printf("1-abrir o ficheiro e apresentar o conteudo\n");
    printf("2-Alterar conteudo e mostrar o conteudo modificado\n");
    printf("3-Sair\n");
    scanf("%d", &x);

    switch (x) {
        case 1:
            abrirficheiro(m);
            printf("\n");
            menu(m);
            break;
        case 2:
            alteratabuleiro(m);
            guardaalteracao(m);
            abrirficheiro(m);
            menu(m);
            break;
        case 3:
            break;
        default:
            printf("Número não encontrado\n\n");//se clicar em algum para alem das opcoes posiveis(1,2,3,...)
            menu(m);
            break;
    }
}


int main() {
    char m[1000][1000];
    menu(m);
    return 0;
}