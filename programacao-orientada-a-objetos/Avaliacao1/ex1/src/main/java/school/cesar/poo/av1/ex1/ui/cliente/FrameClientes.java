package school.cesar.poo.av1.ex1.ui.cliente;

import java.awt.Color;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;

import school.cesar.poo.av1.ex1.cliente.Cliente;
import school.cesar.poo.av1.ex1.cliente.RepositorioCliente;
import school.cesar.poo.av1.ex1.cliente.RepositorioClienteImpl;
import javax.swing.SpinnerNumberModel;

public class FrameClientes extends JFrame {
	private RepositorioCliente repositorioCliente = new RepositorioClienteImpl();
	private JPanel contentPane;
	private JTextField txtCPFRecuperar;
	private JLabel lblNome; 
	private JLabel lblCPF; 
	private JLabel lblIdade; 
	private JLabel lblVIP; 
	private JLabel lblRenda; 
	private JTextField txtNome;
	private JTextField txtCPF;
	private JCheckBox ckbVIP; 
	private JSpinner spnIdade;
	private JSpinner spnRenda;

	/**
	 * Create the frame.
	 */
	public FrameClientes() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 401);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		GridBagLayout gbl_contentPane = new GridBagLayout();
		gbl_contentPane.columnWidths = new int[]{0, 0};
		gbl_contentPane.rowHeights = new int[]{0, 0, 0};
		gbl_contentPane.columnWeights = new double[]{1.0, Double.MIN_VALUE};
		gbl_contentPane.rowWeights = new double[]{1.0, 1.0, Double.MIN_VALUE};
		contentPane.setLayout(gbl_contentPane);
		
		JPanel panel = new JPanel();
		panel.setToolTipText("Cadastrar");
		panel.setBorder(new LineBorder(new Color(0, 0, 0)));
		GridBagConstraints gbc_panel = new GridBagConstraints();
		gbc_panel.insets = new Insets(0, 0, 5, 0);
		gbc_panel.fill = GridBagConstraints.BOTH;
		gbc_panel.gridx = 0;
		gbc_panel.gridy = 0;
		contentPane.add(panel, gbc_panel);
		GridBagLayout gbl_panel = new GridBagLayout();
		gbl_panel.columnWidths = new int[]{0, 0, 0};
		gbl_panel.rowHeights = new int[]{0, 0, 0, 0, 0, 0, 0, 0};
		gbl_panel.columnWeights = new double[]{0.0, 1.0, Double.MIN_VALUE};
		gbl_panel.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		panel.setLayout(gbl_panel);
		
		JLabel lblNewLabel = new JLabel("Cadastrar");
		lblNewLabel.setFont(new Font("Tahoma", Font.BOLD, 13));
		GridBagConstraints gbc_lblNewLabel = new GridBagConstraints();
		gbc_lblNewLabel.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel.gridx = 0;
		gbc_lblNewLabel.gridy = 0;
		panel.add(lblNewLabel, gbc_lblNewLabel);
		
		JLabel lblNewLabel_5 = new JLabel("Nome:");
		GridBagConstraints gbc_lblNewLabel_5 = new GridBagConstraints();
		gbc_lblNewLabel_5.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_5.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel_5.gridx = 0;
		gbc_lblNewLabel_5.gridy = 1;
		panel.add(lblNewLabel_5, gbc_lblNewLabel_5);
		
		txtNome = new JTextField();
		GridBagConstraints gbc_txtNome = new GridBagConstraints();
		gbc_txtNome.insets = new Insets(0, 0, 5, 0);
		gbc_txtNome.fill = GridBagConstraints.HORIZONTAL;
		gbc_txtNome.gridx = 1;
		gbc_txtNome.gridy = 1;
		panel.add(txtNome, gbc_txtNome);
		txtNome.setColumns(10);
		
		JLabel lblNewLabel_9 = new JLabel("CPF:");
		GridBagConstraints gbc_lblNewLabel_9 = new GridBagConstraints();
		gbc_lblNewLabel_9.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel_9.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_9.gridx = 0;
		gbc_lblNewLabel_9.gridy = 2;
		panel.add(lblNewLabel_9, gbc_lblNewLabel_9);
		
		txtCPF = new JTextField();
		GridBagConstraints gbc_txtCPF = new GridBagConstraints();
		gbc_txtCPF.insets = new Insets(0, 0, 5, 0);
		gbc_txtCPF.fill = GridBagConstraints.HORIZONTAL;
		gbc_txtCPF.gridx = 1;
		gbc_txtCPF.gridy = 2;
		panel.add(txtCPF, gbc_txtCPF);
		txtCPF.setColumns(10);
		
		JLabel lblNewLabel_10 = new JLabel("Renda:");
		GridBagConstraints gbc_lblNewLabel_10 = new GridBagConstraints();
		gbc_lblNewLabel_10.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_10.gridx = 0;
		gbc_lblNewLabel_10.gridy = 3;
		panel.add(lblNewLabel_10, gbc_lblNewLabel_10);
		
		spnRenda = new JSpinner();
		spnRenda.setModel(new SpinnerNumberModel(new Double(0d), null, null, new Double(0.5d)));
		GridBagConstraints gbc_spnRenda = new GridBagConstraints();
		gbc_spnRenda.insets = new Insets(0, 0, 5, 0);
		gbc_spnRenda.fill = GridBagConstraints.BOTH;
		gbc_spnRenda.gridx = 1;
		gbc_spnRenda.gridy = 3;
		panel.add(spnRenda, gbc_spnRenda);
		
		JLabel lblNewLabel_11 = new JLabel("VIP:");
		GridBagConstraints gbc_lblNewLabel_11 = new GridBagConstraints();
		gbc_lblNewLabel_11.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_11.gridx = 0;
		gbc_lblNewLabel_11.gridy = 4;
		panel.add(lblNewLabel_11, gbc_lblNewLabel_11);
		
		ckbVIP = new JCheckBox("VIP");
		GridBagConstraints gbc_ckbVIP = new GridBagConstraints();
		gbc_ckbVIP.insets = new Insets(0, 0, 5, 0);
		gbc_ckbVIP.gridx = 1;
		gbc_ckbVIP.gridy = 4;
		panel.add(ckbVIP, gbc_ckbVIP);
		
		JLabel lblNewLabel_12 = new JLabel("Idade:");
		GridBagConstraints gbc_lblNewLabel_12 = new GridBagConstraints();
		gbc_lblNewLabel_12.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_12.gridx = 0;
		gbc_lblNewLabel_12.gridy = 5;
		panel.add(lblNewLabel_12, gbc_lblNewLabel_12);
		
		spnIdade = new JSpinner();
		GridBagConstraints gbc_spnIdade = new GridBagConstraints();
		gbc_spnIdade.insets = new Insets(0, 0, 5, 0);
		gbc_spnIdade.fill = GridBagConstraints.BOTH;
		gbc_spnIdade.gridx = 1;
		gbc_spnIdade.gridy = 5;
		panel.add(spnIdade, gbc_spnIdade);
		
		JButton btnCadastrar = new JButton("Cadastrar");
		btnCadastrar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					Cliente cliente = new Cliente();
					cliente.setNome(txtNome.getText());
					cliente.setCpf(txtCPF.getText());
					cliente.setVip(ckbVIP.isSelected());
					cliente.setIdade((Integer) spnIdade.getValue()); 
					cliente.setRenda((Double) spnRenda.getValue());
					repositorioCliente.cadastrarCliente(cliente);
				} catch (Exception ex) {
					JOptionPane.showMessageDialog(null, ex.getMessage());
				}
			}
		});
		GridBagConstraints gbc_btnCadastrar = new GridBagConstraints();
		gbc_btnCadastrar.gridx = 1;
		gbc_btnCadastrar.gridy = 6;
		panel.add(btnCadastrar, gbc_btnCadastrar);
		
		JPanel panel_1 = new JPanel();
		panel_1.setToolTipText("Cadastrado");
		panel_1.setBorder(new LineBorder(new Color(0, 0, 0)));
		GridBagConstraints gbc_panel_1 = new GridBagConstraints();
		gbc_panel_1.fill = GridBagConstraints.BOTH;
		gbc_panel_1.gridx = 0;
		gbc_panel_1.gridy = 1;
		contentPane.add(panel_1, gbc_panel_1);
		GridBagLayout gbl_panel_1 = new GridBagLayout();
		gbl_panel_1.columnWidths = new int[]{0, 0, 0, 0};
		gbl_panel_1.rowHeights = new int[]{0, 0, 0, 0, 0, 0, 0, 0};
		gbl_panel_1.columnWeights = new double[]{0.0, 1.0, 0.0, Double.MIN_VALUE};
		gbl_panel_1.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		panel_1.setLayout(gbl_panel_1);
		
		JLabel lblNewLabel_1 = new JLabel("Cadastrado");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.BOLD, 13));
		GridBagConstraints gbc_lblNewLabel_1 = new GridBagConstraints();
		gbc_lblNewLabel_1.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_1.gridx = 0;
		gbc_lblNewLabel_1.gridy = 0;
		panel_1.add(lblNewLabel_1, gbc_lblNewLabel_1);
		
		JLabel lblNewLabel_2 = new JLabel("CPF:");
		GridBagConstraints gbc_lblNewLabel_2 = new GridBagConstraints();
		gbc_lblNewLabel_2.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_2.anchor = GridBagConstraints.EAST;
		gbc_lblNewLabel_2.gridx = 0;
		gbc_lblNewLabel_2.gridy = 1;
		panel_1.add(lblNewLabel_2, gbc_lblNewLabel_2);
		
		txtCPFRecuperar = new JTextField();
		GridBagConstraints gbc_txtCPFRecuperar = new GridBagConstraints();
		gbc_txtCPFRecuperar.insets = new Insets(0, 0, 5, 5);
		gbc_txtCPFRecuperar.fill = GridBagConstraints.HORIZONTAL;
		gbc_txtCPFRecuperar.gridx = 1;
		gbc_txtCPFRecuperar.gridy = 1;
		panel_1.add(txtCPFRecuperar, gbc_txtCPFRecuperar);
		txtCPFRecuperar.setColumns(10);
		
		JButton btnRecuperar = new JButton("Recuperar");
		btnRecuperar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					Cliente recuperado = repositorioCliente.recuperarCliente(txtCPFRecuperar.getText());
					lblNome.setText(recuperado.getNome());
					lblCPF.setText(recuperado.getCpf());
					lblVIP.setText(recuperado.isVip() ? "Sim" : "N�o");
					lblIdade.setText(String.format("%d anos", recuperado.getIdade()));
					lblRenda.setText(String.format("R$ %32.2f", recuperado.getRenda()));
				} catch (Exception ex) {
					JOptionPane.showMessageDialog(null, ex.getMessage());
				}
			}
		});
		GridBagConstraints gbc_btnRecuperar = new GridBagConstraints();
		gbc_btnRecuperar.insets = new Insets(0, 0, 5, 0);
		gbc_btnRecuperar.gridx = 2;
		gbc_btnRecuperar.gridy = 1;
		panel_1.add(btnRecuperar, gbc_btnRecuperar);
		
		JLabel lblNewLabel_3 = new JLabel("Nome:");
		GridBagConstraints gbc_lblNewLabel_3 = new GridBagConstraints();
		gbc_lblNewLabel_3.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_3.gridx = 0;
		gbc_lblNewLabel_3.gridy = 2;
		panel_1.add(lblNewLabel_3, gbc_lblNewLabel_3);
		
		lblNome = new JLabel("");
		GridBagConstraints gbc_lblNome = new GridBagConstraints();
		gbc_lblNome.insets = new Insets(0, 0, 5, 5);
		gbc_lblNome.gridx = 1;
		gbc_lblNome.gridy = 2;
		panel_1.add(lblNome, gbc_lblNome);
		
		JLabel lblNewLabel_4 = new JLabel("CPF:");
		GridBagConstraints gbc_lblNewLabel_4 = new GridBagConstraints();
		gbc_lblNewLabel_4.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_4.gridx = 0;
		gbc_lblNewLabel_4.gridy = 3;
		panel_1.add(lblNewLabel_4, gbc_lblNewLabel_4);
		
		lblCPF = new JLabel("");
		GridBagConstraints gbc_lblCPF = new GridBagConstraints();
		gbc_lblCPF.insets = new Insets(0, 0, 5, 5);
		gbc_lblCPF.gridx = 1;
		gbc_lblCPF.gridy = 3;
		panel_1.add(lblCPF, gbc_lblCPF);
		
		JLabel lblNewLabel_6 = new JLabel("Renda:");
		GridBagConstraints gbc_lblNewLabel_6 = new GridBagConstraints();
		gbc_lblNewLabel_6.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_6.gridx = 0;
		gbc_lblNewLabel_6.gridy = 4;
		panel_1.add(lblNewLabel_6, gbc_lblNewLabel_6);
		
		lblRenda = new JLabel("");
		GridBagConstraints gbc_lblRenda = new GridBagConstraints();
		gbc_lblRenda.insets = new Insets(0, 0, 5, 5);
		gbc_lblRenda.gridx = 1;
		gbc_lblRenda.gridy = 4;
		panel_1.add(lblRenda, gbc_lblRenda);
		
		JLabel lblNewLabel_7 = new JLabel("VIP:");
		GridBagConstraints gbc_lblNewLabel_7 = new GridBagConstraints();
		gbc_lblNewLabel_7.insets = new Insets(0, 0, 5, 5);
		gbc_lblNewLabel_7.gridx = 0;
		gbc_lblNewLabel_7.gridy = 5;
		panel_1.add(lblNewLabel_7, gbc_lblNewLabel_7);
		
		lblVIP = new JLabel("");
		GridBagConstraints gbc_lblVIP = new GridBagConstraints();
		gbc_lblVIP.insets = new Insets(0, 0, 5, 5);
		gbc_lblVIP.gridx = 1;
		gbc_lblVIP.gridy = 5;
		panel_1.add(lblVIP, gbc_lblVIP);
		
		JLabel lblNewLabel_8 = new JLabel("Idade:");
		GridBagConstraints gbc_lblNewLabel_8 = new GridBagConstraints();
		gbc_lblNewLabel_8.insets = new Insets(0, 0, 0, 5);
		gbc_lblNewLabel_8.gridx = 0;
		gbc_lblNewLabel_8.gridy = 6;
		panel_1.add(lblNewLabel_8, gbc_lblNewLabel_8);
		
		lblIdade = new JLabel("");
		GridBagConstraints gbc_lblIdade = new GridBagConstraints();
		gbc_lblIdade.insets = new Insets(0, 0, 0, 5);
		gbc_lblIdade.gridx = 1;
		gbc_lblIdade.gridy = 6;
		panel_1.add(lblIdade, gbc_lblIdade);
	}

}
