package school.cesar.poo.av1.ex3;
import java.util.List;
import java.util.ArrayList;

public class Restaurante {
    private String nome;
    private List<Vendedor> vendedores = new ArrayList<Vendedor>();
    private List<Produto> produtos = new ArrayList<Produto>();

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public List<Vendedor> getVendedores() {
        return this.vendedores;
    }

    public void setVendedores(List<Vendedor> vendedores) {
        this.vendedores = vendedores;
    }

    public List<Produto> getProdutos() {
        return this.produtos;
    }

    public void setProdutos(List<Produto> produtos) {
        this.produtos = produtos;
    }
}
