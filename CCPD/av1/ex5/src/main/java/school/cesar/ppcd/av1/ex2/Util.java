package school.cesar.ppcd.av1.ex2;

public class Util {
	public static void nap(long millis) {
		try {
			Thread.currentThread().sleep(millis);
		} catch (InterruptedException e) {
		}
	}
}
