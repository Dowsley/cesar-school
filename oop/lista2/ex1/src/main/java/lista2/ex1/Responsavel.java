package lista2.ex1;
import java.math.BigDecimal;

public class Responsavel extends Pessoa {
        private Aluno aluno;
        private BigDecimal renda;
        private Ocupacao ocupacao;

        // Constructor
        public Responsavel(String nome, String cpf, int idade) {
                this.setCpf(cpf);
                this.setNome(nome);
                this.setIdade(idade);
        }

        /* Getters */
        public Aluno getAluno() {
                return this.aluno;
        }

        public Ocupacao getOcupacao() {
                return this.ocupacao;
        }

        public BigDecimal getRenda() {
                return this.renda;
        }

        /* Setters */
        public void setAluno(Aluno aluno) {
                this.aluno = aluno;
        }

        public void setOcupacao(Ocupacao ocupacao) {
                this.ocupacao = ocupacao;
        }

        public void setRenda(BigDecimal renda) {
                this.renda = renda;
        }
}