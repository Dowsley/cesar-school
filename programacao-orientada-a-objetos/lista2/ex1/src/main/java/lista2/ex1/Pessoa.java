package lista2.ex1;

public abstract class Pessoa {
        private String cpf;
        private String nome;
        private int idade;

        /* Setters */
        public void setCpf(String cpf) throws RuntimeException {
                if (cpf == "")
                        throw new RuntimeException("CPF não pode ser vazio.");
                this.cpf = cpf;
        }

        public void setNome(String nome) {
                this.nome = nome;
        }

        public void setIdade(int idade) throws RuntimeException {
                if (idade < 0)
                        throw new RuntimeException("Idade não pode ser menor que 0");
                this.idade = idade;
        }

        /* Getters */
        public String getCpf() {
                return this.cpf;
        }


        public String getNome() {
                return this.nome;
        }


        public int getIdade() {
                return this.idade;
        } 

        /* Other Methods */
        @Override
        public int hashCode() {
                int hash = 7;
                hash = 9 * hash + cpf.hashCode();
                return hash;
        }

        @Override
        public boolean equals(Object o) {
                if (!(o instanceof Pessoa) || this.cpf == null)
                        return false;
                Pessoa that = (Pessoa) o;
                return (this.hashCode() == that.hashCode());
        }
}