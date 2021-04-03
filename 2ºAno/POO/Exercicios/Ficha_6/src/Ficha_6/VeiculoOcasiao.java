package Ficha_6;

import java.io.Serializable;

public class VeiculoOcasiao extends Veiculo implements Serializable {

    private boolean promocao;

    public VeiculoOcasiao(){
        super();
        this.promocao = false;
    }

    public VeiculoOcasiao(String cod, String marca1, String modelo1, int ano1, double velocidade_media1, double preco1,double classificacao1,
                          float kms_totais1,int nClientes1,boolean promocao1){
        super(cod,marca1,modelo1,ano1,velocidade_media1,preco1,classificacao1,kms_totais1,nClientes1);
        this.promocao = promocao1;
    }

    public VeiculoOcasiao(VeiculoOcasiao v){
        super(v);
        this.promocao = v.isPromocao();
    }

    public boolean isPromocao() {
        return promocao;
    }

    public void setPromocao(boolean promocao) {
        this.promocao = promocao;
    }

    public double custoReal_km(){
        double coef = 1+(super.getKms_totais()/100000);
        float acrescimo = 1.1f;
        double r =  super.getPreco() * acrescimo * coef;
        if(this.promocao){
            r = r*0.75f;
        }
        return Math.round(r);
    }

    public VeiculoOcasiao clone(){
        return new VeiculoOcasiao(this);
    }

    public boolean equals(Object o) {
        if (o == this) return true;
        if (o == null || o.getClass() == this.getClass()) return true;

        VeiculoOcasiao v = (VeiculoOcasiao) o;
        return super.equals(v) && this.promocao == v.isPromocao();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString());
        if (promocao) sb.append("Está em promoção\n");
        else sb.append("\tNão está em promoção.\n");
        sb.append("}\n");
        return sb.toString();
    }
}
