package Ficha_6;

import java.io.Serializable;

public class VeiculoNormal extends Veiculo implements Serializable {
    public VeiculoNormal(){
        super();
    }

    public VeiculoNormal(String cod, String marca1, String modelo1, int ano1, double velocidade_media1, double preco1,double classificacao1,
                         float kms_totais1,int nClientes1){
        super(cod,marca1,modelo1,ano1,velocidade_media1,preco1,classificacao1,kms_totais1,nClientes1);
    }

    public VeiculoNormal (VeiculoNormal v){
        super(v);
    }

    public double custoReal_km(){
        return  1.1 * this.getPreco();
    }

    public VeiculoNormal clone(){
        return new VeiculoNormal(this);
    }
}
