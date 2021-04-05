package school.cesar.ppcd.av1.ex2;

public class Main {
	public static void main(String[] args) {
		FakeLongTask fakeLongTask = new FakeLongTask();
		Thread threadFakeLongTask = new Thread(fakeLongTask);
		threadFakeLongTask.start();
		while (!fakeLongTask.isDone()) {
			System.out.println("waiting...");
		}
		System.out.println("done!");
	}
}
