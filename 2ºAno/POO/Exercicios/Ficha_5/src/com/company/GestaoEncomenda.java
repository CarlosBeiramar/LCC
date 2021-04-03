package com.company;

import java.time.LocalDateTime;
import java.util.*;

public class GestaoEncomenda {
    private Map<String,Encomenda> encomendas;
    private String nome;

    public GestaoEncomenda(){
        this.encomendas = new HashMap<>();
        this.nome = new String();
    }

    public GestaoEncomenda(Map<String,Encomenda> encomendas1,String nome1){
        setEncomendas(encomendas1);
        this.nome = nome1;
    }

    public GestaoEncomenda(GestaoEncomenda t){
        setEncomendas(t.getEncomendas());
        this.nome = t.getNome();
    }

    public Map<String, Encomenda> getEncomendas() {
        Map<String,Encomenda> res = new HashMap<>();
        for (Map.Entry<String,Encomenda> e : this.encomendas.entrySet()){
            res.put(e.getKey(),e.getValue().clone());
        }
        return res;
    }

    /*
    public Map<String,Encomenda> getEncomendas2(){
        Map<String,Encomenda> res = new HashMap<>();
        this.encomendas.entrySet().forEach(e->res.put(e.getKey(),e.getValue().clone());
        return res;
     }
     */

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setEncomendas(Map<String, Encomenda> encomendas) {
        this.encomendas = new HashMap<String,Encomenda>();
        encomendas.entrySet().forEach(e->this.encomendas.put(e.getKey(),e.getValue().clone()));
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this)return true;
        if( obj== null || obj.getClass()!=this.getClass()) return false;

        GestaoEncomenda a = (GestaoEncomenda) obj;

        return this.nome.equals(a.getNome());
    }

    public GestaoEncomenda clone(){
        return new GestaoEncomenda(this);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append(this.nome).append(":\n").append(this.encomendas);
        return sb.toString();
    }

    /*
        método que determina os códigos de encomenda existentes
     */

    public Set<String> todosCodigosEnc(){
        return new TreeSet<>(this.encomendas.keySet());
    }

    /*
        adiciona mais uma encomenda ao sistema
     */

    public void addEncomenda(Encomenda enc){
        this.encomendas.put(enc.getReferencia(),enc.clone());
    }

    /*
        dado um codigo devolve a informacao respetiva
     */

    public Encomenda getEncomenda(String codEnc){
        return this.encomendas.get(codEnc).clone();
    }

    /*
        remove uma encomenda dado o seu codigo
     */
    public void removeEncomenda(String codEnc){
        this.encomendas.remove(codEnc);
    }

    /*
        encomenda com mais produtos encomendados
     */

    public String encomendaComMaisProdutos(){
        int res = 0;
        String x = new String();
        for(Map.Entry<String,Encomenda> e:this.encomendas.entrySet()){
            if (e.getValue().getQuantidade()>res){
                res = e.getValue().getQuantidade();
                x = e.getValue().getReferencia();
            }
        }
        return x;
    }

    /*
        metodo que determinas todas as encomendas em que um determinado produto, identificado pelo codigo, esta presente
     */

    public Set<String> encomendasComProduto(String codProd){
        Set<String> res = new TreeSet<String>();
        for(Map.Entry<String,Encomenda> e: this.encomendas.entrySet()){
            if (e.getValue().getReferencia().equals(codProd)){
                res.add(e.getValue().getReferencia());
            }
        }
        return res;
    }

    /*
        deteermina todas as encomendas com data posterior a uma data fornecida como parametro
     */

    public Set<String> encomendasAposData(LocalDateTime d){
        Set<String> res = new TreeSet<>();
        for (Map.Entry<String,Encomenda> e:this.encomendas.entrySet()){
            if(e.getValue().getData().isAfter(d)){
                res.add(e.getValue().getReferencia());
            }
        }
        return res;
    }

    /*
        metodo que devolve uma ordenacao por ordem descrescente do valor
     */

    public Set<Encomenda> encomendasValorDescresente(){
        Set<Encomenda> res = new TreeSet<>(new ComparatorPreco());
        for(Encomenda a : this.encomendas.values()){
            res.add(a.clone());
        }
        return res;
    }

    /*
        metodo que calcula um map em que associa cada codigo de produto a lista das encomendas em que foi referida
     */

}
