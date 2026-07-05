// Solve 2026-06-21

import java.util.*;

class LC_1833 {

    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int iceCream = 0;

        for (int cost : costs) {
            if (cost > coins) {
                break;
            }

            coins -= cost;
            iceCream++;
        }

        return iceCream;
    }

}
