package com.company;
import java.util.ArrayList;
import java.util.List;

public class CasaInteligente {
    private List<Lampada> lampadas;

    public CasaInteligente(){
        lampadas = new ArrayList<Lampada>();
    }

    public CasaInteligente(List<Lampada> lampadas){
        setLampadas(lampadas);
    }

    public CasaInteligente(CasaInteligente ci){
        setLampadas(ci.getLampadas());
    }

    private void setLampadas(List<Lampada> ls){
        this.lampadas = new ArrayList<>();
        for (Lampada l: ls){
            this.lampadas.add(l.clone());
        }
    }
    /*
    private void setLampadasInternalIterator(List<Lampada> ls){
        this.lampadas = ls.stream().map(Lampada::clone).collect(Collectors.toList());
        }
     */

    public List<Lampada> getLampadasExternalIterator() {
        ArrayList<Lampada> aux = new ArrayList<>();
        for (Lampada l: this.lampadas){
            aux.add(l.clone());
        }
        return aux;
    }

    public List<Lampada> getLampadas(){
        return getLampadasExternalIterator();
    }

    public CasaInteligente clone(){
        return new CasaInteligente(this);
    }

    public String toString(){
        return "CasaInteligente{" + "lampadas=" + lampadas.toString();
    }

    public boolean equals(Object o){
        if (this==o)return true;
        if (o == null || o.getClass() != this.getClass()) return false;

        CasaInteligente p = (CasaInteligente) o;

        return this.lampadas.equals(p.getLampadas());
    }

    public void addLampada(Lampada l){
        this.lampadas.add(l.clone());
    }

    public void ligaLampadaNormal(int index){
        this.lampadas.get(index).lampON();
    }

    public void ligaLampadaECO(int index){
        this.lampadas.get(index).lampECO();
    }

    public void desligaLampada(int index){
        this.lampadas.get(index).lampOFF();
    }

    private void ligaTodasECO(){
        this.lampadas.stream().forEach(l->l.lampECO());
    }

    /*public double consumoTotal(){
        return (double) this.lampadas.stream().mapToDouble((Lampada::totalConsumo).sum());
    }*/


}
