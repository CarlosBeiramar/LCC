package Ficha_6;

import java.util.Comparator;

public class BrandComparator implements Comparator<Veiculo> {
    public int compare (Veiculo v1,Veiculo v2){
         int x = v1.getMarca().compareTo(v2.getMarca());
         if (x == 0){
             return v1.getModelo().compareTo(v2.getModelo());
         }else {
             return x;
         }
    }
}
