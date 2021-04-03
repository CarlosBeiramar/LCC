package com.company;
import javax.swing.plaf.synth.SynthTextAreaUI;
import java.util.Scanner;
import java.util.Calendar;

public class Ficha1 {


     //Exercício 2 1)
    public double celsiusParaFarenheit (double graus){
        double res = graus * 1.8 + 32;
        System.out.println("\nFarenheit:"+res+"\n");
        return res;
    }

    // 2)

    public int maximoNumeros(int a, int b){
        if (a>b){
            System.out.println("o maior é:"+a);
            return a;
        }
        else {
            System.out.println("o maior é:"+b);
            return b;
        }
    }

    // 3)

    public String criaDescricaoConta (String nome, double saldo){

        System.out.println("Nome:" + nome + "-> Saldo:" + saldo);

        return ("Nome:" + nome + "-> Saldo:" + saldo);
    }

    //4)

    public double eurosParaLibras (double valor, double taxaConversao){
        double res = valor * taxaConversao;
        System.out.println(res);
        return  res;
    }

    //5)

    public void inteiros_media (){
        Scanner input = new Scanner(System.in);
        int media=0;
        System.out.println("Insira um número:");
        int x = input.nextInt();
        System.out.println("Insira outro número:");
        int y = input.nextInt();
        media = (x+y)/2;

        if (x>y){
            System.out.println(x+","+ y +";" + media+"\n");
        }else{
            System.out.println(y+","+x +";" + media+"\n");
        }
    }

    // 6)

    public long factorial(int num){
        long fact= 1;
        for (int i =1; i<=num; i++){
            fact += num * i;
        }
        System.out.println(fact);
        return fact;
    }

    // 7)

    public long tempoGasto(){
        Calendar calendario = Calendar.getInstance();
        long x = calendario.getTimeInMillis();
        System.out.println(x);

        factorial(5000);


        long y  = calendario.getTimeInMillis();
        System.out.println(y);
        System.out.println(y-x);
        return (y-x);
    }

}
