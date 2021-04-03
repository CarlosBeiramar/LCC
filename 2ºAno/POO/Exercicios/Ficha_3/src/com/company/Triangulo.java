package com.company;

import java.awt.*;

public class Triangulo {

    private Ponto ponto1;
    private Ponto ponto2;
    private Ponto ponto3;

    public Triangulo(){
        this.ponto1 = new Ponto();
        this.ponto2 = new Ponto();
        this.ponto3 = new Ponto();
    }

    public Triangulo(Ponto p1, Ponto p2, Ponto p3){
        this.ponto1 = p1.clone();
        this.ponto2 = p2.clone();
        this.ponto3 = p3.clone();
    }

    public Triangulo(Triangulo t){
        this.ponto1 = t.getPonto1();
        this.ponto2 = t.getPonto2();
        this.ponto3 = t.getPonto3();
    }

    public Ponto getPonto1() {
        return this.ponto1.clone();
    }

    public Ponto getPonto2() {
        return this.ponto2.clone();
    }

    public Ponto getPonto3() {
        return this.ponto3.clone();
    }

    public void setPonto1(Ponto ponto1) {
        this.ponto1 = ponto1.clone();
    }

    public void setPonto2(Ponto ponto2) {
        this.ponto2 = ponto2.clone();
    }

    public void setPonto3(Ponto ponto3) {
        this.ponto3 = ponto3.clone();
    }

    public Triangulo clone(){
        return new Triangulo(this);
    }

    public String toString(){
        return "Ponto_1:" + this.ponto1.toString() + "\nPonto_2" + this.ponto2.toString() + "\nPonto_3" + this.ponto3.toString();
    }

    public boolean equals(Object o){
        if (this == o){
            return true;
        }
        if (o == null || o.getClass()!=this.getClass())
            return false;
        Triangulo t = (Triangulo) o;

        return (this.ponto1 == t.getPonto1() && this.ponto2 == t.getPonto2() && this.ponto3 == t.getPonto3());
    }
}
