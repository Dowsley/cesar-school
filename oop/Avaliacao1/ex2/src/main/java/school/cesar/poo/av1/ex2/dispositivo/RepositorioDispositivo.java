package school.cesar.poo.av1.ex2.dispositivo;

public interface RepositorioDispositivo {
	public void cadastrarDispositivo(Dispositivo dispositivo) throws DispositivoException;
	public void descadastrarDispositivo(Dispositivo dispositivo) throws DispositivoException;
	public void recuperarDispositivo(String macAddress) throws DispositivoException;
}
