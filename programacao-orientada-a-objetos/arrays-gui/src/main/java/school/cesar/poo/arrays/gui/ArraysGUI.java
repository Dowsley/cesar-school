package school.cesar.poo.arrays.gui;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import java.awt.GridBagLayout;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.GridBagConstraints;
import javax.swing.JTextField;
import java.awt.Insets;
import javax.swing.JButton;
import javax.swing.AbstractAction;
import java.awt.event.ActionEvent;
import javax.swing.Action;
import java.awt.event.ActionListener;

public class ArraysGUI extends JFrame {
	private RepositorioCliente repositorioCliente;
	private JPanel contentPane;
	private JTextField txtNome;
	private JTextField txtCPF;

	/**
	 * Launch the application.
	 */

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					ArraysGUI frame = new ArraysGUI();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public ArraysGUI() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 504, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		GridBagLayout gbl_contentPane = new GridBagLayout();
		gbl_contentPane.columnWidths = new int[]{0, 0, 0, 0, 0, 0, 0, 0};
		gbl_contentPane.rowHeights = new int[]{0, 0};
		gbl_contentPane.columnWeights = new double[]{0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		gbl_contentPane.rowWeights = new double[]{0.0, Double.MIN_VALUE};
		contentPane.setLayout(gbl_contentPane);
		
		JLabel lblNome = new JLabel("Nome:");
		GridBagConstraints gbc_lblNome = new GridBagConstraints();
		gbc_lblNome.insets = new Insets(0, 0, 0, 5);
		gbc_lblNome.anchor = GridBagConstraints.EAST;
		gbc_lblNome.gridx = 0;
		gbc_lblNome.gridy = 0;
		contentPane.add(lblNome, gbc_lblNome);
		
		txtNome = new JTextField();
		GridBagConstraints gbc_txtNome = new GridBagConstraints();
		gbc_txtNome.insets = new Insets(0, 0, 0, 5);
		gbc_txtNome.fill = GridBagConstraints.HORIZONTAL;
		gbc_txtNome.gridx = 1;
		gbc_txtNome.gridy = 0;
		contentPane.add(txtNome, gbc_txtNome);
		txtNome.setColumns(10);
		
		JLabel lblCPF = new JLabel("CPF");
		GridBagConstraints gbc_lblCPF = new GridBagConstraints();
		gbc_lblCPF.insets = new Insets(0, 0, 0, 5);
		gbc_lblCPF.anchor = GridBagConstraints.EAST;
		gbc_lblCPF.gridx = 2;
		gbc_lblCPF.gridy = 0;
		contentPane.add(lblCPF, gbc_lblCPF);
		
		txtCPF = new JTextField();
		GridBagConstraints gbc_txtCPF = new GridBagConstraints();
		gbc_txtCPF.insets = new Insets(0, 0, 0, 5);
		gbc_txtCPF.fill = GridBagConstraints.HORIZONTAL;
		gbc_txtCPF.gridx = 3;
		gbc_txtCPF.gridy = 0;
		contentPane.add(txtCPF, gbc_txtCPF);
		txtCPF.setColumns(10);
		
		JButton btnCadastrar = new JButton("Cadastrar");
		btnCadastrar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				//TODO: cadastrar cliente
				Cliente novoCliente = null;
				ArraysGUI.this.repositorioCliente.cadastrarCliente(novoCliente);
			}
		});
		GridBagConstraints gbc_btnCadastrar = new GridBagConstraints();
		gbc_btnCadastrar.insets = new Insets(0, 0, 0, 5);
		gbc_btnCadastrar.gridx = 4;
		gbc_btnCadastrar.gridy = 0;
		contentPane.add(btnCadastrar, gbc_btnCadastrar);
		
		JButton btnDescadastrar = new JButton("Descadastrar");
		btnDescadastrar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				//TODO: descadastrar
				String cpf = txtCPF.getText();
				Cliente removido = ArraysGUI.this.repositorioCliente.descadastrarCliente(cpf);
			}
		});
		GridBagConstraints gbc_btnDescadastrar = new GridBagConstraints();
		gbc_btnDescadastrar.insets = new Insets(0, 0, 0, 5);
		gbc_btnDescadastrar.gridx = 5;
		gbc_btnDescadastrar.gridy = 0;
		contentPane.add(btnDescadastrar, gbc_btnDescadastrar);
		
		JButton btnRecuperar = new JButton("Recuperar");
		btnRecuperar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//TODO: recuperar
				String cpf = txtCPF.getText();
				Cliente recuperado = ArraysGUI.this.repositorioCliente.descadastrarCliente(cpf);
				JOptionPane.showMessageDialog(ArraysGUI.this, "");
			}
		});
		GridBagConstraints gbc_btnRecuperar = new GridBagConstraints();
		gbc_btnRecuperar.gridx = 6;
		gbc_btnRecuperar.gridy = 0;
		contentPane.add(btnRecuperar, gbc_btnRecuperar);
	}

	private class SwingAction extends AbstractAction {
		public SwingAction() {
			putValue(NAME, "SwingAction");
			putValue(SHORT_DESCRIPTION, "Some short description");
		}
		public void actionPerformed(ActionEvent e) {
		}
	}
}
