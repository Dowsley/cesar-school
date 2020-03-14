package lista2.ex1;

public abstract class Pessoa {
        public String cpf;
        public String nome;
        public int idade;

        public boolean equals(Pessoa that) {
                if (this.cpf == null || that.cpf == null)
                        return false;
                return (this.cpf == that.cpf);
        }

        @Override
        public int hashCode() {
                int hash = 19;
                hash = 31 * hash + cpf.hashCode();
                hash = 31 * hash + nome.hashCode();
                hash = 31 * hash + idade;
                return hash;
        }
}