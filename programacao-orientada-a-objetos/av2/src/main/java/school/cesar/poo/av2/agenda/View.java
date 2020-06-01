package school.cesar.poo.av2.agenda;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class View {
	private ListaFrame gui;
	private AddFrame popup;

	public ListaFrame getGui() {
		return gui;
	}

	public void setGui(ListaFrame gui) {
		this.gui = gui;
	}

	public AddFrame getPopup() {
		return popup;
	}

	public void setPopup(AddFrame popup) {
		this.popup = popup;
	}
}