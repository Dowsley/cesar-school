package school.cesar.poo.av1.ex3;
import java.util.List;
import java.util.ArrayList;

public class Cliente extends Usuario {
    private List<Pedido> pedidos = new ArrayList<Pedido>();

    public List<Pedido> getPedidos() {
        return this.pedidos;
    }

    public void setPedidos(List<Pedido> pedidos) {
        this.pedidos = pedidos;
    }
}