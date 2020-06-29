package school.cesar.poo.av1.ex3;

public class Usuario {
    private String email;
    private String cpf;
    private String senha;

    /* Tirei getSenha, pois não seria seguro para uma autenticação. */
    public boolean verificarSenha(String senha) {
        return this.senha.equals(senha);
    }}

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getCpf() {
        return this.cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }
}