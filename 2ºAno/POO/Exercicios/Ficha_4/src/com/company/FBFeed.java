package com.company;

import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;
import java.util.Comparator;

public class FBFeed{
    private List<FBPost> lista;

    public FBFeed(){
        this.lista = new ArrayList<FBPost>();
    }

    public FBFeed(List<FBPost> list){
        this.lista= list.stream().map(FBPost::clone).collect(Collectors.toList());
    }

    public FBFeed(FBFeed e){
        this.lista = e.getFBFeed();
    }

    public ArrayList<FBPost> getFBFeed(){
        ArrayList<FBPost> novo = new ArrayList<FBPost>();
        for (FBPost c:this.lista){
            novo.add(c.clone());
        }
        return novo;
    }

    public void setFBFeed(ArrayList<FBPost> ls){
        this.lista = new ArrayList<FBPost>();
        for(FBPost c : ls){
            this.lista.add(c.clone());
        }
    }

    /*
        Determina o número de posts de um user
     */

    public int nrPosts(String user){
        int conta=0;
        for (FBPost s:this.lista){
            if (s.getNome().equals(user)){
                conta++;
            }
        }
        return conta;
    }

    /*
    Determinar a lista de posts de um user
     */

    public List<FBPost> postsOf(String user){
        ArrayList<FBPost> aux = new ArrayList<FBPost>();
        for (FBPost s : this.lista){
            if (s.getNome().equals(user)){
                aux.add(s.clone());
            }
        }
        return aux;
    }

    /*
        Determinar a lista de posts de um user num determinado intervalor de tempo
     */

    public List<FBPost> postsOF(String user, LocalDateTime inicio, LocalDateTime Fim){
        ArrayList<FBPost> aux = new ArrayList<FBPost>();
        for (FBPost s:this.lista){
            if(s.getNome().equals(user)){
                if(s.getData().isAfter(inicio) && s.getData().isBefore(Fim)){
                    aux.add(s.clone());
                }
            }
        }
        return aux;
    }

    /*
           obter um post dado o seu identificador
     */

    public FBPost getPost(int id) {
        FBPost x = new FBPost();
        for (FBPost s : this.lista) {
            if (s.getIdentificador() == id) {
                x=s.clone();
            }
        }
        return x;
    }

    /*
            inserir um comentario num post
     */

    public void comment (FBPost post, String comentario){
        for (FBPost s:this.lista){
            if (s.equals(post)){
                s.getComentarios().add(comentario);
            }
        }
    }

    /*
        Adicionar um like a um post
     */

    public void like(FBPost post){
        for (FBPost s:this.lista){
            if(s.equals(post)){
                s.setNumLikes(s.getNumLikes()+1);
            }
        }
    }

    /*
        adicionar um like a um post
     */

    public void like1(int postid){
        for (FBPost s:this.lista){
            if(s.getIdentificador()==postid){
                s.setNumLikes(s.getNumLikes()+1);
            }
        }
    }


    /*
        determinar uma lista dos 5 posts com mais comentarios

     */

    public List<Integer> top5Comments(){
        ArrayList<Integer> lista = new ArrayList<>();
        Comparator<FBPost> comp = new CommentComparator();
        Collections.sort(this.lista,comp);
        int x=0;
        while(x<5){
            lista.add(this.lista.get(x).getIdentificador());
            x++;
        }
        return lista;
    }
}
