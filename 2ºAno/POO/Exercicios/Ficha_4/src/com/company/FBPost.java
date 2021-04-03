package com.company;

import java.time.LocalDateTime;
import java.util.ArrayList;

public class FBPost{
    private int identificador;
    private String nome;
    private LocalDateTime data;
    private String conteudo;
    private int num_likes;
    private ArrayList<String> comentarios;

    public FBPost(){
        this.identificador = 0;
        this.nome = "";
        this.data=LocalDateTime.now();
        this.conteudo = "";
        this.num_likes = 0;
        this.comentarios = new ArrayList<String>();
    }

    public FBPost(int id,String name, LocalDateTime date, String conteudo1, int num_likes1,ArrayList comments){
        this.identificador = id;
        this.nome = name;
        this.data = date;
        this.conteudo = conteudo1;
        this.num_likes = num_likes1;
        setComentario(comments);
    }

    public FBPost(FBPost fb){
        this.identificador = fb.getIdentificador();
        this.nome = fb.getNome();
        this.data = fb.getData();
        this.conteudo = fb.getConteudo();
        this.num_likes = fb.getNumLikes();
        this.comentarios = fb.getComentarios();
    }

    public int getIdentificador(){
        return this.identificador;
    }

    public String getNome(){
        return this.nome;
    }

    public LocalDateTime getData(){
        return this.data;
    }

    public String getConteudo(){
        return this.conteudo;
    }

    public int getNumLikes(){
        return this.num_likes;
    }

    public ArrayList<String> getComentarios(){
        ArrayList<String> novo = new ArrayList<String>();
        for (String c:this.comentarios){
            novo.add(c);
        }
        return novo;
    }

    public void setIdentificador(int id){
        this.identificador = id;
    }

    public void setNome(String name){
        this.nome = name;
    }

    public void setData(LocalDateTime date){
        this.data = date;
    }

    public void setConteudo(String conteudo1){
        this.conteudo = conteudo1;
    }

    public void setNumLikes(int num_likes1){
        this.num_likes = num_likes1;
    }

    public void setComentario(ArrayList<String> c){
        this.comentarios = new ArrayList<String>();
        for (String cmt : c){
            this.comentarios.add(cmt);
        }
    }

    public FBPost clone(){
        return new FBPost(this);
    }

    public boolean equals(Object o){
        if(o==this) return true;
        if(o==null || o.getClass() != this.getClass()) return false;
        FBPost fb = (FBPost) o;
        return fb.getConteudo().equals(this.getConteudo()) && fb.getNome().equals(this.getNome()) && fb.getNumLikes() == this.getNumLikes() ;
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Identificador: ").append(this.identificador);
        sb.append("Nome: ").append(this.nome);
        sb.append("Numero de likes: ").append(this.num_likes);
        sb.append("Conteudo: ").append(this.conteudo);
        return sb.toString();
    }
}