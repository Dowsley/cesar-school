package school.cesar.poo.av1.ex2.leitura;

import java.util.ArrayList;
import java.util.List;

import school.cesar.poo.av1.ex2.dispositivo.Dispositivo;

public class RepositorioLeituraImpl implements RepositorioLeitura {

	List<Leitura> leituras = new ArrayList<Leitura>();

	public void cadastrarLeitura(Leitura leitura) {
		leituras.add(leitura);
	}

	public List<Leitura> listarLeituras(Dispositivo dispositivo) {
		List<Leitura> out = new ArrayList<Leitura>();
		for (Leitura l : leituras) {
			if (l.dispositivo.getMacAddress().equals(dispositivo.getMacAddress())) {
				out.add(l);
			}
		}
		return out;
	}

}
