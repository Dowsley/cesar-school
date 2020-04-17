package lista1.ex2;

import java.math.BigDecimal;

public class Cliente {
	// Atributos
	public String nome;
	public int idade;
	public BigDecimal renda;
	public Ocupacao ocupacao = new Ocupacao();

	// Métodos
	public String toString() {
		return String.format("Cliente: %s %d %s", nome, idade, ocupacao.descricao);
	}
}