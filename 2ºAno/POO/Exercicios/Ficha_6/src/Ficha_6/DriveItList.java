package Ficha_6;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class DriveItList implements Serializable {
    private Map<String,Veiculo> veiculos;
    private static Map<String,Comparator<Veiculo>> comps = new HashMap<>();

    public DriveItList(){
        this.veiculos = new HashMap<>();
    }

    public DriveItList(HashMap<String,Veiculo> veiculos1){
        setVeiculos(veiculos1);
    }

    public DriveItList(DriveItList d){
        setVeiculos(d.getVeiculos());
    }

    public Map<String, Veiculo> getVeiculos() {
        Map<String,Veiculo> aux= new HashMap<>();
        for (Map.Entry<String,Veiculo> v:this.veiculos.entrySet()){
            aux.put(v.getKey(),v.getValue().clone());
        }
        return aux;
    }

    public void setVeiculos(Map<String, Veiculo> veiculos) {
        this.veiculos = new HashMap<String,Veiculo>();
        veiculos.entrySet().forEach(e->{this.veiculos.put(e.getKey(),e.getValue().clone());});
    }

    /*
        a) Método que verifica se um carro existe
     */

    public boolean existeVeiculo(String cod){
        return this.veiculos.containsKey(cod);
    }

    /*
        b) Quantidade de veículos existentes
     */

    public int quantos(){
        return this.veiculos.size();
    }

    /*
        c) Método que devolve o número de veículos de uma marca
     */

    public int quantos(String marca){
       return (int) this.veiculos.values().stream().filter(e -> e.getMarca().equals(marca)).count();
    }

    /*
        d) Devolver a informação de um veículo
     */

    public Veiculo getVeiculo(String cod){
        if (existeVeiculo(cod)) {
            return this.veiculos.get(cod).clone();
        }else{
            System.out.println("Não existe nenhum carro com esse código");
            return null;
        }
    }

    /*
        e) Adicionar um novo veiculo
     */

    public void adiciona(Veiculo v){
        this.veiculos.put(v.getCodigo(),v.clone());
    }

    /*
        f) devolver uma lista contendo a cópia de todos veiculos
     */

    public List<Veiculo> getVeiculos1(){
        return this.veiculos.values().stream().map(Veiculo::clone).collect(Collectors.toList());
    }
     /*
         g) Adicionar veiculos
      */

     public void adiciona(Set<Veiculo> vs){
         for (Veiculo v:vs){
             adiciona(v);
         }
     }

     /*
        h) Registar um aluguer de um veículo
      */

     public void registarAluguer(String codVeiculo,int numkms){
         Veiculo x  = getVeiculo(codVeiculo);
         x.setKms_totais( x.getKms_totais() + numkms);
         adiciona(x);
     }

     /*
        i) Classificar um veículo quando o cliente termina o aluguer
      */

     public void classificarVeiculo(String cod, int classificacao){
         Veiculo x = getVeiculo(cod);
         x.setClassificacao(x.getClassificacao() +1);
         x.setnClientes_que_classificou(x.getnClientes_que_classificou()+1);
         adiciona(x);
     }

     /*
        j) Calcula o custo real
      */

     public int custoRealKm(String cod){
         Veiculo x = getVeiculo(cod);
         if(x!=null){return (int) x.custoReal_km();}
         else{return 0;}
     }

    public DriveItList clone(){
        return new DriveItList(this);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(this.veiculos.values().toString());

        return sb.toString();
    }

    public boolean equals(Object o){
        if (o == this){return true;}
        if (o==null || o.getClass() != this.getClass()) return false;

        DriveItList d = (DriveItList) o;
        return d.equals(this);
    }


    /**
     *****************************FASE 2
     */

    // a)

    public Set<Veiculo> ordenarVeiculos(){
        Set<Veiculo> veiculos_ord = new TreeSet<>(new BrandComparator());
        for (Veiculo v:this.veiculos.values()){
            veiculos_ord.add(v.clone());
        }
        return veiculos_ord;
    }

    //  b)

    public List<Veiculo> ordenarVeiculosList(){
        List<Veiculo> veiculos_ord = new ArrayList<>();
        for (Veiculo v:this.veiculos.values()){
            veiculos_ord.add(v.clone());
        }
        Collections.sort(veiculos_ord,new BrandComparator());
        return veiculos_ord;
    }

    // c) Por kms percorridos

    public Set<Veiculo> ordenarVeiculos2(Comparator<Veiculo> c){
        Set<Veiculo> veiculos_ord = new TreeSet<>(c);
        for (Veiculo v:this.veiculos.values()){
            veiculos_ord.add(v.clone());
        }
        return veiculos_ord;
    }


    // d)
    public void guarda_comps(String s,Comparator<Veiculo> c){
        comps.put(s,c);
    }


    // e)

    public Iterator<Veiculo> ordenarVeiculo2(String criterio){
        Set<Veiculo> s = new TreeSet<>(comps.get(criterio));
        for (Veiculo v : this.veiculos.values()){
            s.add(v.clone());
        }
        return s.iterator();
    }

    // FASE 3

    //c)
    public List<BonificaKms> daoPontos(){
        List<BonificaKms> x = new ArrayList<>();
        for (Veiculo p : this.veiculos.values()){
            if ( p instanceof VeiculosPremium || p instanceof AutocarroInteligente){
                x.add((BonificaKms) p.clone());
            }
        }
        return x;
    }

    //FASE 4

    //a)
    public void gravaCSV() throws FileNotFoundException{
        try(PrintWriter writer = new PrintWriter(new File("dados.csv"))){
            StringBuilder sb = new StringBuilder();
            for (Veiculo v : this.veiculos.values()){
                sb.append(v.toString());
                sb.append("\n");
            }
            writer.write(sb.toString());
            System.out.println("Escreveu!");
        }catch (FileNotFoundException e){
            e.getMessage();
        }
    }

    //b)

    public void grava_em_ficheiro() throws FileNotFoundException, IOException{
        try {
            FileOutputStream fos = new FileOutputStream("dados.obj");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(this.veiculos);
            oos.flush();
            oos.close();

        }catch (IOException e){
            e.printStackTrace();
        }
    }

    //c)
    public static DriveItList leFicheiro() throws FileNotFoundException, IOException, ClassCastException, ClassNotFoundException {
        FileInputStream fis = new FileInputStream("dados.obj");
        ObjectInputStream ois = new ObjectInputStream(fis);
        DriveItList d = (DriveItList) ois.readObject();
        ois.close();
        return d;
    }

    public boolean VeiculoInexistenteEx(String cod) throws VeiculoInexistenteEx{
        if(!this.veiculos.containsKey(cod)) throw new VeiculoInexistenteEx("O veículo não existe.");
        else{
            return true;
        }
    }

    public boolean AddVeiculoExist(Veiculo v) throws AddVeiculoExist{
        if(this.veiculos.containsKey(v.getCodigo())) {
            throw new AddVeiculoExist("O veículo já exite.");
        }else{
            return true;
        }
    }
}