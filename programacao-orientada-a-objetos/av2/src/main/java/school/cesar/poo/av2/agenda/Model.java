package school.cesar.poo.av2.agenda;

import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

public class Model {
	private String nomeArquivo;
	private List<Contato> estado;
	
	// Salva estado no arquivo
	public void salvarEstado() {
		try {
            FileOutputStream file = new FileOutputStream(this.nomeArquivo, false); 
            ObjectOutputStream out = new ObjectOutputStream(file);
            for (Contato c : estado) {
            	out.writeObject(c);
            }
            out.close(); 
            file.close(); 
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	// Carrega estado do arquivo
	public Iterable<Contato> carregarEstado() {
		try {
            FileInputStream file = new FileInputStream(this.nomeArquivo); 
            ObjectInputStream in = new ObjectInputStream(file); 
			List<Contato> contatos = new ArrayList<Contato>();
			while(true) {
			    try {
			    	contatos.add((Contato) in.readObject());
			    } catch (EOFException e) {
			        break; // Break when the end-of-file is reached
			    }
			}
            in.close();
            file.close();
            return contatos;
		} catch (Exception e) {
			return (Iterable<Contato>) new ArrayList<Contato>();
		}
	}
	
	// Adicionar Contato
	public void adicionarInstancia(Contato c) {
		this.estado.add(c);
	}

	// Remover Contato
	public void removerInstancia(Contato r) {
		// Checa similaridade
		for (Contato c: estado) {
			if (c.getNome() == r.getNome() && 
				c.getEmail() == r.getEmail() &&
				c.getEndereco() == r.getEndereco() &&
				c.getTelefone() == r.getTelefone()) {
					estado.remove(c);
					break;
			}
			
		}
	}
	
	public List<Contato> getEstado() {
		return estado;
	}
	
	// Inicializa modelo
	public Model(String nome) {
		nomeArquivo = nome; // Define o nome da "DATABASE"
		estado = (ArrayList<Contato>) carregarEstado();
	}
}
