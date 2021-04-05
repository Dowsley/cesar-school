package school.cesar.printer;

public class Printer {
  public void print() {
    System.out.print("-");
    
    try {
      Thread.sleep(50);
    } catch (InterruptedException exn) {}

    System.out.print("|");
  }
}
