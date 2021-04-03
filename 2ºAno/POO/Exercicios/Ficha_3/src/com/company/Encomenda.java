package com.company;


import java.time.LocalDateTime;

public class Encomenda {
    private String nome;
    private long nif;
    private String morada;
    private int num_encomenda;
    private LocalDateTime data;
    private Linha_Encomenda[] linha_encomendas;

    public Encomenda(){
        this.nome = "";
        this.nif = 0;
        this.morada = "";
        this.num_encomenda = 0;
        this.data = LocalDateTime.now();
        this.linha_encomendas = new Linha_Encomenda[10];
    }

    public Encomenda (String nome1, long nif1, String morada1, int num_encomenda1,LocalDateTime data1, Linha_Encomenda[] linha_encomendas1){
        this.nome = nome1;
        this.nif = nif1;
        this.morada = morada1;
        this.num_encomenda = num_encomenda1;
        this.data = data1;
        setLinha_encomendas(linha_encomendas1);
    }

    public Encomenda (Encomenda x){

    }

    public int getNum_encomenda() {
        return num_encomenda;
    }

    public long getNif() {
        return nif;
    }

    public LocalDateTime getData() {
        return data;
    }

    public String getMorada() {
        return morada;
    }

    public String getNome() {
        return nome;
    }

    public Linha_Encomenda[] getLinha_encomendas() {
        Linha_Encomenda nova_linha[] = new Linha_Encomenda[this.linha_encomendas.length];
        for (int i=0; i< linha_encomendas.length;i++){
            nova_linha[i] = linha_encomendas[i].clone();
        }
        return nova_linha;
    }

    public void setLinha_encomendas(Linha_Encomenda[] linha_encomendas) {
        this.linha_encomendas = new Linha_Encomenda[linha_encomendas.length];
        for (int i  = 0; i<linha_encomendas.length;i++){
            this.linha_encomendas[i] = linha_encomendas[i].clone();
        }
    }
}
