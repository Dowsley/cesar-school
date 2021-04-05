package school.cesar.printer;

import java.util.concurrent.Semaphore;

public class Main {
  public static void main(String[] args) {
    final Semaphore semaphore = new Semaphore(1);
    Printer printer = new Printer();
    
    for (int i = 0; i<4; i++) {
      new Thread(new RunPrint(printer, semaphore)).start();
    }
  }
}