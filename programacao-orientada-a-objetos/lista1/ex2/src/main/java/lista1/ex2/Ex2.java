package lista1.ex2;

import java.math.BigDecimal;

public class Ex2 {
	public static void main(String[] args) {
		Cliente c1 = new Cliente();
		c1.nome = "Fulano";
        	c1.renda = new BigDecimal(10000d);
        	c1.ocupacao = new Ocupacao();
        	c1.ocupacao.descricao = "Professor";
        	c1.idade = 40;
        	System.out.println(c1);
	}
}