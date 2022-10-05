import java.util.Scanner;

public class Main {
  public static boolean carPooling(int trips[][], int cap) {
    int lastDropLocation = -1;
    for (int trip[] : trips) {
      lastDropLocation = Math.max(lastDropLocation, trip[1]);
    }

    int highway[] = new int[lastDropLocation + 1];
    for (int trip[] : trips) {
      highway[trip[0]] += trip[2];
      highway[trip[1]] += -trip[2];
    }

    for (int i = 1 ; i <= lastDropLocation ; i++) {
      highway[i] += highway[i - 1];
      if (highway[i] > cap) {
        return false;
      }
    }

    return true;
  }
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();

    int trips[][] = new int[n][3];
    for (int i = 0 ; i < n ; i++) {
      trips[i][0] = scn.nextInt();
      trips[i][1] = scn.nextInt();
      trips[i][2] = scn.nextInt();
    }
    int cap = scn.nextInt();

    if (carPooling(trips, cap)) {
      System.out.println("YES");
    } else {
      System.out.println("NO");
    }

  }
}                            
                                
