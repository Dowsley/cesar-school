package lista1.ex4;
public class Cilindro {
    
    public Circulo base;
    public double altura;

    public double volume() {
        return base.area() * altura;
    }

}