package school.cesar.poo.arrays.gui;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class RepositorioClienteMapa implements RepositorioCliente {
	private Map<String,Cliente> armazenamento;
	public RepositorioClienteMapa() {
		this.armazenamento = new HashMap<String, Cliente>();
	}
	
	public void cadastrarCliente(Cliente cliente) {
		//this.armazenamento.add(cliente);
	}
	
	public Cliente descadastrarCliente(String cpf) {
	
		throw new RuntimeException("Nao ha cliente com o cpf " + cpf);
	}
	
	public Cliente recuperarCliente(String cpf) {

		throw new RuntimeException("Nao ha cliente com o cpf " + cpf);
	}

}
