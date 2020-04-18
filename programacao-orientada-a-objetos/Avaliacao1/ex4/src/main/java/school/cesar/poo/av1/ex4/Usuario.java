package school.cesar.poo.av1.ex4;
import java.util.List;
import java.util.ArrayList;

public class Usuario {
    private String email;
    private String senha;
    private List<Post> posts = new ArrayList<Post>();

    /* Novamente, retirei o getSenha */
    public boolean verificarSenha(String senha) {
        return this.senha.equals(senha);
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public List<Post> getPosts() {
        return this.posts;
    }

    public void setPosts(List<Post> posts) {
        this.posts = posts;
    }
}