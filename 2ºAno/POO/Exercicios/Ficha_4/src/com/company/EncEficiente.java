package com.company;

import java.time.LocalDateTime;
import java.util.ArrayList;

public class EncEficiente {

    /*
    Variáveis de instâncias
     */
    private String nome;
    private String nif;
    private String morada;
    private int numEnc;
    private LocalDateTime data_enc;
    private ArrayList<LinhaEncomenda> encomendas;

    /*
    Construtores
     */

    public EncEficiente(){
        this.nome = "";
        this.nif = "";
        this.morada = "";
        this.numEnc = 0;
        this.data_enc = LocalDateTime.now();
        this.encomendas = new ArrayList<LinhaEncomenda>();
    }

    public EncEficiente(String name,String nif2, String address, int numEnc2,LocalDateTime date,ArrayList<LinhaEncomenda> encomendas1){
        this.nome = name;
        this.nif = nif2;
        this.morada = address;
        this.numEnc = numEnc2;
        this.data_enc = date;
        for(LinhaEncomenda l:encomendas1){
            this.encomendas.add(l.clone());
        }
    }

    public EncEficiente(EncEficiente s){
        this.nome = s.getNome();
        this.nif = s.getNif();
        this.morada = s.getMorada();
        this.numEnc = s.getNumEnc();
        this.data_enc = s.getData_enc();
        this.encomendas = s.getEncomendas();
    }

    /*
    Getter and Setters
     */

    public String getNome() {
        return nome;
    }

    public String getMorada() {
        return morada;
    }

    public int getNumEnc() {
        return numEnc;
    }

    public String getNif() {
        return nif;
    }

    public LocalDateTime getData_enc() {
        return data_enc;
    }

    public ArrayList<LinhaEncomenda> getEncomendas() {
        ArrayList<LinhaEncomenda> novo = new ArrayList<LinhaEncomenda>();
        for (LinhaEncomenda l:this.encomendas){
            novo.add(l.clone());
        }
        return novo;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setData_enc(LocalDateTime data_enc) {
        this.data_enc = data_enc;
    }

    public void setNumEnc(int numEnc) {
        this.numEnc = numEnc;
    }

    public void setMorada(String morada) {
        this.morada = morada;
    }

    public void setNif(String nif) {
        this.nif = nif;
    }

    public void setEncomendas(ArrayList<LinhaEncomenda> encomendas1) {
        encomendas.clear();
        for (LinhaEncomenda l:encomendas1){
            this.encomendas.add(l.clone());
        }
    }

    /*
    Calcula o valor total da encomenda.
     */

    public double calculaValorTotal(){
        double valor = 0;
        for (LinhaEncomenda l:this.encomendas){
            valor += l.calculaValorLinhaEnc();
        }
        return valor;
    }

    /*
    calcula o valor dos descontos
     */

    public double calculaValorDescontos(){
        double descontos=0;
        for (LinhaEncomenda l:this.encomendas){
            descontos += l.calculaValorDesconto();
        }
        return descontos;
    }

    /*
    metodo que determina o numero total de produtos a receber
     */

    public int numeroTotalProdutos(){
        int quantidade = 0;
        for (LinhaEncomenda l: this.encomendas){
            quantidade += l.getQuantidade();
        }
        return quantidade;

    }

    /*
    determina se o produto vai ser encomendado
     */

    public boolean existeProdutoEncomenda(String refProduto){
        int i=0;
        boolean encontrado=false;
        while (i<this.encomendas.size() && !encontrado){
            if (refProduto.equals(this.encomendas.get(i).getReferencia())){
                encontrado=true;
            }
        }
        return encontrado;
    }

    /*
    método que adiciona uma nova linha de encomenda
     */

    public void adicionaLinha(LinhaEncomenda linha){
        this.encomendas.add(linha);
    }

    /*
    método que remove uma linha de encomenda
     */

    public void removeProduto(String codProd){
        int i =0,flag=0;
        while(i<this.encomendas.size() && flag==0){
            if (codProd.equals(this.encomendas.get(i).getReferencia())){
                this.encomendas.remove(i);
                flag=1;
            }
        }
    }


    public boolean equals(Object o){
        if (this==o)return true;
        if (o == null || o.getClass() != this.getClass()) return false;
        EncEficiente x = (EncEficiente) o;
        return this.getEncomendas().equals(x.getEncomendas());
    }

    public EncEficiente clone(){
        return new EncEficiente(this);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Nome:").append(this.nome);
        sb.append("NIF:").append(this.nif);
        sb.append("Morada:").append(this.morada);
        sb.append("Numero da Encomenda:").append(this.numEnc);
        for (LinhaEncomenda l:this.encomendas){
            l.toString();
        }
        return sb.toString();
    }
}
