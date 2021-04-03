package Ficha_6;

import java.io.Serializable;

public class AutocarroInteligente extends Veiculo implements BonificaKms, Serializable {
    private double numero_passageiros;
    private double capacidade;
    private int pontos_km;

    public AutocarroInteligente(){
        super();
        this.numero_passageiros = 0;
        this.capacidade = 50;
        this.pontos_km = 0;
    }

    public AutocarroInteligente(String cod, String marca1, String modelo1, int ano1, double velocidade_media1, double preco1,double classificacao1,
                                float kms_totais1,int nClientes1,double numero_passageiros1,double capacidade1,int pontos_km){

        super(cod, marca1, modelo1, ano1, velocidade_media1, preco1, classificacao1, kms_totais1, nClientes1);
        this.numero_passageiros = numero_passageiros1;
        this.capacidade = capacidade1;
        this.pontos_km = pontos_km;
    }

    public AutocarroInteligente(AutocarroInteligente a){
        super(a);
       setNumero_passageiros(a.getNumero_passageiros());
       setCapacidade(a.getCapacidade());
       this.pontos_km = a.getPontos_km();
    }


    public double getCapacidade() {
        return capacidade;
    }

    public double getNumero_passageiros() {
        return numero_passageiros;
    }

    public int getPontos_km() {
        return pontos_km;
    }

    public int total_de_pontos(){
        return (int) (this.pontos_km * super.getKms_totais());
    }

    public void setPontos_km(int pontos_km) {
        this.pontos_km = pontos_km;
    }

    public void setCapacidade(double capacidade) {
        this.capacidade = capacidade;
    }

    public void setNumero_passageiros(double numero_passageiros) {
        this.numero_passageiros = numero_passageiros;
    }

    public double custoReal_km(){
        double ocupacao = this.numero_passageiros/this.capacidade;
        if (ocupacao>=0 && ocupacao<=60){
            return (1.1 * this.getPreco()) * 0.5;
        }else{
            return (1.1 * this.getPreco()) *0.75;
        }
    }

    public boolean equals(Object o) {
        if (o == this) return true;
        if (o == null || o.getClass() == this.getClass()) return true;

        AutocarroInteligente a = (AutocarroInteligente) o;

        return super.equals(a) && this.capacidade == a.getCapacidade();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString()).append("\tCapacidade:").append(this.capacidade)
                .append("}\n");
        return sb.toString();
    }

        public AutocarroInteligente clone(){
        return new AutocarroInteligente(this);
    }
}
