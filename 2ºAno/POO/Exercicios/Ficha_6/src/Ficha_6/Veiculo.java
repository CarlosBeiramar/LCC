package Ficha_6;

public abstract class Veiculo {
    private String codigo;
    private String marca;
    private String modelo;
    private int ano;
    private double kms_totais;
    private double velocidade_media;
    private double preco;
    private double classificacao;
    private int nClientes_que_classificou;

    public Veiculo(){
        this.codigo = "";
        this.marca = "";
        this.modelo = "";
        this.ano = ano;
        this.kms_totais = 0;
        this.velocidade_media = 0;
        this.preco = 0;
        this.classificacao = 0;
        this.nClientes_que_classificou = 0;
    }
    public Veiculo(String cod, String marca1, String modelo1, int ano1, double velocidade_media1, double preco1,double classificacao1,
                   float kms_totais1,int nClientes1) {
        this.codigo = cod;
        this.marca = marca1;
        this.modelo = modelo1;
        this.ano = ano1;
        this.kms_totais = kms_totais1;
        this.velocidade_media = velocidade_media1;
        this.preco = preco1;
        this.classificacao = classificacao1;
        this.nClientes_que_classificou = nClientes1;
    }

    public Veiculo(Veiculo v){
        this.codigo = v.getCodigo();
        this.marca = v.getMarca();
        this.modelo = v.getModelo();
        this.ano = v.getAno();
        this.kms_totais = v.getKms_totais();
        this.velocidade_media = v.getVelocidade_media();
        this.preco = v.getPreco();
        this.classificacao = v.getClassificacao();
        this.nClientes_que_classificou = v.getnClientes_que_classificou();
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String cod) {
        this.codigo = cod;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public double getKms_totais() {
        return kms_totais;
    }

    public void setKms_totais(double kms_totais) {
        this.kms_totais = kms_totais;
    }

    public double getVelocidade_media() {
        return velocidade_media;
    }

    public void setVelocidade_media(double velocidade_media) {
        this.velocidade_media = velocidade_media;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public double getClassificacao() {
        return classificacao;
    }

    public void setClassificacao(double classificacao) {
        this.classificacao = classificacao;
    }

    public int getnClientes_que_classificou() {
        return nClientes_que_classificou;
    }

    public void setnClientes_que_classificou(int nClientes_que_classificou) {
        this.nClientes_que_classificou = nClientes_que_classificou;
    }

    public abstract double custoReal_km();

    public abstract Veiculo clone();

    public boolean equals(Object o){
        if (o == this) return true;
        if (o==null || o.getClass()==this.getClass())return true;
        Veiculo v = (Veiculo) o;
        return this.getCodigo().equals(v.getCodigo());
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Código:").append(this.codigo).append("\n")
                .append("{\n")
                .append("\tMarca: ").append(this.marca).append("\n")
                .append("\tModelo: ").append(this.modelo).append("\n")
                .append("\tAno: ").append(this.ano).append("\n")
                .append("\tVelocidade média: ").append(this.velocidade_media).append("\n")
                .append("\tPreço: ").append(this.classificacao).append("\n")
                .append("\tClassificação: ").append(this.classificacao).append("\n")
                .append("\tQuilómetros: ").append(this.kms_totais).append("\n");
        return sb.toString();
    }
}
