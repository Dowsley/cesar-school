package se.chalmers.cse;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.io.IOException;
import java.util.ArrayList;

import javax.imageio.ImageIO;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

class CarWorld extends JPanel {
  private static final long serialVersionUID = 1L;
  Image bridge;
	Image redCar;
	Image blueCar;

	TrafficController controller;

	ArrayList<Car> blueCars = new ArrayList<Car>();
	ArrayList<Car> redCars = new ArrayList<Car>();

	public CarWorld() {
		controller = new TrafficController();

		try {
			redCar = ImageIO.read(CarWorld.class.getResourceAsStream("/se/chalmers/cse/image/redcar.gif"));
			blueCar = ImageIO.read(CarWorld.class.getResourceAsStream("/se/chalmers/cse/image/bluecar.gif"));
			bridge = ImageIO.read(CarWorld.class.getResourceAsStream("/se/chalmers/cse/image/bridge1.gif"));
		} catch (IOException e) {

		}

		redCars.add(new Car(Car.REDCAR,null,redCar,null));
		blueCars.add(new Car(Car.BLUECAR,null,blueCar,null));
		setPreferredSize(new Dimension(bridge.getWidth(null),bridge.getHeight(null)));
	}


	public void paintComponent(Graphics g) {
		g.drawImage(bridge,0,0,this);
		for (Car c : redCars) c.draw(g);
		for (Car c : blueCars) c.draw(g);
	}

	public void addCar(final int cartype) {
		SwingUtilities.invokeLater(new Runnable () {
			public void run() {
				Car c;
				if (cartype==Car.REDCAR) {
					c = new Car(cartype,redCars.get(redCars.size()-1),redCar,controller);
					redCars.add(c);
				} else {
					c = new Car(cartype,blueCars.get(blueCars.size()-1),blueCar,controller);
					blueCars.add(c);
				}
				new Thread(c).start();
			}
		});
	}

}
