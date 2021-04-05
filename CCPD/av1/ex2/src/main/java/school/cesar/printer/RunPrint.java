package school.cesar.printer;

import java.util.concurrent.Semaphore;

public class RunPrint implements Runnable {
  private Printer printer;
  Semaphore semaphore;

  public RunPrint(Printer printer, Semaphore semaphore) {
    this.printer = printer;
    this.semaphore = semaphore;
  }
  
  public void run() {
    while (true) {
      try {
        semaphore.acquire();
        this.printer.print();
      } catch (InterruptedException e) {
        e.printStackTrace();
      } finally {
        semaphore.release();
      }
    }
  }
}
