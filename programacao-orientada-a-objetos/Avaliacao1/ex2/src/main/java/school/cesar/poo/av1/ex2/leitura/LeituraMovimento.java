package school.cesar.poo.av1.ex2.leitura;

public class LeituraMovimento extends Leitura {
    private int acionamentos;
    private double distanciaMedia;
    private double distanciaMinima;
    private double distanciaMaxima;

    public int getAcionamentos() {
        return this.acionamentos;
    }
    public void setAcionamentos(int acionamentos) {
        this.acionamentos = acionamentos;
    }

    public double getDistanciaMedia() {
        return this.distanciaMedia;
    }
    public void setDistanciaMedia(double distanciaMedia) {
        this.distanciaMedia = distanciaMedia;
    }

    public double getDistanciaMinima() {
        return this.distanciaMinima;
    }
    public void setDistanciaMinima(double distanciaMinima) {
        this.distanciaMinima = distanciaMinima;
    }

    public double getDistanciaMaxima() {
        return this.distanciaMaxima;
    }
    public void setDistanciaMaxima(double distanciaMaxima) {
        this.distanciaMaxima = distanciaMaxima;
    }
}