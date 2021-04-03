package com.company;

public class Circulo {
    private double raio;
    private double X;
    private double Y;

    public Circulo(){
        this.raio = 0;
        this.X = 0;
        this.Y = 0;
    }

    public Circulo(double raio2, double X2,double Y2){
        this.raio=raio2;
        this.X=X2;
        this.Y=Y2;
    }

    public Circulo(Circulo c){
        this.raio = c.getRaio();
        this.X = c.getX();
        this.Y = c.getY();
    }

    public double getX(){
        return this.X;
    }

    public double getY(){
        return this.Y;
    }

    public double getRaio(){
        return this.raio;
    }

    public void SetX(double novoX){
        this.X = novoX;
    }

    public void SetY(double novoY){
        this.Y = novoY;
    }

    public void SetRaio(double novoR){
        this.raio=novoR;
    }

    public void alteraCentro(double x, double y){
        this.X = x;
        this.Y = y;
    }

    public double calculaArea(){
        System.out.print("area =" + Math.PI * this.raio + "\n");
        return Math.PI * this.raio;
    }

    public double calculaPerimetrio(){
        System.out.print("perímetro = " + Math.PI * 2 * this.raio);
        return Math.PI * 2 * this.raio;
    }


    public String toString(){
        System.out.print("(x =" + this.X + ",y = " + this.Y + ")");
        return "(x =" + this.X + ",y = " + this.Y + ")";
    }

    public Circulo clone(){
        return new Circulo(this);
    }

}
