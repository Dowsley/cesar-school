package school.cesar.poo.av2.agenda;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;

public class AddFrame extends JFrame {

	private JPanel contentPane;
	private JButton btnConfirmar;
	private JButton btnSair;
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;

	/**
	 * Create the frame.
	 */
	public AddFrame() {
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		setBounds(100, 100, 357, 292);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		// Componentes da GUI
		btnConfirmar = new JButton("Confirmar");
		
		btnSair = new JButton("Sair");
		
		JLabel lblNewLabel = new JLabel("Nome");
		lblNewLabel.setHorizontalAlignment(SwingConstants.RIGHT);
		
		JLabel lblNewLabel_1 = new JLabel("Email");
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.RIGHT);
		
		JLabel lblNewLabel_2 = new JLabel("Endereco");
		lblNewLabel_2.setHorizontalAlignment(SwingConstants.RIGHT);
		
		JLabel lblNewLabel_3 = new JLabel("Telefone");
		lblNewLabel_3.setHorizontalAlignment(SwingConstants.RIGHT);
		
		textField = new JTextField();
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setColumns(10);
		
		textField_2 = new JTextField();
		textField_2.setColumns(10);
		
		textField_3 = new JTextField();
		textField_3.setColumns(10);
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(40)
					.addComponent(lblNewLabel, GroupLayout.DEFAULT_SIZE, 46, Short.MAX_VALUE)
					.addGap(10)
					.addComponent(textField, GroupLayout.DEFAULT_SIZE, 169, Short.MAX_VALUE)
					.addGap(66))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(40)
					.addComponent(lblNewLabel_1, GroupLayout.DEFAULT_SIZE, 46, Short.MAX_VALUE)
					.addGap(10)
					.addComponent(textField_1, GroupLayout.DEFAULT_SIZE, 169, Short.MAX_VALUE)
					.addGap(66))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(40)
					.addComponent(lblNewLabel_2, GroupLayout.DEFAULT_SIZE, 46, Short.MAX_VALUE)
					.addGap(10)
					.addComponent(textField_2, GroupLayout.DEFAULT_SIZE, 169, Short.MAX_VALUE)
					.addGap(66))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(40)
					.addComponent(lblNewLabel_3, GroupLayout.DEFAULT_SIZE, 46, Short.MAX_VALUE)
					.addGap(10)
					.addComponent(textField_3, GroupLayout.DEFAULT_SIZE, 169, Short.MAX_VALUE)
					.addGap(66))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(28)
					.addComponent(btnConfirmar, GroupLayout.DEFAULT_SIZE, 89, Short.MAX_VALUE)
					.addGap(97)
					.addComponent(btnSair, GroupLayout.DEFAULT_SIZE, 89, Short.MAX_VALUE)
					.addGap(28))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(38)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(3)
							.addComponent(lblNewLabel))
						.addComponent(textField))
					.addGap(11)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(3)
							.addComponent(lblNewLabel_1))
						.addComponent(textField_1, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
					.addGap(11)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(3)
							.addComponent(lblNewLabel_2))
						.addComponent(textField_2))
					.addGap(8)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(3)
							.addComponent(lblNewLabel_3))
						.addComponent(textField_3))
					.addGap(55)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING, false)
						.addComponent(btnConfirmar, Alignment.TRAILING)
						.addComponent(btnSair))
					.addGap(17))
		);
		contentPane.setLayout(gl_contentPane);
	}

	public JButton getBtnConfirmar() {
		return btnConfirmar;
	}

	public JButton getBtnSair() {
		return btnSair;
	}

	public String getInputNome() {
		return textField.getText();
	}

	public String getInputEmail() {
		return textField_1.getText();
	}

	public String getInputEndereco() {
		return textField_2.getText();
	}

	public String getInputTelefone() {
		return textField_3.getText();
	}

}
