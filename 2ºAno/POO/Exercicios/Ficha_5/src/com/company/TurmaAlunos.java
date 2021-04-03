package com.company;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class TurmaAlunos {

    private Map<String,Aluno> alunos;
    private String nome;
    private String codigo;

    public TurmaAlunos(){
        this.nome = new String();
        this.codigo = new String();
        this.alunos = new HashMap<>();
        //this.alunos = new HashMap<String,Aluno>(); podemos fazer assim mas nao é necessario pq ja temos o tipo definido inicialmente
    }

    public TurmaAlunos(Map<String,Aluno> alunos1,String nome1,String codigo1){
        this.nome = nome1;
        this.codigo = codigo1;
        setAlunos(alunos1);
    }

    public TurmaAlunos (TurmaAlunos t){
        this.nome = t.getNome();
        this.codigo = t.getCodigo();
        setAlunos(t.getAlunos());
    }

    public String getNome() {
        return this.nome;
    }

    public String getCodigo() {
        return this.codigo;
    }

    public Map<String,Aluno> getAlunos(){
        Map<String,Aluno> ret = new HashMap<>();
        for(Map.Entry<String,Aluno> e: this.alunos.entrySet()){
            ret.put(e.getKey(),e.getValue().clone());
        }
        return ret;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public void setAlunos(Map<String, Aluno> als) {
        this.alunos = new HashMap<>();
        als.entrySet().forEach(e ->this.alunos.put(e.getKey(),e.getValue().clone()));
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Turma:\n").append(this.nome).append("\n")
                .append(this.codigo).append("\n")
                .append(this.alunos).append("\n");
        return sb.toString();
    }

    public boolean equals(Object o){
        if (o==this) return true;
        if(o==null || o.getClass()!=this.getClass()) return false;

        TurmaAlunos t = (TurmaAlunos) o;
        return this.nome.equals(t.getNome()) && this.codigo.equals(t.getCodigo()) && this.alunos.equals(t.getAlunos());
    }


    public TurmaAlunos clone(){
        return new TurmaAlunos(this);
    }

    public int compareTo(TurmaAlunos t){
        return this.nome.compareTo(t.getNome());
    }

    public void insereAlunos(Aluno a){
        this.alunos.put(a.getNumero(),a.clone());
    }

    public Aluno getAluno(String codAluno){
        return this.alunos.get(codAluno).clone();
    }

    public void removeAluno(String codAluno){
        this.alunos.remove(codAluno);
    }

    public Set<String> todosOsCodigos(){
        return new TreeSet<>(this.alunos.keySet());
    }

    public int qtsAlunos(){
        return this.alunos.size();
    }

    public Set<Aluno> alunosOrdemAlfabeticaStream(){
        return this.alunos.values().stream()
                .map(Aluno::clone)
                .collect(Collectors.toCollection(TreeSet::new));
    }

    public Set<Aluno> alunosOrdemAlfabetica(){
        Set<Aluno> ret = new TreeSet<>();
        for (Aluno a : this.alunos.values()){
            ret.add(a.clone());
        }
        return ret;
    }

    public Set<Aluno> alunosOrdemDescrescenteNumero(){
        Set<Aluno> ret = new TreeSet<>(new ComparatorAlunoNumero());
        for (Aluno a : this.alunos.values()){
            ret.add(a.clone());
        }
        return ret;
    }
}
