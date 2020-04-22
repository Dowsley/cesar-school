package lista1.ex1;

public class Ex1 {
    public static void main(String[] args) {
        Circulo c1 = new Circulo();
        c1.raio = 10d;
        System.out.println(c1.area());
        
        Quadrado q1 = new Quadrado();
        q1.altura = 10d;
        q1.largura = 10d;
        System.out.println(q1.area());
    }
}