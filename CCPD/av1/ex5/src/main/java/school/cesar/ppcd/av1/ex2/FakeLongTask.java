package school.cesar.ppcd.av1.ex2;

import static school.cesar.ppcd.av1.ex2.Util.nap;

public class FakeLongTask implements Runnable {
	private static final long ONE_MINUTE = 60 * 1000;

	public void run() {
		nap(ONE_MINUTE);
		notify();
	}
}
