package Ficha_6;

import java.util.Comparator;

public class Comparator_numKms implements Comparator<Veiculo> {
    public int compare(Veiculo v1, Veiculo v2) {
        return (int) (v2.getKms_totais()-v1.getKms_totais());
    }
}
