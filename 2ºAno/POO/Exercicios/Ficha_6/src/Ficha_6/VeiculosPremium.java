package Ficha_6;

import java.io.Serializable;

public class VeiculosPremium extends Veiculo implements BonificaKms, Serializable {
    private int pontos_km;
    private double taxa_luxo;

    public VeiculosPremium(){
        super();
        this.taxa_luxo = 0;
    }

    public VeiculosPremium(String cod, String marca1, String modelo1, int ano1, double velocidade_media1, double preco1,double classificacao1,
                   float kms_totais1,int nClientes1,double taxa_luxo1,int pontos_km){
        super(cod,marca1,modelo1,ano1,velocidade_media1,preco1,classificacao1,kms_totais1,nClientes1);
        this.taxa_luxo=taxa_luxo1;
        this.pontos_km = pontos_km;
    }

    public VeiculosPremium(VeiculosPremium v){
        super(v);
        this.taxa_luxo = v.getTaxa_luxo();
        this.pontos_km = v.getPontos_km();
    }

    public double getTaxa_luxo() {
        return taxa_luxo;
    }

    public void setTaxa_luxo(double taxa_luxo) {
        this.taxa_luxo = taxa_luxo;
    }

    public double custoReal_km(){
        return  1.1 * this.getPreco();
    }

    public VeiculosPremium clone(){
        return new VeiculosPremium(this);
    }

    public void atribui_kms(){

    }

    public int getPontos_km() {
        return pontos_km;
    }

    public void setPontos_km(int pontos_km) {
        this.pontos_km = pontos_km;
    }

    public int total_de_pontos(){
        return (int) (this.pontos_km * super.getKms_totais());
    }

    public boolean equals(Object o) {
        if (o == this) return true;
        if (o == null || o.getClass() == this.getClass()) return true;

        VeiculosPremium v = (VeiculosPremium) o;
        return super.equals(v) && this.taxa_luxo == v.getTaxa_luxo();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString())
                .append("\tTaxa de luxo: ").append(this.taxa_luxo)
                .append("\n")
                .append("}\n");
        return sb.toString();
    }
}
