package school.cesar.poo.av1.ex1.cliente;

public interface RepositorioCliente {
	public void cadastrarCliente(Cliente cliente);
	public void descadastrarCliente(String cpf);
	public Cliente recuperarCliente(String cpf);
}
