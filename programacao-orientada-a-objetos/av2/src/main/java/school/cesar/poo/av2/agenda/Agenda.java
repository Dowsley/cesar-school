package school.cesar.poo.av2.agenda;

import java.util.List;
import java.util.ArrayList;

/* Classe principal, que chama os componentes MVP
* Model: Guarda o estado da database, e é responsável por carrega-lo ou salva-lo
* View: É composta das duas janelas, ListaFrame e AddFrame
* Controlador: Gerencia ambas os eventos de ambos componentes
*/
public class Agenda {
    public static void main(String[] args) {
    	/* Inicia o MVC */
    	Model m = new Model("data.bin");
    	View v = new View();
    	Controller c = new Controller(m, v);
    }
    
}