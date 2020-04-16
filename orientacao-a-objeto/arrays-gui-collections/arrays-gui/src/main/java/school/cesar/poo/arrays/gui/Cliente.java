package school.cesar.poo.arrays.gui;

public class Cliente {
	private String nome;
	private String cpf;
	
	public Cliente(String nome, String cpf) {
		this.nome = nome;
		this.cpf = cpf;
	}
	
	public Cliente() {
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getCpf() {
		return cpf;
	}
	
	public boolean equals(Object o) {
		if (o instanceof Cliente) {
			Cliente outro = (Cliente) o;
			if (this.cpf == null)
				return false;
			return this.cpf.equals(outro.cpf);
		}
		return false;
	}
	
	public int hashCode() {
		return cpf.hashCode();
	}
}
