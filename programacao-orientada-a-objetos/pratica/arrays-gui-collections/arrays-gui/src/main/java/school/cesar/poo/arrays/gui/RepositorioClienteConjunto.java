package school.cesar.poo.arrays.gui;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class RepositorioClienteConjunto implements RepositorioCliente {
	private Set<Cliente> armazenamento;
	public RepositorioClienteConjunto() {
		this.armazenamento = new HashSet<Cliente>();
	}
	
	public void cadastrarCliente(Cliente cliente) {
		this.armazenamento.add(cliente);
	}
	
	public Cliente descadastrarCliente(String cpf) {
		Cliente busca = new Cliente("", cpf);
		if (this.armazenamento.contains(busca)) {
			Iterator<Cliente> it = this.armazenamento.iterator();
			while (it.hasNext()) {
				Cliente elemento = it.next();
				if (elemento.equals(busca)) {
					it.remove();
					return elemento;
				}
			}
		}
		throw new RuntimeException("Nao ha cliente com o cpf " + cpf);
	}
	
	public Cliente recuperarCliente(String cpf) {
		Cliente busca = new Cliente("", cpf);
		if (this.armazenamento.contains(busca)) {
			Iterator<Cliente> it = this.armazenamento.iterator();
			while (it.hasNext()) {
				Cliente elemento = it.next();
				if (elemento.equals(busca))
					return elemento;
			}
		}
		throw new RuntimeException("Nao ha cliente com o cpf " + cpf);
	}

}
