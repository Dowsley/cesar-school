package lista1.ex4;

public class Ex4 {
    public static void main(String[] args) {
        Cilindro cil1 = new Cilindro();
        cil1.base = new Circulo();
        cil1.base.raio = 10d;
        cil1.altura = 20d;
        System.out.println(cil1.volume());
    }
}