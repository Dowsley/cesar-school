package school.cesar.poo.av1.ex4;

import java.util.List;
import java.util.ArrayList;
import java.util.Date;

public class Post {
    private byte[] imagem;
    private Date data;
    private List<Usuario> mencoes = new ArrayList<Usuario>();

    public byte[] getImagem() {
        return this.imagem;
    }

    public void setImagem(byte[] imagem) {
        this.imagem = imagem;
    }

    public Date getData() {
        return this.data;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public List<Usuario> getMencoes() {
        return this.mencoes;
    }

    public void setMencoes(List<Usuario> mencoes) {
        this.mencoes = mencoes;
    }
}