package school.cesar.primos;

import java.util.List;

public class MyRunnable implements Runnable {
  private List<Integer> inputArr;
  private List<Integer> outputArr;
  
  public MyRunnable(List<Integer> input, List<Integer> output) {
    inputArr = input;
    outputArr = output;
  }

  public void run() {
    for (Integer i : inputArr) {
      if (Util.primo(i)) {
        outputArr.add(i);
      }
    }
  }
}