package school.cesar.poo.av1.ex2.leitura;

import java.util.List;

import school.cesar.poo.av1.ex2.dispositivo.Dispositivo;

public interface RepositorioLeitura {
	public void cadastrarLeitura(Leitura leitura);
	public List<Leitura> listarLeituras(Dispositivo dispositivo);
}
