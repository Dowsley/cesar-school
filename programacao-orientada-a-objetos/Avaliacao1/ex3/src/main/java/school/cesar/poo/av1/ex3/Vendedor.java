package school.cesar.poo.av1.ex3;
import java.util.List;
import java.util.ArrayList;

public class Vendedor {
    private List<Restaurante> restaurantes = new ArrayList<Restaurante>();

    public List<Restaurante> getRestaurantes() {
        return this.restaurantes;
    }

    public void setRestaurantes(List<Restaurante> restaurantes) {
        this.restaurantes = restaurantes;
    }
}