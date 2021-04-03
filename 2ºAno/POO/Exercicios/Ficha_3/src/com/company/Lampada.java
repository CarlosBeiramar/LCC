package com.company;

public class Lampada {
    private int estado; // 1 ligado, 0 desligado, 2 eco
    private double consumo; //6 watts, 0 watts, 3 watts
    private double consumo_total;
    private double periodconsumo;

    public Lampada(){
        this.estado = 0;
        this.consumo = 0;
    }

    public Lampada(int estado1,double consumo1){
        this.estado = estado1;
        this.consumo = consumo1;
    }

    public Lampada(Lampada l){
        this.estado = l.getEstado();
        this.consumo = l.getConsumo();
    }

    public double getConsumo() {
        return consumo;
    }

    public void setConsumo(double consumo) {
        this.consumo = consumo;
    }

    public int getEstado() {
        return estado;
    }

    public void setEstado(int estado) {
        this.estado = estado;
    }

    public void lampON(){
        this.estado = 1;
        this.consumo = 6;
    }

    public void lampOFF(){
        this.estado= 0;
        this.consumo = 0;
    }

    public void lampECO(){
        this.estado = 2;
        this.consumo = 3;
    }

    @Override
    public boolean equals(Object obj) {
      if (this == obj){
          return true;
      }
      if(obj == null || obj.getClass()!=this.getClass()){
          return false;
      }
      Lampada l = (Lampada) obj;
      return (this.estado == l.getEstado() && this.consumo == l.getConsumo());
    }

    public Lampada clone(){
        return new Lampada(this);
    }
}
