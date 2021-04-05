package school.cesar.primos;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
  public static List<Integer> getNumbersInRange(int start, int end) {
    List<Integer> result = new ArrayList<Integer>();
    for (int i = start; i < end; i++) {
        result.add(i);
    }
    return result;
  }

  public static void main(String[] args) {
    List<Integer> primos = new ArrayList<Integer>();

    List<Integer> arr1 = getNumbersInRange(0, 250);
    List<Integer> arr2 = getNumbersInRange(251, 500);
    List<Integer> arr3 = getNumbersInRange(501, 750);
    List<Integer> arr4 = getNumbersInRange(751, 1000);

    Thread t1 = new Thread(new MyRunnable(arr1, primos));
    Thread t2 = new Thread(new MyRunnable(arr2, primos));
    Thread t3 = new Thread(new MyRunnable(arr3, primos));
    Thread t4 = new Thread(new MyRunnable(arr4, primos));
    
    t1.start();
    t2.start();
    t3.start();
    t4.start();

    try {
      t1.join();
      t2.join();
      t3.join();
      t4.join();
    } catch (InterruptedException ex) {
      ex.printStackTrace();
    }

    System.out.println(Arrays.toString(primos.toArray()));
  }
}