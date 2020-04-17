package school.cesar.poo.arrays.gui;

import java.util.ArrayList;
import java.util.List;

public class RepositorioClienteLista implements RepositorioCliente {
	private List<Cliente> armazenamento;
	public RepositorioClienteLista() {
		this.armazenamento = new ArrayList<Cliente>();
	}
	
	public void cadastrarCliente(Cliente cliente) {
		this.armazenamento.add(cliente);
	}
	
	public Cliente descadastrarCliente(String cpf) {
		Cliente busca = new Cliente("", cpf);
		if (this.armazenamento.contains(busca)) {
			int indice = this.armazenamento.indexOf(busca);
			Cliente removido = this.armazenamento.get(indice);
			this.armazenamento.remove(indice);
			return removido;
		}
		throw new RuntimeException("Nao ha cliente com o cpf " + cpf);
	}
	
	public Cliente recuperarCliente(String cpf) {
		Cliente busca = new Cliente("", cpf);
		if (this.armazenamento.contains(busca)) {
			return this.armazenamento.get(this.armazenamento.indexOf(busca));
		}
		throw new RuntimeException("Nao ha cliente com o cpf " + cpf);
	}

}
