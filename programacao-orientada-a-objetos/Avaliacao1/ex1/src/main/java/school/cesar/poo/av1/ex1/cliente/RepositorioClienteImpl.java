package school.cesar.poo.av1.ex1.cliente;
import java.util.ArrayList;
import java.util.List;

public class RepositorioClienteImpl implements RepositorioCliente {
	public RepositorioClienteImpl() {
	}
	
	private ArrayList<Cliente> clientes = new ArrayList<Cliente>();

	public void cadastrarCliente(Cliente cliente) {
		if (cliente != null) 
			this.clientes.add(cliente);
	}

	public void descadastrarCliente(String cpf) {
		for (Cliente c : this.clientes) {
			if (c.getCpf().equals(cpf)) {
				clientes.remove(clientes.indexOf(c));
			}
		}
	}

	public Cliente recuperarCliente(String cpf) {
		for (Cliente c : this.clientes) {
			if (c.getCpf().equals(cpf)) {
				return c;
			}
		}
		return null;
	}

}
