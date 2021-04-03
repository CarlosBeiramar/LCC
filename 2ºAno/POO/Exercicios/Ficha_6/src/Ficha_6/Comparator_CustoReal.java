package Ficha_6;

import java.util.Comparator;

public class Comparator_CustoReal implements Comparator<Veiculo> {
    public int compare(Veiculo v1, Veiculo v2) {
        return (int) (v2.getPreco()-v1.getPreco());
    }
}
