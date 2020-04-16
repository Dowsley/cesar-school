package lista2.ex1;

public class Aluno extends Pessoa { 
        private String curso;
        private Boolean matriculaTrancada;
        
        // Constructor
        public Aluno(String nome, String cpf, int idade) {
                matriculaTrancada = false;
                this.setCpf(cpf);
                this.setNome(nome);
                this.setIdade(idade);
        }

        /* Setters */
        public void setCurso(String curso) {
                this.curso = curso;
        }

        /* Getters */
        public String getCurso() {
                return this.curso;
        }


        public Boolean getMatriculaTrancada() {
                return this.matriculaTrancada;
        }
       
        /* Other Methods */
        public void trancarMatricula() {
                this.matriculaTrancada = true;
        }
}