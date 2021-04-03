package com.company;

import java.util.Comparator;

public class ComparatorPreco implements Comparator<Encomenda> {
    public int compare(Encomenda a, Encomenda b){
        if (a.getPreco()>b.getPreco()) return 1;
        if (a.getPreco()<b.getPreco()) return -1;
        return 0;
    }
}
