package com.company;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
import java.util.Arrays;

public class Ficha2 {
    //Exercício 1
    // a)

    public int minArray(){
        int n=0,x=0;
        int valor = 0;

        Scanner numeros = new Scanner(System.in);
        System.out.println("Quantos numeros vai inserir no array?");
        valor = numeros.nextInt();

        int[] valores = new int[valor];

        for (n=0;n<valor;n++){
            x = numeros.nextInt();
            valores[n]=x;
        }
        int minimo = Arrays.stream(valores).min().getAsInt();
        System.out.println("Mínimo:" +minimo);

    return minimo;
    }

    // b)

    public int[] arrayIndex(){
        int n=0,x=0,i=0;
        int valor = 0;
        int indice1=0, indice2=0;

        Scanner numeros = new Scanner(System.in);
        System.out.println("Quantos numeros vai inserir no array?");
        valor = numeros.nextInt();

        int[] valores = new int[valor];
        int[] retorna = new int[valor];

        for (n=0;n<valor;n++){
            x = numeros.nextInt();
            valores[n]=x;
        }

        System.out.println("Insira o primeiro índice:");
        indice1=numeros.nextInt();
        System.out.println("Insira o segundo índice:");
        indice2=numeros.nextInt();

        for(int y=indice1;y<=indice2;y++){
            retorna[i]=valores[y];
            System.out.println(retorna[i]);
            i++;
        }
        return retorna;
    }

    //Exercicio 4
    // a)

    public int[] ordena_cres(){
        int[] x = {10,2,9,34,1};
        Arrays.sort(x);
        System.out.println(Arrays.toString(x));
        return x;
    }

    //b)

    public void binarySearch(){
        int[] x = {10,2,9,34,1};
        System.out.println(Arrays.binarySearch(x,10));
    }

    //Exercicio 2
    // a)

    public int[][] atualiza(int [][] x){
        int aluno;
        int disciplina;
        int nota;
        Scanner notas = new Scanner(System.in);
        System.out.println("Insira qual o aluno q quer atualizar (0 a 4):");
        aluno = notas.nextInt();
        System.out.println("Insira qual a disciplina (0 a 4):");
        disciplina = notas.nextInt();
        System.out.println("Insira a nota:");
        nota  = notas.nextInt();

        x[aluno][disciplina] = nota;
        for (int i = 0; i < x.length; i++) {
            System.out.print("Aluno ->" + i + " ");
            for (int j = 0; j < x[i].length; j++) {
                System.out.print(x[i][j] + " ");
            }
            System.out.println();
        }
        return x;
    }

    //b)

    public int soma_disciplina(int [][] x,int y){
        int soma=0;

        for (int aluno =0;aluno<x.length;aluno++){
            soma =soma + x[aluno][y];
        }
        System.out.println(soma);
        return soma;
    }

    //c)

    public int aluno_media(int [][] notas,int aluno){
        int soma=0;
        for (int disciplina =0;disciplina<notas.length;disciplina++){
            soma += notas[aluno][disciplina];
        }
        int media = soma/5;
        for (int i = 0; i < notas.length; i++) {
            System.out.print("Aluno ->" + i + " ");
            for (int j = 0; j < notas[i].length; j++) {
                System.out.print(notas[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println(media);
        return media;
    }

    //d)

    public int disciplina_media(int [][] notas, int disciplina){
        int soma=0;
        for (int aluno=0; aluno<notas.length;aluno++){
            soma +=notas[aluno][disciplina];
        }
        for (int i = 0; i < notas.length; i++) {
            System.out.print("Aluno ->" + i + " ");
            for (int j = 0; j < notas[i].length; j++) {
                System.out.print(notas[i][j] + " ");
            }
            System.out.println();
        }
        int media = soma/5;
        System.out.println(media);
        return media;
    }

    //e)

    public void nota_mais_alta(int [][] notas){
        int nota=0;
        for (int i=0;i<notas.length;i++){
            for (int j=0;j<notas.length;j++) {
                if (nota<notas[i][j]){
                    nota = notas[i][j];
                }
            }
            System.out.println("Aluno (" + i + ") "+ "notas mais alta: " + nota);
        }
    }

    // f)
    public void nota_mais_baixa(int [][] notas){
        int nota=6;
        for (int i=0;i<notas.length;i++){
            for (int j=0;j<notas.length;j++) {
                if (nota>notas[i][j]){
                    nota = notas[i][j];
                }
            }
            System.out.println("Aluno (" + i + ") "+ "notas mais baixa: " + nota);
        }
    }

    // g)
    public ArrayList<Integer> array_superior(int[][]notas, int valor){
        int x=0;
        ArrayList<Integer>valores = new ArrayList<>();
        for (int i =0; i<notas.length;i++){
            for (int j=0; j<notas.length;j++){
                if (notas[i][j]>valor){
                    valores.add(notas[i][j]);
                    x++;
                }
            }
        }
            System.out.println(valores);
        return valores;
    }

    // 6 a)
    public void le_matriz(int[][] notas){
        for (int i =0;i<notas.length;i++){
            for(int j=0;j<notas.length;j++){
                System.out.println(notas[i][j]);
            }
        }
    }

    //6 b)
    public int[][] soma_matrizes(int [][] matriz1, int [][]matriz2){
        int[][] resultado=new int[matriz1.length][matriz1.length];
        if(matriz1.length == matriz2.length) {
            for (int i = 0; i < matriz1.length;i++){
                for(int j=0;j < matriz2.length;j++){
                    resultado[i][j] = matriz1[i][j] + matriz2[i][2];
                    System.out.print(resultado[i][j] + " ");
                }
                System.out.print("\n");
            }
        }
        return resultado;
    }

    //6 c)

    public boolean matrizes_iguais(int [][] matriz1, int[][] matriz2){
        for (int i=0;i<matriz1.length;i++){
            for(int j=0;j<matriz1.length;j++){
                if (matriz1[i][j] != matriz2[i][j]){
                    return false;
                }
            }
        }
        return true;
    }

    //7

    /**public void euromilhoes_simulator(){
        int min=1,max=50,iguais=0;
        int min_estrela = 1,max_estrela = 9;
        ArrayList<Integer> numeros = new ArrayList<>();
        Random random = new Random();
        int estrela1 = random.nextInt(((max-min)+1)+min);
        int estrela2 = random.nextInt(((max-min)+1)+min);

        for (int i=1;i<=5;i++){
            numeros.add(random.nextInt((max-min)+1)+min);
        }

        System.out.println("Insira os seus numeros:");

        ArrayList<Integer> chave_util = new ArrayList<>();
        Scanner read = new Scanner(System.in);
        int x =0;

        while(x<5){
            chave_util.add(read.nextInt());
            x++;
        }

        System.out.print("Insira as suas estrelas");
        int estrela1_util = read.nextInt();
        int estrela2_util = read.nextInt();

        for (int i =0;i<numeros.size();i++){
            for (int j=0;j<chave_util.size();j++)
            if (numeros.get(i) == chave_util.get(j)){
                iguais++;
            }
        }
    }**/
}
