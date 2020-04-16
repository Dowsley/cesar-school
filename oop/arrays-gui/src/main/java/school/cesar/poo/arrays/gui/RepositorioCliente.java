package school.cesar.poo.arrays.gui;

public interface RepositorioCliente {
	public void cadastrarCliente(Cliente c);
	public Cliente descadastrarCliente(String cpf);
	public Cliente recuperarCliente(String cpf);
}
