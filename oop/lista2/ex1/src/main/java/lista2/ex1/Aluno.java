package lista2.ex1;

public class Aluno extends Pessoa { 
        public String curso;
        public Boolean matriculaTrancada;

        // Default Constructor
        public Aluno(String nome, String cpf, int idade, String curso) {
                this.curso = curso;
                this.cpf = cpf;
                this.nome = nome;
                this.idade = idade;
                matriculaTrancada = false;
        }

        public boolean trancarMatricula() {
                this.matriculaTrancada = true;
                return matriculaTrancada;
        }
}