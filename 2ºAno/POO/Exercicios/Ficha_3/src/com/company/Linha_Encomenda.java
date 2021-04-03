package com.company;

public class Linha_Encomenda {

    private String referencia;
    private String descricao;
    private double preco;
    private double quantidade;
    private double imposto;
    private double desconto;

    public Linha_Encomenda(){
        this.referencia = "";
        this.descricao = "";
        this.preco = 0;
        this.quantidade = 0;
        this.imposto = 0;
        this.desconto = 0;
    }

    public Linha_Encomenda (String ref, String desc,double preco, double quantidade, double imposto, double desconto){
        this.referencia = ref;
        this.descricao = desc;
        this.preco = preco;
        this.quantidade = quantidade;
        this.imposto = imposto;
        this.desconto = desconto;
    }

    public Linha_Encomenda (Linha_Encomenda t){
        this.referencia = t.getReferencia();
        this.desconto = t.getDesconto();
        this.preco = t.getPreco();
        this.quantidade = t.getQuantidade();
        this.desconto = t.getDesconto();
        this.imposto = t.getImposto();
        this.descricao = t.getDescricao();
    }

    public double getDesconto() {
        return this.desconto;
    }

    public double getImposto() {
        return this.imposto;
    }

    public double getPreco() {
        return this.preco;
    }

    public double getQuantidade() {
        return this.quantidade;
    }

    public String getDescricao() {
        return this.descricao;
    }

    public String getReferencia() {
        return this.referencia;
    }

    public void setDesconto(double desconto) {
        this.desconto = desconto;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public void setImposto(double imposto) {
        this.imposto = imposto;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void setQuantidade(double quantidade) {
        this.quantidade = quantidade;
    }

    public void setReferencia(String referencia) {
        this.referencia = referencia;
    }

    public double calculaValorLinhaEnc(){
        double p = (this.preco * this.imposto)/100;
        double preco = this.preco - p;
        return preco * this.quantidade;
    }

   public boolean equals(Object o ){
        if(o==this) return true;
        if((o== null) || (o.getClass() != this.getClass())) return false;

        Linha_Encomenda nova_linha = (Linha_Encomenda) o;

        return  (this.referencia.equals(nova_linha.getReferencia()));
    }


    public Linha_Encomenda clone(){
        return new Linha_Encomenda(this);
    }



}
