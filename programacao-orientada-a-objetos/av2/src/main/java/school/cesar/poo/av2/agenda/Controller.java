package school.cesar.poo.av2.agenda;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.JTableHeader;

import java.util.*;

public class Controller {
	private Model model;
	private View view;

	// Inicializa a View
	public void initView() {
		// Carrega estado do model, e inicia a view com ele.
		Vector<Object> dados = new Vector<Object>();
		Vector<Object> linha;
		for (Contato c : model.getEstado()) {
			linha = new Vector<Object>();
			linha.add(c.getNome());
			linha.add(c.getEmail());
			linha.add(c.getEndereco());
			linha.add(c.getTelefone());
			dados.add(linha);
		}
		// Abaixo: Inicializa valores da view
		String[] colunas = {"Nome", "E-mail", "Endereco", "Telefone"};
		view.setGui(new ListaFrame(
				dados,
				new Vector<Object>(Arrays.asList(colunas)))
		);
		view.getGui().setVisible(true);

		/* Eventos de interação entre Model e View */
		
		// 1: Evento de botão de adicionar da GUI
		view.getGui().getBtnAdicionar().addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// 1.1: Inicializa Popup
				view.setPopup(new AddFrame());
				view.getPopup().setVisible(true);
				
				// 1.2: Eventos de Sair do Popup
				view.getPopup().getBtnSair().addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						// Fecha popup
						view.getPopup().dispose();
					}
				});
				
				// 1.3: Eventos de Adicionar do Popup
				view.getPopup().getBtnConfirmar().addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						// Cria objeto e adiciona no estado do Model
						String nome = view.getPopup().getInputNome();
						String email = view.getPopup().getInputEmail();
						String endereco = view.getPopup().getInputEndereco();
						String telefone = view.getPopup().getInputTelefone();
						Contato c = new Contato(nome, email, endereco, telefone);
						// Atualiza Model
						model.adicionarInstancia(c);
						// Atualiza tabela
						Object[] novo = {nome, email, endereco, telefone};
						DefaultTableModel tableModel;
						tableModel = (DefaultTableModel) view.getGui().getTable().getModel();
						tableModel.addRow(novo);
						JOptionPane.showMessageDialog(null, "Contato inserido com sucesso");
						view.getPopup().dispose();
					}
				});
			}
		});
		// 2: Evento de REMOVER da tabela da GUI
		view.getGui().getBtnRemover().addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// 2.1: Checa linha(s) selecionada
				int[] lines = view.getGui().getTable().getSelectedRows();
				if (lines.length == 0) {
					JOptionPane.showMessageDialog(
							null,
							"Selecione pelomenos uma linha para ser deletada"
					);
				} else {
					DefaultTableModel tableModel;
					tableModel = (DefaultTableModel) view.getGui().getTable().getModel();
					// 2.2: Remove da tabela e do estado do modelo
					/* Comentário: É varrido no inverso pois, se for em ordem
					 * normal, os índices subsequentes decrementam a cada remoção */
					Contato c;
					for (int i=lines.length-1; i >= 0; i--) {
						// 2.2.1: Constrói o objeto a ser deletado no estado
						c = new Contato(
								tableModel.getValueAt(lines[i], 0).toString(),
								tableModel.getValueAt(lines[i], 1).toString(),
								tableModel.getValueAt(lines[i], 2).toString(),
								tableModel.getValueAt(lines[i], 3).toString()
						);
						// 2.2.2: Deleta o objeto no estado e da tabela
						model.removerInstancia(c);
						tableModel.removeRow(lines[i]);
					}
					
					JOptionPane.showMessageDialog(
							null,
							"Linha(s) deletada(s) com sucesso!"
					);
				}	
				}
		});
		
		// 3: Evento de botão de sair da GUI
		view.getGui().getBtnSair().addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// 3.1: Salva estado do modelo em seu arquivo.
				model.salvarEstado();
				// 3.2: Fecha aplicação por total
				view.getGui().dispose();
			}
		});
	}
	
	/* Inicia o Controller */
	public Controller(Model m, View v) {
		model = m;
		view = v;
		initView();
	}
}
