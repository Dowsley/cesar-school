package school.cesar.poo.av1.ex2.leitura;
import java.util.Date;
import school.cesar.poo.av1.ex2.dispositivo.Dispositivo;

public abstract class Leitura {
	public Dispositivo dispositivo;
	public Date timestamp;

	public Dispositivo getDispositivo() {
		return this.dispositivo;
	}
	public void setDispositivo(Dispositivo dispositivo) {
		this.dispositivo = dispositivo;
	}

	public Date getTimestamp() {
		return this.timestamp;
	}
	public void setTimestamp(Date timestamp) {
		this.timestamp = timestamp;
	}
}
