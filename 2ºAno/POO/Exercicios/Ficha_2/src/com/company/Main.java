package com.company;

public class Main {

    public static void main(String[] args) {

        Ficha2 ficha_2 = new Ficha2();

        int[][] notas = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
        int[][] matriz2 = {{10,2,3,13,5},{5,2,76,7,5},{1,15,3,17,5},{1,2,3,4,5},{1,2,3,4,5}};


        //1 a)
        //int n = ficha_2.minArray();

        //1 b)
        //ficha_2.arrayIndex();

        //2 a)
        //ficha_2.atualiza(notas);

        //2 b)
        //ficha_2.soma_disciplina(notas,3);

        //2 c)
        //ficha_2.aluno_media(notas,1);

        //2 d)
        //ficha_2.disciplina_media(notas,4);

        //2 e)
        //ficha_2.nota_mais_alta(notas);

        //2 f)
        //ficha_2.nota_mais_baixa(notas);

        //2 g)
        //ficha_2.array_superior(notas,4);

        //4 a)
        //ficha_2.ordena_cres();

        //4 b)
        //ficha_2.binarySearch();

        // 6 b)
        ficha_2.soma_matrizes(notas,matriz2);


    }
}
