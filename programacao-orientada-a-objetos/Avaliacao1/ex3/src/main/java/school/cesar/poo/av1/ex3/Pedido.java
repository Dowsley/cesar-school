package school.cesar.poo.av1.ex3;

import java.util.List;
import java.util.ArrayList;
import java.util.Date;

public class Pedido {
    private Date date;
    private Cliente cliente;
    private List<Produto> produtos = new ArrayList<Produto>();
    private Restaurante restaurante;

    public double valorTotal() {
        double tmp = 0;
        for (Produto p : produtos) {
            tmp += p.getValor();
        }
        return tmp;
    }


    public Date getDate() {
        return this.date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public Cliente getCliente() {
        return this.cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    public List<Produto> getProdutos() {
        return this.produtos;
    }

    public void setProdutos(List<Produto> produtos) {
        this.produtos = produtos;
    }

    public Restaurante getRestaurante() {
        return this.restaurante;
    }

    public void setRestaurante(Restaurante restaurante) {
        this.restaurante = restaurante;
    }
}