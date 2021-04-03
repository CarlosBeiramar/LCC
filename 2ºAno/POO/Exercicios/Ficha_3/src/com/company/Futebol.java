package com.company;

public class Futebol {
    private int estado; //0 - por iniciar , 1 - a decorrer, 2 - terminado
    private int GoloVisitante;
    private int GoloVisitado;
    private String visitado;
    private String visitante;

    public Futebol(){
        this.estado = 0;
        this.visitado = "";
        this.visitante = "";
        this.GoloVisitado = 0;
        this.GoloVisitante = 0;
    }

    public Futebol(int estado1,String visitado1,String visitante1,int goloVisitado,int goloVisitante){
        this.estado = estado1;
        this.visitado = visitado1;
        this.visitante = visitante1;
        this.GoloVisitado = goloVisitado;
        this.GoloVisitante = goloVisitante;
    }

    public Futebol(Futebol f){
        this.estado = f.getEstado();
        this.visitado =f.getVisitado();
        this.visitante = f.getVisitante();
        this.GoloVisitado = f.getGoloVisitado();
        this.GoloVisitante = f.getGoloVisitante();
    }

    public int getEstado(){
        return this.estado;
    }

    public String getVisitado(){
        return this.visitado;
    }

    public String getVisitante(){
        return this.visitante;
    }

    public int getGoloVisitante(){
        return this.GoloVisitante;
    }

    public int getGoloVisitado(){
        return this.GoloVisitado;
    }

    public void setGoloVisitante(int gVis){
        this.GoloVisitante=gVis;
    }

    public void setGoloVisitado(int gVisitado){this.GoloVisitado = gVisitado;}

    public void setEstado(int e){
        this.estado= e;
    }

    public void setVisitado(String v){
        this.visitado = v;
    }

    public void setVisitante(String v){
        this.visitante = v;
    }


    public void startGame(){
        this.estado = 1;
    }

    public void endGame(){
        this.estado = 2;
    }

    public void addgoloVisitado(){
        this.GoloVisitado = this.GoloVisitado +1;
    }

    public void addgoloVisitante(){
        this.GoloVisitante = this.GoloVisitante +1;
    }

    public String resultadoActual() {
        System.out.println("Resultado: " + this.visitado+" " + this.GoloVisitado +" "+ "-" +" "+ this.GoloVisitante +" "+ this.visitante+" ");
        return "Resultado: " + this.visitado+" " + this.GoloVisitado +" "+ "-" +" "+ this.visitante+" "+ this.GoloVisitante;
    }
}
