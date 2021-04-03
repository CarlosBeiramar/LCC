package Ficha_6;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class Main {

    public static void main(String[] args) throws IOException {

        DriveItList driveIt = new DriveItList();
        VeiculoNormal v1 = new VeiculoNormal("v1", "Audi", "A3", 2010, 80.0, 92.4, 7, 20, 3);
        VeiculoNormal v2 = new VeiculoNormal("v2", "BMW", "Class C", 2007, 95.3, 90.1, 8,  10, 3);
        VeiculoNormal v3 = new VeiculoNormal("v3", "Porshe", "Panamera", 2009, 80.0, 87.4, 8, 3, 1);
        VeiculosPremium v4 = new VeiculosPremium("v4", "Mercedes", "MG", 2005, 70.0, 86.5, 7, 12, 2, 1.06, 5);
        VeiculosPremium v5 = new VeiculosPremium("v5", "Ferrari", "1.18", 2011, 100.4, 121.2, 9, 0, 0, 1.2, 6);
        VeiculosPremium v6 = new VeiculosPremium("v6", "Rolls Royce", "Ghost", 2020, 110.3, 200.2, 10, 7, 1, 1.15, 7);
        VeiculoOcasiao v7 = new VeiculoOcasiao("v7", "Audi", "A3", 2005, 78.6, 70.8, 7, 20, 3, false);
        VeiculoOcasiao v8 = new VeiculoOcasiao("v8", "Nissan", "GTR", 2008, 77.2, 89.7, 8, 43, 5, false);
        VeiculoOcasiao v9 = new VeiculoOcasiao("v9", "McLaren", "P1", 2020, 121.2, 140, 9, 10, 1, false);
        AutocarroInteligente v10 = new AutocarroInteligente("v10", "Tesla", "CyberTruck", 2021, 103.2, 105.1, 9, 40, 5, 85, 10,4);


        driveIt.adiciona(v1);
        driveIt.adiciona(v2);
        driveIt.adiciona(v3);
        driveIt.adiciona(v4);
        driveIt.adiciona(v5);
        driveIt.adiciona(v6);
        driveIt.adiciona(v7);
        driveIt.adiciona(v8);
        driveIt.adiciona(v9);
        driveIt.adiciona(v10);


        //i
        /**System.out.println("V4 -> Pontos Por KM (antes) : " + v4.getPontos_km());
        v4.setPontos_km(10);
        System.out.println("V4 -> Pontos Por KM (depois) : " + v4.getPontos_km());

        System.out.println("\n");

        //ii
        System.out.println("V4 -> Pontos Totais : " + v4.total_de_pontos());
        System.out.println("V5 -> Pontos Totais : " + v5.total_de_pontos());
        System.out.println("V6 -> Pontos Totais : " + v6.total_de_pontos());
        System.out.println("V10 -> Pontos Totais : " + v10.total_de_pontos());

        System.out.println("\n");

        //iii
        System.out.println(driveIt.daoPontos().toString());*/

        driveIt.gravaCSV();
        driveIt.grava_em_ficheiro();

    }
}
