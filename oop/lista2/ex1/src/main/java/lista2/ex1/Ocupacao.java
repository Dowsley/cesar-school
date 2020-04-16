package lista2.ex1;

public class Ocupacao {
        private String descricao;

        // Constructor
        public Ocupacao(String descricao) {
                this.descricao = descricao;
        }
        
        /* 
        COMENTARIO PESSOAL: A proposta de identidade foi
        resolvida com um Override de hashCode e equals.
        */

        /* Methods */
        @Override
        public int hashCode() {
                int hash = 7;
                hash = 9 * hash + descricao.hashCode();
                return hash;
        }

        @Override
        public boolean equals(Object o) {
                if (!(o instanceof Ocupacao) || this.descricao == null)
                        return false;
                Ocupacao that = (Ocupacao) o;
                return (this.hashCode() == that.hashCode());
        }
}