package school.cesar.ppcd.av1.ex2;

import static school.cesar.ppcd.av1.ex2.Util.nap;

public class FakeLongTask implements Runnable {
	private boolean done = false;
	private static final long ONE_MINUTE = 60 * 1000;

	public void run() {
		nap(ONE_MINUTE);
		done = true;
	}
	public boolean isDone() {
		return done;
	}
}
