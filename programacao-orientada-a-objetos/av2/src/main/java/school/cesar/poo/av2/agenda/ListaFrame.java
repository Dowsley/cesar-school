package school.cesar.poo.av2.agenda;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.table.JTableHeader;
import javax.swing.JButton;
import javax.swing.JTable;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JScrollPane;

import java.util.*;

public class ListaFrame extends JFrame {
	private JPanel contentPane;
	private JTable table;
	private JButton btnAdicionar;
	private JButton btnSair;
	private JButton btnRemover;
	private JScrollPane scrollPane;

	/**
	 * Create the frame.
	 */
	public ListaFrame(Vector<Object> dados, Vector<Object> colunas) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);

		// Componentes da ListaFrame
		btnAdicionar = new JButton("Adicionar");
		btnAdicionar.setBounds(290, 11, 89, 23);
		contentPane.add(btnAdicionar);

		btnSair = new JButton("Sair");
		btnSair.setBounds(290, 227, 89, 23);
		contentPane.add(btnSair);
		
		table = new JTable(dados, colunas);
		table.setTableHeader(table.getTableHeader());
		scrollPane = new JScrollPane(table);
		scrollPane.setBounds(10, 11, 216, 239);
		contentPane.add(scrollPane);	
		
		btnRemover = new JButton("Remover");
		btnRemover.setBounds(290, 112, 89, 23);
		contentPane.add(btnRemover);
	}
	
	public JTable getTable() {
		return this.table;
	}

	public JButton getBtnAdicionar() {
		return btnAdicionar;
	}

	public JButton getBtnSair() {
		return btnSair;
	}
	
	public JButton getBtnRemover() {
		return btnRemover;
	}
}
