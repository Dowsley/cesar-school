package school.cesar.primos;

public class Util {
  public static boolean primo(int n) {
    for (int i=2; i<n; i++) {
      if (n%i == 0) {
        return false;
      }
    }
    return true;
  }
}
