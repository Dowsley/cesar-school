package se.chalmers.cse;

import java.util.ArrayDeque;
import java.util.Queue;

public class TrafficController {
  Queue<Thread> queue;

  public TrafficController() {
    queue = new ArrayDeque<Thread>();
  }
  
  public synchronized void queueAndWait() {
    queue.add(Thread.currentThread());
  
    while (queue.peek() != Thread.currentThread()) {
      try {
        wait();
      } catch (InterruptedException e) {}
    }
  }

  public synchronized void dequeueAndNotify() {
    queue.poll();
    notifyAll();
  }

  public synchronized void enterLeft() {
    queueAndWait();
  }

  public synchronized void enterRight() {
    queueAndWait();
  }

  public synchronized void leaveLeft() {
    dequeueAndNotify();
  }

  public synchronized void leaveRight() {
    dequeueAndNotify();
  }
}
