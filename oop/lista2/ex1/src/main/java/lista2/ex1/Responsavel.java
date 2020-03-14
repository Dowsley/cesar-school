package lista2.ex1;
import java.math.BigDecimal;

public class Responsavel extends Pessoa {
        Aluno aluno;
        BigDecimal renda;
        Ocupacao ocupacao;

        // Default Constructor
        public Responsavel(String nome, String cpf, int idade, BigDecimal renda) {
                this.cpf = cpf;
                this.nome = nome;
                this.idade = idade;
                this.renda = renda;
        }
}