package lista2.ex1;

public class Ex1 {
        public static void main(String[] args) {
                Aluno p1 = new Aluno("Larissa", "100.200.300-40", 19);
                Aluno p2 = new Aluno("Joao","100.200.300-40", 20);
                System.out.println(p1.equals(p2));
                System.out.println(p1 == p2);

                Responsavel r1 = new Responsavel("Cain", "999.999.999-99", 200);
                r1.setOcupacao(new Ocupacao("Professor de Pastoragem"));
                Responsavel r2 = new Responsavel("Abel", "666.666.666-66", 300);
                r2.setOcupacao(new Ocupacao("Professor de Agricultura"));

                System.out.println(r1.getOcupacao().equals(r2.getOcupacao()));
        }
}