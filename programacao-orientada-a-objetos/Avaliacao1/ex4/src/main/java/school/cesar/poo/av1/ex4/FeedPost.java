package school.cesar.poo.av1.ex4;
import java.util.List;
import java.util.ArrayList;

public class FeedPost extends Post {
    private String texto;
    private List<String> tags = new ArrayList<String>();

    public String getTexto() {
        return this.texto;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }

    public List<String> getTags() {
        return this.tags;
    }

    public void setTags(List<String> tags) {
        this.tags = tags;
    }
}