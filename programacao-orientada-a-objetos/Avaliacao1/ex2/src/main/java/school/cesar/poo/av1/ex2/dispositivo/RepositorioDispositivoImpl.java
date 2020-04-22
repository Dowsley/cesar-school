package school.cesar.poo.av1.ex2.dispositivo;

import java.util.ArrayList;
import java.util.List;

public class RepositorioDispositivoImpl implements RepositorioDispositivo {
	
	List<Dispositivo> dispositivos = new ArrayList<Dispositivo>();

	public void cadastrarDispositivo(Dispositivo dispositivo) throws DispositivoException {
		if (dispositivo == null) {
			throw new DispositivoException("Dispositivo nao pode ser nulo");
		}
		for (Dispositivo d : dispositivos) {
			if (d.getMacAddress().equals(dispositivo.getMacAddress())) {
				throw new DispositivoException("Ja existe um dispositivo igual cadastrado");
			}
		}
		dispositivos.add(dispositivo);
	}

	public void descadastrarDispositivo(Dispositivo dispositivo) throws DispositivoException {
		if (dispositivo == null) {
			throw new DispositivoException("Dispositivo nao pode ser nulo");
		}
		for (Dispositivo d : dispositivos) {
			if (d.getMacAddress().equals(dispositivo.getMacAddress())) {
				dispositivos.remove(dispositivos.indexOf(d));
			}
		}
	}

	public Dispositivo recuperarDispositivo(String macAddress) throws DispositivoException {
		if (macAddress == null || macAddress.equals("")) {
			throw new DispositivoException("Mac Address nao pode ser nulo ou vazio");
		}
		for (Dispositivo d : dispositivos) {
			if (d.getMacAddress().equals(macAddress)) {
				return d;
			}
		}
		return null;
	}
}
