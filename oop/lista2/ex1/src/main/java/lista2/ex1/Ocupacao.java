package lista2.ex1;

public class Ocupacao {
        String descricao;
        
        public boolean equals(Ocupacao that) {
                if (this.descricao == null)
                        return false;
                return (this.descricao == that.descricao);
        }
}