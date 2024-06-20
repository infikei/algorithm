// Solve 2024-06-20

// 리트코드에 제출할 때는 class 이름을 Solution으로 설정해야 한다.

import java.util.*;

class LeetCode_1552_test {

    public static int maxDistance(int[] position, int m) {
        Arrays.sort(position);

        int low = 1;
        int high = 1000000000;

        while (low + 1 < high) {
            int mid = (low + high) / 2;
            int cnt = 0;
            int pos = -1000000000;

            while (true) {
                int idx = lowerBound(position, pos + mid);

                if (idx >= position.length) {
                    break;
                }

                pos = position[idx];
                cnt++;
            }

            if (cnt >= m) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }

    static int lowerBound(int[] arr, int val) {
        int low = -1;
        int high = arr.length;

        while (low + 1 < high) {
            int mid = (low + high) / 2;

            if (arr[mid] >= val) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return high;
    }

    public static void main(String[] args) {
        System.out.println(maxDistance(new int[] { 1, 2, 3, 4, 7 }, 3));
        System.out.println(maxDistance(new int[] { 5, 4, 3, 2, 1, 1000000000 }, 2));
    }

}
