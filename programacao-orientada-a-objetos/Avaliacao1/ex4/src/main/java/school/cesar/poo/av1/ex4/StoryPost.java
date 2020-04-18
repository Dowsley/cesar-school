package school.cesar.poo.av1.ex4;

import java.util.Date;

public class StoryPost extends Post {
    private Date expiracao;
    private boolean melhoresAmigos;

    public Date getExpiracao() {
        return this.expiracao;
    }

    public void setExpiracao(Date expiracao) {
        this.expiracao = expiracao;
    }

    public boolean isMelhoresAmigos() {
        return this.melhoresAmigos;
    }

    public boolean getMelhoresAmigos() {
        return this.melhoresAmigos;
    }

    public void setMelhoresAmigos(boolean melhoresAmigos) {
        this.melhoresAmigos = melhoresAmigos;
    }
}