package com.company;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Telemovel {
    private String marca;
    private String modelo;
    private double resolucaoX;
    private double resolucaoY;
    private int dimensaoMensagens;
    private String[] mensagens;
    private int dimensaoFotos;
    private int dimensaoAPPS;
    private byte espacoOcupado;
    private byte espacototal;
    private int fotosGuardadas;
    private int AppsInstaladas;
    private String[] nomeAPPS;

    public Telemovel(){
        this.marca = "";
        this.modelo = "";
        this.resolucaoX = 0;
        this.resolucaoY = 0;
        this.dimensaoMensagens = 0;
        this.mensagens = new String[dimensaoMensagens];
        this.dimensaoFotos = 0;
        this.dimensaoAPPS = 0;
        this.espacoOcupado = 0;
        this.espacototal = 0;
        this.fotosGuardadas = 0;
        this.AppsInstaladas = 0;
        this.nomeAPPS = new String[this.AppsInstaladas];
    }

    public Telemovel(String marca1,String[] mensagens1,String modelo1,double resolucaoX1,double resolucaoY1,int dimensaoMensagens1,int dimensaoFotos1,int dimensaoAPPS1,byte espacoOcupado1,byte espacototal1,int fotosGuardadas1,int AppsInstaladas1,String[] nomeAPPS1){
        this.marca = marca1;
        this.modelo = modelo1;
        this.resolucaoX = resolucaoX1;
        this.resolucaoY = resolucaoY1;
        this.dimensaoMensagens = dimensaoMensagens1;
        this.mensagens = new String[dimensaoMensagens1];
        System.arraycopy(mensagens1,0,this.mensagens,0,mensagens1.length);
        this.dimensaoFotos = dimensaoFotos1;
        this.dimensaoAPPS = dimensaoAPPS1;
        this.espacoOcupado = espacoOcupado1;
        this.espacototal = espacototal1;
        this.fotosGuardadas = fotosGuardadas1;
        this.AppsInstaladas = AppsInstaladas1;
        this.nomeAPPS = new String[nomeAPPS1.length];
        System.arraycopy(nomeAPPS1,0,this.nomeAPPS,0,nomeAPPS1.length);

    }

    public Telemovel(Telemovel t){
        this.marca = t.getMarca();
        this.modelo = t.getModelo();
        this.resolucaoX = t.getResolucaoX();
        this.resolucaoY = t.getResolucaoY();
        this.dimensaoMensagens = t.getDimensaoMensagens();
        this.dimensaoAPPS = t.getDimensaoAPPS();
        this.dimensaoFotos = t.getDimensaoFotos();
        this.dimensaoAPPS = t.getDimensaoAPPS();
        this.espacoOcupado = t.getEspacoOcupado();
        this.espacototal = t.getEspacototal();
        this.fotosGuardadas = t.getFotosGuardadas();
        this.AppsInstaladas = t.getAPPSinstaladas();
        this.nomeAPPS = t.getNomeAPPS();
    }


    public String[] getMensagens() {
        return mensagens;
    }

    public void setMensagens(String[] mensagens) {
        this.mensagens = mensagens;
    }

    public String[] getNomeAPPS() {
        String[] nome = new String[this.AppsInstaladas];
        System.arraycopy(nome,0,this.nomeAPPS,0,this.AppsInstaladas);
        return nome;
    }

    public void setNomeAPPS(String[] nomeAPPS1) {
        this.nomeAPPS = new String[nomeAPPS1.length];
        for (int i=0; i<nomeAPPS1.length; i++){
            System.arraycopy(this.nomeAPPS,0,nomeAPPS1,0,nomeAPPS1.length);
        }
    }

    public String getMarca(){return this.marca;}
    public void SetMarca (String novamarca){this.marca = novamarca;}

    public String getModelo(){return this.modelo;}
    public void SetModelo(String modelonovo){this.modelo=modelonovo;}

    public double getResolucaoX(){return this.resolucaoX;}
    public void SetResolucaoX(double novaresolucaoX){this.resolucaoX = novaresolucaoX;}

    public double getResolucaoY(){return this.resolucaoY;}
    public void SetResolucaoY(double novaresolucaoY){this.resolucaoY = novaresolucaoY;}

    public int getDimensaoMensagens(){return this.dimensaoMensagens;}
    public void SetDimensaoMensagens(int novaDim){this.dimensaoMensagens = novaDim;}

    public int getDimensaoFotos(){return this.dimensaoFotos;}
    public void setDimensaoFotos(int novaDimensaoFotos){this.dimensaoFotos = novaDimensaoFotos;}

    public int getDimensaoAPPS(){return this.dimensaoAPPS;}
    public void setDimensaoAPPS(int novadimensaoAPPS){this.dimensaoAPPS = novadimensaoAPPS;}

    public byte getEspacoOcupado(){return this.espacoOcupado;}
    public void setEspacoOcupado(byte novoespacoocupado){this.espacoOcupado = novoespacoocupado;}

    public byte getEspacototal(){return this.espacototal;}
    public void setEspacototal(byte espacototal){this.espacototal = espacototal;}

    public int getFotosGuardadas(){return this.fotosGuardadas;}
    public void setFotosGuardades(int novoFotosGuardadas){this.fotosGuardadas = novoFotosGuardadas;}

    public int getAPPSinstaladas(){return this.AppsInstaladas;}
    public  void setAPPsintaladas(int novoappsinstaladas){this.AppsInstaladas = novoappsinstaladas;}

    public boolean existeEspaco(int numeroBytes){
        byte numero_bytes = (byte) numeroBytes;
        return numero_bytes + this.espacoOcupado < this.espacototal;
    }

    public void instalaApp(String nome, int tamanho){
        int espaco_disponivel = (int) this.espacototal - this.espacoOcupado;
        if (tamanho < espaco_disponivel){
            this.AppsInstaladas +=1;
            this.nomeAPPS[AppsInstaladas] = nome;
        }
    }

    public void recebeMsg(String msg){

    }


}
